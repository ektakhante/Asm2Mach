#define MAX_INSTRUCTION_LEN 100
#define MAX_QUEUE_SIZE 100
#define MAX_LABELS 50
#define MAX_DATA_SIZE 100

// Structure for queue
typedef struct
{
    char instructions[MAX_QUEUE_SIZE][MAX_INSTRUCTION_LEN];
    int front;
    int rear;
} InstructionQueue;

// Structure for symbol table (labels and addresses)
typedef struct
{
    char label[20];
    int address;
} SymbolTableEntry;

SymbolTableEntry symbolTable[MAX_LABELS];
int symbolTableSize = 0;

// Structure for storing data (byte and word storage)
unsigned char dataSegment[MAX_DATA_SIZE];
int dataSegmentSize = 0;

// Opcodes lookup table (extend this as needed)
typedef struct
{
    char mnemonic[10];
    char opcode[5];
} OpcodeTable;

OpcodeTable opcodeTable[] = {
    {"MOV", "89"},
    {"ADD", "01"},
    {"SUB", "29"},
    {"MUL", "F7"},
    {"DIV", "F7"},
    {"PUSH", "50"},
    {"POP", "58"},
    {"HLT", "F4"},
    {"JMP", "E9"},
};

int opcodeTableSize = sizeof(opcodeTable) / sizeof(OpcodeTable);
