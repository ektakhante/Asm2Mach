```
Asm2Mach    /
├── bin/                          # Directory for the compiled output (machine code)
│   └── Asm2Mach.out         # Final machine code output file (example)
├── data/                         # Directory for input data (assembly files)
│   └── test.asm                  # Example assembly code file
├── include/                      # Directory for header files
│   ├── functionHeader.h          # Function declarations
│   ├── queue.h                   # Queue-related data structures (if applicable)
│   ├── utils.h                   # Utility functions like error handling, parsing
│   └── variablesHeader.h         # Declarations for variables and global constants
├── Makefile                      # Makefile to automate build and compile process
├── obj/                          # Object files generated during compilation
├── README.md                     # Documentation for the project (detailed description, setup instructions)
└── src/                          # Source code directory
    └── main.c                    # Main program logic (entry point)
```

### **Explanation of Directories and Files:**
- **bin/**: Stores the final compiled output, which is the machine code that the assembler produces.
- **data/**: Holds your input assembly files (`test.asm` is the example). This is where the user will place assembly code for the assembler to process.
- **include/**: Contains header files that declare functions, constants, and data structures used throughout the project.
- **Makefile**: Defines the rules for compiling the project and automating the build process (compiling source files, linking them, etc.).
- **obj/**: Temporary folder where object files (.o) are stored during the compilation process before creating the final executable.
- **README.md**: Contains the detailed project description, setup instructions, and any other relevant information about the project.
- **src/**: Contains the source code files. The `main.c` file serves as the entry point and contains the main logic of the assembler.
