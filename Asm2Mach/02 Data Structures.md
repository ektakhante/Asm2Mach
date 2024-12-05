### 1. **Queue**
   - **What it does**: A queue is like a line where items (instructions or data) wait their turn to be processed. The first item to enter is the first to be processed.
   - **Why it's used**: It helps keep the instructions in order as they are processed one by one.

### 2. **Symbol Table (Hash Table)**
   - **What it does**: A symbol table is like a dictionary that maps labels (like `LOOP`) to memory addresses. Whenever the assembler encounters a label in the code, it checks the symbol table to figure out where it should jump or refer to.
   - **Why it's used**: It makes it easy to quickly look up and resolve labels to their memory locations.

### 3. **Arrays**
   - **What it does**: An array is a list of items stored in a specific order. You can access each item by its position (index).
   - **Why it's used**: It stores things like opcodes (machine code) or data in a fixed order, making it quick to access when needed.

### 4. **Linked List**
   - **What it does**: A linked list is a chain of items, where each item knows where the next one is. This allows easy addition or removal of items without shifting everything around.
   - **Why it's used**: It’s useful for handling a list of instructions or data that may grow or shrink as the program runs.

### 5. **Hash Map (for Opcode Table)**
   - **What it does**: A hash map is like a super-fast lookup table that links instructions (like `MOV`, `ADD`) to their machine code equivalents.
   - **Why it's used**: It helps quickly convert human-readable assembly instructions into machine code during the assembling process.

### 6. **Data Segment Management (Array or Struct)**
   - **What it does**: This manages the part of memory where variables and constants (like numbers or text) are stored in the program.
   - **Why it's used**: It helps keep track of where the program’s data is located and how to access it.

---

### Simple Summary of Data Structures:
- **Queue**: For processing instructions in order.
- **Symbol Table (Hash Table)**: For looking up labels and their memory addresses.
- **Arrays**: For storing things like opcodes and data in order.
- **Linked List**: For handling instructions or data that may change in size.
- **Hash Map**: For converting assembly instructions to machine code.
- **Data Segment Management**: For keeping track of data used by the program.