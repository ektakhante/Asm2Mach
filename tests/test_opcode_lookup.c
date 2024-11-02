#include <stdio.h>
#include "opcode_lookup.h"

void testLookupOpcode() {
    initializeOpcodeTable();
    const char *mnemonic = "MOV";
    uint8_t opcode = lookupOpcode(mnemonic);
    
    if (opcode != 0xFF) {
        printf("Opcode for %s: 0x%02X\n", mnemonic, opcode);
    } else {
        printf("Opcode not found for mnemonic: %s\n", mnemonic);
    }
}

int main() {
    testLookupOpcode();
    return 0;
}
