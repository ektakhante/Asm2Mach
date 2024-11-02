#include <stdio.h>
#include <stdint.h>
#include "instruction.h"

// Function to encode the instruction into machine code
void encodeInstruction(const Instruction *instruction, uint8_t opcode) {
    // For demonstration, we'll just print the opcode and the instruction details
    // A more complex implementation would create a byte array for machine code
    printf("Encoding Instruction: %s ", instruction->mnemonic);
    
    // Print operands if they exist
    for (int i = 0; i < instruction->operandCount; i++) {
        printf("%s", instruction->operands[i]);
        if (i < instruction->operandCount - 1) {
            printf(", ");
        }
    }
    
    // Print the opcode
    printf(" | Opcode: 0x%02X\n", opcode);

    // Here, you would typically store the encoded instruction into a buffer
    // or write it directly to an output file.
}

// Function to print the encoded instruction for debugging purposes
void printEncodedInstruction(const Instruction *instruction) {
    printf("Instruction: %s | Operands: ", instruction->mnemonic);
    for (int i = 0; i < instruction->operandCount; i++) {
        printf("%s", instruction->operands[i]);
        if (i < instruction->operandCount - 1) {
            printf(", ");
        }
    }
    printf("\n");
}
