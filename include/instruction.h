#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>

// Define a structure to represent an assembly instruction
typedef struct {
    char mnemonic[10];      // Mnemonic for the instruction (e.g., "MOV", "ADD")
    char operands[3][20];   // Array to hold operands (up to 3)
    int operandCount;       // Number of operands
} Instruction;

// Function to encode the instruction into machine code
void encodeInstruction(const Instruction *instruction, uint8_t opcode);

// Function to print the encoded instruction for debugging purposes
void printEncodedInstruction(const Instruction *instruction);

#endif // INSTRUCTION_H
