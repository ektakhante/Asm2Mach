#include <stdio.h>
#include "instruction.h"

void testEncodeInstruction() {
    Instruction instruction = {"ADD", {"AL", "BL"}, 2};
    uint8_t opcode = 0x04; // Example opcode for ADD

    printf("Encoding Instruction...\n");
    encodeInstruction(&instruction, opcode);
    printEncodedInstruction(&instruction);
}

int main() {
    testEncodeInstruction();
    return 0;
}
