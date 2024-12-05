# Asm2mach Project

This is an assembler that reads assembly code and converts it into machine code for a theoretical processor. The project supports instruction processing, symbol table management, and data segment handling. It features:

- **Label Resolution**: Supports jump and branch instructions with labels.
- **Opcode Conversion**: Converts assembly mnemonics into opcodes.
- **Data Directives**: Processes data directives like DB, DW, RESB, and RESW.

## Usage

1. Compile the project with `make`.
2. then use `make run` to execute the binary
3. there you go

```bash
./assembler input.asm
```
