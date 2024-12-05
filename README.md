# Assembler Simulator

## Project Overview
The **Assembler Simulator** is a tool designed to simulate the process of converting assembly language code into machine-readable instructions. It is intended to help users understand the basic processes involved in assembling a program, including opcode decoding, label resolution, and data segment management. The simulator can read assembly files, process instructions, resolve labels, and generate machine code outputs in a simulated environment.

## Key Features
- **Assembly Code Parsing**: Reads and processes assembly code files (`.asm`) and identifies opcodes, labels, and data directives.
- **Opcode Decoding**: Converts assembly instructions into machine-readable opcodes, simulating the transformation process that would occur in an actual assembler.
- **Label Resolution**: Resolves and replaces labels with memory addresses, ensuring that jumps and references are correctly mapped during assembly.
- **Data Segment Management**: Handles data segment directives (e.g., `.data`) and manages memory allocation for data variables.
- **Queue Management**: Uses a queue to organize and manage the instructions during processing.
- **Symbol Table**: Keeps track of variable names, labels, and their corresponding memory addresses.

## How it Works
The Assembler Simulator operates in the following way:

1. **Input**: The simulator takes a source assembly file (`.asm`) as input. This file can contain assembly instructions with labels and data definitions.
2. **Parsing**: The assembly file is parsed line by line. Each instruction or directive is processed, and the necessary operations are performed, such as converting opcodes, resolving labels, and managing data segments.
3. **Opcode Decoding**: Each assembly instruction is matched to its corresponding opcode. This involves converting mnemonics like `MOV`, `ADD`, `SUB`, etc., into their binary or hexadecimal representation.
4. **Label Resolution**: Labels are replaced with their corresponding memory addresses. This ensures that jumps and calls in the assembly code point to the correct location in the simulated memory.
5. **Output**: After processing, the simulator generates a machine-readable output, which may include a list of opcodes or a memory dump.

## Project Structure

The project follows a modular and organized structure for better scalability and maintenance:

```
.
├── bin/                        # Final compiled executable
├── data/                       # Sample test files
│   └── test.asm                # Example assembly file
├── include/                    # Header files
│   ├── functionHeader.h        # Function declarations
│   ├── queue.h                 # Queue data structure
│   ├── utils.h                 # Utility functions
│   └── variablesHeader.h       # Global variable declarations
├── Makefile                    # Build script for compiling the project
├── obj/                        # Compiled object files
├── README.md                   # Project documentation
└── src/                        # Source code files
    └── main.c                  # Main program entry point
```

### Detailed Explanation of Key Files:

- **`src/main.c`**: The entry point for the program. It initializes the simulator, reads input files, and calls the relevant functions to simulate the assembler process.
- **`src/queue.c`**: Contains functions for managing the queue data structure used to hold and process instructions.
- **`src/labels.c`**: Handles the resolution of labels by storing the address of each label and ensuring that instructions referencing these labels are updated correctly.
- **`src/opcode.c`**: Includes the logic for decoding assembly instructions into opcodes (machine instructions).
- **`src/utils.c`**: Provides various utility functions used across different modules, such as string manipulation, error handling, etc.
- **`include/*.h`**: Header files containing declarations for functions, constants, and data structures used in the project.

## Building the Project

To build the project, follow these steps:

1. Clone the repository:
   ```
   git clone https://github.com/ShingareOm/Asm2Mach.git
   ```

2. Navigate to the project directory:
   ```
   cd Asm2Mach
   ```

3. Run the `make` command to compile the program:
   ```
   make
   ```

4. Run the `make run` command to execute the program:
   ```
   make run
   ```

5. After the build completes successfully, you can run the assembler simulator:
   ```
   ./bin/asm_simulator <your_assembly_file.asm>
   ```

## Requirements
- **gcc**: The C compiler used for building the project.
- **make**: A tool to automate the build process.

## License

This project is licensed under the MIT [License](LICENSE).