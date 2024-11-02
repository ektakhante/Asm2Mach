#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/parser.h"
#include "./include/opcode_lookup.h"
#include "./include/instruction.h"
#include "./include/error_handling.h"

#define MAX_LINE_LENGTH 256

void displayUsage(const char *progName) {
    printf("Usage: %s <assembly_file.asm>\n", progName);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        displayUsage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *assemblyFile = argv[1];
    FILE *file = fopen(assemblyFile, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", assemblyFile);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = 0;

        // Skip empty lines
        if (strlen(line) == 0) continue;

        // Parse the line into an instruction
        Instruction instruction;
        if (parseLine(line, &instruction) != 0) {
            handleError("Failed to parse line", line);
            continue; // Skip to next line on error
        }

        // Lookup the opcode for the instruction
        unsigned char opcode = lookupOpcode(instruction.mnemonic);
        if (opcode == 0xFF) { // 0xFF could indicate an invalid opcode
            handleError("Invalid mnemonic", instruction.mnemonic);
            continue;
        }

        // Encode the instruction (this function should be implemented in instruction.c)
        encodeInstruction(&instruction, opcode);

        // Output the encoded instruction (for demonstration purposes)
        printEncodedInstruction(&instruction);
    }

    fclose(file);
    return EXIT_SUCCESS;
}
