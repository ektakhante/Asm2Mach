#include <stdio.h>
#include "parser.h"

void testParseLine() {
    Instruction instruction;
    const char *line = "MOV AL, 5";

    if (parseLine(line, &instruction) == 0) {
        printf("Parsed Instruction: %s, Operands: ", instruction.mnemonic);
        for (int i = 0; i < instruction.operandCount; i++) {
            printf("%s ", instruction.operands[i]);
        }
        printf("\n");
    } else {
        printf("Failed to parse line: %s\n", line);
    }
}

int main() {
    testParseLine();
    return 0;
}
