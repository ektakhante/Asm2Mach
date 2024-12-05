#include "queue.h"

char *fetchOpcode(const char *mnemonic)
{
    for (int i = 0; i < opcodeTableSize; i++)
    {
        if (strcmp(opcodeTable[i].mnemonic, mnemonic) == 0)
        {
            return opcodeTable[i].opcode;
        }
    }
    return NULL;
}

// Resolve the label to its address
int resolveLabel(const char *label)
{
    for (int i = 0; i < symbolTableSize; i++)
    {
        if (strcmp(symbolTable[i].label, label) == 0)
        {
            return symbolTable[i].address;
        }
    }
    return -1; // Label not found
}

// Convert an instruction to opcode
void convertInstructionToOpcode(const char *instruction)
{
    char mnemonic[10], operand1[10], operand2[10];
    int numOperands = sscanf(instruction, "%s %[^,], %s", mnemonic, operand1, operand2);

    // Fetch opcode for the mnemonic
    char *opcode = fetchOpcode(mnemonic);
    if (opcode == NULL)
    {
        printf("Error: Unknown mnemonic '%s'\n", mnemonic);
        return;
    }

    // Resolve the label if it's a jump instruction
    if (strcmp(mnemonic, "JMP") == 0)
    {
        int labelAddress = resolveLabel(operand1);
        if (labelAddress == -1)
        {
            printf("Error: Undefined label '%s'\n", operand1);
            return;
        }
        printf("Opcode: %s | Operand1 (resolved): %d\n", opcode, labelAddress);
    }
    else
    {
        printf("Opcode: %s ", opcode);
        if (numOperands >= 2)
        {
            printf("| Operand1: %s", operand1);
        }
        if (numOperands == 3)
        {
            printf(" | Operand2: %s", operand2);
        }
        printf("\n");
    }
}

// Process the labels and instructions
void processLabels(FILE *asmFile, InstructionQueue *queue)
{
    char buffer[MAX_INSTRUCTION_LEN];
    int address = 0;

    // Read instructions from the ASM file and process labels
    while (fgets(buffer, MAX_INSTRUCTION_LEN, asmFile))
    {
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Remove comments from the line
        removeComments(buffer);

        // If the line is empty after removing comments, skip it
        if (strlen(buffer) == 0)
        {
            continue;
        }

        // Check for labels (e.g., LOOP:)
        if (strchr(buffer, ':'))
        {
            char label[20];
            sscanf(buffer, "%s", label);
            label[strlen(label) - 1] = 0; // Remove the colon
            symbolTable[symbolTableSize].address = address;
            strcpy(symbolTable[symbolTableSize].label, label);
            symbolTableSize++;
            printf("Label found: %s at address %d\n", label, address);
        }
        else
        {
            // Enqueue instruction
            enqueue(queue, buffer);
        }

        address++;
    }
}

// Process data directives (DB, DW, RESB, RESW)
void processDataDirectives(FILE *asmFile)
{
    char buffer[MAX_INSTRUCTION_LEN];

    // Reset data segment size
    dataSegmentSize = 0;

    while (fgets(buffer, MAX_INSTRUCTION_LEN, asmFile))
    {
        // Remove newline character
        buffer[strcspn(buffer, "\n")] = 0;

        // Remove comments from the line
        removeComments(buffer);

        // If the line is empty after removing comments, skip it
        if (strlen(buffer) == 0)
        {
            continue;
        }

        // Check for data directives
        if (strstr(buffer, "DB") != NULL)
        {
            unsigned char value;
            char *token = strtok(buffer + 2, ",");
            while (token != NULL)
            {
                sscanf(token, "0x%hhx", &value);
                dataSegment[dataSegmentSize++] = value;
                token = strtok(NULL, ",");
            }
        }
        else if (strstr(buffer, "DW") != NULL)
        {
            unsigned short value;
            char *token = strtok(buffer + 2, ",");
            while (token != NULL)
            {
                sscanf(token, "%hx", &value);
                dataSegment[dataSegmentSize++] = (unsigned char)(value & 0xFF);
                dataSegment[dataSegmentSize++] = (unsigned char)((value >> 8) & 0xFF);
                token = strtok(NULL, ",");
            }
        }
        else if (strstr(buffer, "RESB") != NULL)
        {
            int bytesToReserve;
            sscanf(buffer + 4, "%d", &bytesToReserve);
            dataSegmentSize += bytesToReserve;
        }
        else if (strstr(buffer, "RESW") != NULL)
        {
            int wordsToReserve;
            sscanf(buffer + 4, "%d", &wordsToReserve);
            dataSegmentSize += wordsToReserve * 2; // Each word is 2 bytes
        }
    }
}

// Remove comments from a line
void removeComments(char *line)
{
    char *commentStart = strchr(line, ';');
    if (commentStart != NULL)
    {
        *commentStart = '\0'; // Remove the comment part of the line
    }
}

// Display the instruction queue
void displayQueue(InstructionQueue *queue)
{
    printf("Instruction Queue:\n");
    for (int i = queue->front; i < queue->rear; i++)
    {
        printf("%s\n", queue->instructions[i % MAX_QUEUE_SIZE]);
    }
}

// Display the data segment
void displayDataSegment()
{
    printf("\nData Segment:\n");
    for (int i = 0; i < dataSegmentSize; i++)
    {
        printf("0x%02X ", dataSegment[i]);
    }
    printf("\n");
}