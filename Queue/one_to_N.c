#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enqueue(char ch[], char **queueu, int *front, int *rear, int size)
{
    if ((*front + size - 1) % size == *rear)
    {
        printf("Queue is already full\n");
        return;
    }
    if (*front == -1 && *rear == -1)
    {
        *front = *rear = 0;
    }
    queueu[*rear] = ch;
    *rear = (*rear + 1) % size;
}

void print_queue(char **queue, int front, int rear, int size)
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int index = front;
    while (index != rear)
    {
        printf("%s ", queue[index]);
        index = (index + 1) % size;
    }
    printf("\n");
}

char *dequeue(char **queue, int *front, int *rear, int size)
{
    if (*front == -1)
    {
        printf("Queue is empty\n");
        return NULL;
    }

    char *value = queue[*front];
    queue[*front] = NULL;

    if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else
    {
        *front = (*front + 1) % size;
    }

    return value;
}

void generate_binary_numbers(int count)
{
    char *queue[10] = {malloc(2)};
    int front = 0, rear = 1;
    strcpy(queue[0], "1");

    for (int i = 0; i < count; i++)
    {
        char *value = dequeue(queue, &front, &rear, 10);
        printf("%s ", value);

        char *zero = malloc(strlen(value) + 2);
        char *one = malloc(strlen(value) + 2);
        sprintf(zero, "%s0", value);
        sprintf(one, "%s1", value);

        enqueue(zero, queue, &front, &rear, 10);
        enqueue(one, queue, &front, &rear, 10);
        free(value);
    }
    printf("\n");
}

int main()
{
    generate_binary_numbers(10);

    return 0;
}