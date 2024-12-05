
// Initialize the queue
void initQueue(InstructionQueue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

// Check if the queue is empty
int isQueueEmpty(InstructionQueue *queue)
{
    return queue->front == queue->rear;
}

// Check if the queue is full
int isQueueFull(InstructionQueue *queue)
{
    return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

// Add instruction to the queue
void enqueue(InstructionQueue *queue, const char *instruction)
{
    if (isQueueFull(queue))
    {
        printf("Queue is full. Cannot enqueue: %s\n", instruction);
        return;
    }
    strcpy(queue->instructions[queue->rear], instruction);
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
}

// Remove instruction from the queue
char *dequeue(InstructionQueue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }
    char *instruction = queue->instructions[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return instruction;
}
