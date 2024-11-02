#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"
#include "utils.h"

// Function to parse a line of assembly code
int parseLine(const char *line, Instruction *instruction) {
    char cleanedLine[256];
    strcpy(cleanedLine, line);

    // Remove comments from the line
    removeComments(cleanedLine);

    // Tokenize the cleaned line into mnemonic and operands
    tokenizeInstruction(cleanedLine, instruction);

    // Basic validation of the instruction
    if (instruction->operandCount < 1) {
        return -1; // Error: No operands found
    }
    return 0; // Success
}

// Function to handle comments in the assembly code
void removeComments(char *line) {
    char *commentStart = strstr(line, ";");
    if (commentStart) {
        *commentStart = '\0'; // Terminate the string at the comment
    }
    trimWhitespace(line); // Clean up any trailing whitespace
}

// Function to tokenize the parsed line into mnemonic and operands
void tokenizeInstruction(const char *line, Instruction *instruction) {
    char tempLine[256];
    strcpy(tempLine, line);

    // Tokenize the line using space as the delimiter
    char *token = strtok(tempLine, " ");
    if (token) {
        strncpy(instruction->mnemonic, token, sizeof(instruction->mnemonic));
        instruction->mnemonic[sizeof(instruction->mnemonic) - 1] = '\0'; // Null-terminate
    }

    // Parse operands
    instruction->operandCount = 0;
    token = strtok(NULL, ","); // Use comma as a delimiter for operands
    while (token && instruction->operandCount < 3) {
        trimWhitespace(token); // Clean up operand
        strncpy(instruction->operands[instruction->operandCount++], token, sizeof(instruction->operands[0]));
        instruction->operands[instruction->operandCount - 1][sizeof(instruction->operands[0]) - 1] = '\0'; // Null-terminate
        token = strtok(NULL, ",");
    }
}
