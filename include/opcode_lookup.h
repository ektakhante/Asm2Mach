#ifndef OPCODE_LOOKUP_H
#define OPCODE_LOOKUP_H

#include <stdint.h>

// Define a structure to hold an opcode entry
typedef struct {
    char mnemonic[10];      // Mnemonic for the instruction (e.g., "MOV", "ADD")
    uint8_t opcode;         // Corresponding machine code opcode
} OpcodeEntry;

// Function to initialize the opcode lookup table
void initializeOpcodeTable(void);

// Function to look up the opcode for a given mnemonic
// Returns the opcode if found, or 0xFF if the mnemonic is invalid.
uint8_t lookupOpcode(const char *mnemonic);

#endif // OPCODE_LOOKUP_H
