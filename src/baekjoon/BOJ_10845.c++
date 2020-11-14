#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 10001

typedef struct
{
  int count = 0;
  int queue[MAX_QUEUE_SIZE];
  int front = 0;
  int rear = 0;
} Queue;

int empty(Queue *q)
{
  return (q->count == 0) ? 1 : 0;
}

int size(Queue *q)
{
  return q->count;
}

void push(Queue *q, int item)
{
  if ((q->rear) == MAX_QUEUE_SIZE)
    return;
  q->queue[q->rear++] = item;
  q->count++;
}

int pop(Queue *q)
{
  if (empty(q))
    return -1;
  q->count--;
  return q->queue[q->front++];
}

int front(Queue *q)
{
  if (empty(q))
    return -1;
  return q->queue[q->front];
}

int back(Queue *q)
{
  if (empty(q))
    return -1;
  return q->queue[q->rear - 1];
}

int main()
{
  Queue q;
  int n = 0;
  int push_num = 0;
  char command[10];
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%s", command);

    if (!strcmp("push", command))
    {
      scanf("%d", &push_num);
      push(&q, push_num);
    }
    else if (!strcmp("pop", command))
      printf("%d\n", pop(&q));
    else if (!strcmp("size", command))
      printf("%d\n", size(&q));
    else if (!strcmp("empty", command))
      printf("%d\n", empty(&q));
    else if (!strcmp("front", command))
      printf("%d\n", front(&q));
    else if (!strcmp("back", command))
      printf("%d\n", back(&q));
  }
  return 0;
}