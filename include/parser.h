#ifndef PARSER_H
#define PARSER_H

#include "instruction.h"

// Function to parse a line of assembly code
// Returns 0 on success, or a non-zero error code on failure.
int parseLine(const char *line, Instruction *instruction);

// Function to handle comments in the assembly code
// It removes comments from the line and returns the cleaned line.
void removeComments(char *line);

// Function to tokenize the parsed line into mnemonic and operands
// This function splits the line into mnemonic and operands, populating the Instruction structure.
void tokenizeInstruction(const char *line, Instruction *instruction);

#endif // PARSER_H
