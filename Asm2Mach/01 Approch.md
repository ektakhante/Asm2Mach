### **Asm2Mach Project Workflow**

The workflow of your **Assembler Simulator** project follows a series of steps to take assembly code and convert it into machine code (or opcode). Below is an outline of how the project works:

---

### **1. Input Assembly Code**  
- **Step 1.1**: The user provides an assembly code file (e.g., `test.asm`) stored in the `data` directory.
  - The assembly code contains instructions in human-readable format like `MOV`, `ADD`, labels, and data declarations.

---

### **2. Preprocessing (Reading and Tokenizing)**
- **Step 2.1**: The assembler reads the provided assembly code.
  - The program first checks the `test.asm` file and processes each line.
  - Comments, whitespace, and unnecessary characters are removed (preprocessing).
  
- **Step 2.2**: The code is tokenized into meaningful parts (keywords, labels, operands, instructions).
  - Instructions are split into their basic parts (e.g., `MOV`, `AX`, `BX`).
  - Labels are identified (e.g., `LOOP:`) to be resolved later.

---

### **3. Label Resolution (Using Symbol Table)**
- **Step 3.1**: As the assembler processes the instructions, it builds a **Symbol Table**.
  - **Symbol Table** stores the locations of labels, where each label points to a memory address in the code.
  - Example: `LOOP: 0x100` means the label `LOOP` will be replaced by memory address `0x100`.

- **Step 3.2**: The assembler scans the code again to resolve labels.
  - For any instruction that references a label, it looks up the symbol table to get the correct memory address and replaces the label with the address.

---

### **4. Opcode Generation (Using Opcode Table)**
- **Step 4.1**: The assembler translates human-readable instructions into machine-readable opcodes.
  - **Opcode Table** (Hash Map or Array) is used to map assembly instructions like `MOV`, `ADD`, `JMP` to their respective opcodes (e.g., `0x89`, `0x01`, `0xE9`).
  
- **Step 4.2**: For each instruction, the assembler looks up the opcode in the **Opcode Table** and replaces the instruction with its corresponding opcode.
  - Example: `MOV AX, BX` might be replaced with `0x89, 0xD8`.

---

### **5. Data Segmentation and Processing (Data Section Management)**
- **Step 5.1**: The assembler processes any data declarations in the assembly code (e.g., `.data` section).
  - The **Data Segment** is populated with variables or constants declared in the assembly code.
  - This includes storing values like integers, strings, or labels.

- **Step 5.2**: The program keeps track of the data using either **Arrays** or **Structs** to store data values and manage memory.
  - It ensures that the data section is properly assigned memory addresses.

---

### **6. Final Machine Code Output (Binary/Opcode)**
- **Step 6.1**: After processing all instructions, the assembler writes the final machine code (binary or opcodes) into a file (e.g., `asm_simulator.out` in the `bin` folder).
  - The output contains a sequence of opcodes that can be executed on the target architecture (like 8086 or other microprocessors).

- **Step 6.2**: The output file is ready for execution or further processing.

---

### **7. Debugging and Error Handling**
- **Step 7.1**: During the entire process, the assembler checks for errors in the assembly code, such as:
  - Undefined labels
  - Incorrect opcode usage
  - Misformatted instructions
  
- **Step 7.2**: Errors are displayed to the user, guiding them to fix the issues in the input assembly code.

---

### **8. Optional Enhancements**
- **Step 8.1**: The assembler could include features like:
  - **Optimization**: Removing unnecessary instructions or using shorter opcodes.
  - **Multi-pass assembling**: First pass to collect labels and second pass to generate opcodes.
  - **Cross-referencing**: To validate instruction correctness against available opcodes.

---

### **Diagram of the Workflow:**
```
Assembly Code (test.asm)
        |
        v
   Preprocessing (Tokenizing & Cleaning)
        |
        v
   Label Resolution (Symbol Table)
        |
        v
   Opcode Generation (Opcode Table)
        |
        v
   Data Segmentation (Data Section Management)
        |
        v
   Final Machine Code (Output to bin/asm_simulator)
        |
        v
   Error Handling (If needed)
```

---

### **Project Workflow Summary:**
1. **Input**: Assembly code is provided.
2. **Preprocessing**: Code is cleaned and tokenized.
3. **Label Resolution**: Labels are mapped to memory locations via the symbol table.
4. **Opcode Generation**: Assembly instructions are translated to opcodes using the opcode table.
5. **Data Processing**: Data declarations are handled and stored.
6. **Output**: Final machine code is generated.
7. **Error Handling**: Ensures the program runs smoothly and reports issues if any.
