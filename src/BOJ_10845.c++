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

int is_empty(Queue *q)
{
  return (q->count == 0) ? 1 : 0;
}
void push(Queue *q, int item)
{
  q->rear = (q->rear + 1) & MAX_QUEUE_SIZE;
  q->queue[q->rear] = item;
  q->count++;
}
int size(Queue *q)
{
  return q->count;
}
int front(Queue *q)
{
  if (is_empty(q))
    return -1;
  return q->queue[q->front];
}
int rear(Queue *q)
{
  if (is_empty(q))
    return -1;
  return q->queue[q->rear];
}
int pop(Queue *q)
{
  if (is_empty(q))
    return -1;
  else
  {
    q->front = (q->front + 1) * MAX_QUEUE_SIZE;
    q->count--;
    return q->queue[q->front];
  }
}
int main()
{
  Queue q;
  int n = 0;
  int push_num = 0;
  char command[10];
  scanf_s("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf_s("%s", command);
    if (!strcmp(command, "push"))
    {
      scanf_s("%d", &push_num);
      push(&q, push_num);
    }
    else
    {
      if (!strcmp(command, "pop"))
        printf("%d\n", pop(&q));
      if (!strcmp(command, "size"))
        printf("%d\n", size(&q));
      if (!strcmp(command, "empty"))
        printf("%d\n", is_empty(&q));
      if (!strcmp(command, "front"))
        printf("%d\n", front(&q));
      if (!strcmp(command, "back"))
        printf("%d\n", rear(&q));
    }
  }
}