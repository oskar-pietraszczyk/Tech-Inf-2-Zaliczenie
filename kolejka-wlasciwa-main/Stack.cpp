#define QUEUE_SIZE 5
int queue_table[QUEUE_SIZE] = { 0 };
int front = 0;
int rear = 0;
int count = 0;

int isQueueEmpty(void)
{
    return (count == 0) ? 1 : 0;
}

int isQueueFull(void)
{
    return (count == QUEUE_SIZE) ? 1 : 0;
}

int Dequeue(void)
{
    if (!isQueueEmpty())
    {
        int val = queue_table[front];
        front = (front + 1) % QUEUE_SIZE;
        count--;
        return val;
    }

    return queue_table[front]; // lub jakiś kod błędu
}

int Front(void)
{
    if (!isQueueEmpty())
    {
        return queue_table[front];
    }

    return queue_table[front]; // lub jakiś kod błędu
}

void Enqueue(int val)
{
    if (!isQueueFull())
    {
        queue_table[rear] = val;
        rear = (rear + 1) % QUEUE_SIZE;
        count++;
    }
}
