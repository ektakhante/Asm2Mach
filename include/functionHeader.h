#include "variablesHeader.h"

void initQueue(InstructionQueue *queue);
int isQueueEmpty(InstructionQueue *queue);
int isQueueFull(InstructionQueue *queue);
void enqueue(InstructionQueue *queue, const char *instruction);
char *dequeue(InstructionQueue *queue);
char *fetchOpcode(const char *mnemonic);
void convertInstructionToOpcode(const char *instruction);
void processLabels(FILE *asmFile, InstructionQueue *queue);
void processDataDirectives(FILE *asmFile);
int resolveLabel(const char *label);
void displayQueue(InstructionQueue *queue);
void displayDataSegment();
void removeComments(char *line);