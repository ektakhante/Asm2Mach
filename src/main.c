#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/functionHeader.h"
#include "../include/utils.h"

int main()
{
    FILE *asmFile;
    char filename[100];
    InstructionQueue queue;

    initQueue(&queue);

    // Get ASM file name
    printf("Enter the ASM file name: ");
    scanf("%s", filename);

    // Open the file
    asmFile = fopen(filename, "r");
    if (asmFile == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Process labels and enqueue instructions
    processLabels(asmFile, &queue);

    // Process data directives
    processDataDirectives(asmFile);

    fclose(asmFile);

    // Display the current queue after processing labels
    printf("\nCurrent Queue after processing labels:\n");
    displayQueue(&queue);

    // Display data segment
    displayDataSegment();

    // Process each instruction in the queue
    printf("\nProcessing Instructions:\n");
    while (!isQueueEmpty(&queue))
    {
        char *instruction = dequeue(&queue);
        printf("\nInstruction: %s\n", instruction);
        convertInstructionToOpcode(instruction);
    }

    return 0;
}
