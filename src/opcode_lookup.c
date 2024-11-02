#include <stdio.h>
#include <string.h>
#include "opcode_lookup.h"

// Define the maximum number of opcode entries
#define MAX_OPCODES 256

// Global array to hold the opcode table
static OpcodeEntry opcodeTable[MAX_OPCODES];

// Function to initialize the opcode lookup table
void initializeOpcodeTable(void) {
    // Example opcodes (you can expand this as needed)
    strcpy(opcodeTable[0].mnemonic, "MOV");
    opcodeTable[0].opcode = 0xB8; // Example opcode for MOV

    strcpy(opcodeTable[1].mnemonic, "ADD");
    opcodeTable[1].opcode = 0x04; // Example opcode for ADD

    strcpy(opcodeTable[2].mnemonic, "SUB");
    opcodeTable[2].opcode = 0x05; // Example opcode for SUB

    // Continue adding more mnemonics and their opcodes as needed
}

// Function to look up the opcode for a given mnemonic
uint8_t lookupOpcode(const char *mnemonic) {
    for (int i = 0; i < MAX_OPCODES; i++) {
        if (strcmp(opcodeTable[i].mnemonic, mnemonic) == 0) {
            return opcodeTable[i].opcode;
        }
        // Assuming empty mnemonics are the end of the list
        if (opcodeTable[i].mnemonic[0] == '\0') {
            break;
        }
    }
    return 0xFF; // Return 0xFF if the mnemonic is not found
}
