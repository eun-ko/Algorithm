#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 10000

typedef struct
{
  int stack[MAX_STACK_SIZE];
  int top = -1;
} StackType;

int empty(StackType *s)
{
  return (s->top == -1) ? 1 : 0;
}
int top(StackType *s)
{
  if (empty(s))
    return -1;
  return s->stack[s->top];
}
int size(StackType *s)
{
  return s->top + 1;
  //계속(s->top)++이거때문에..왜 틀리나했더니 s->top값 자체가 바뀌고있었ㄷㅏ
}
void push(StackType *s, int item)
{
  s->stack[++(s->top)] = item;
}
int pop(StackType *s)
{
  if (empty(s))
  {
    return -1;
  }
  else
    return s->stack[(s->top)--];
}
int main()
{
  StackType stack;
  int i, n = 0;
  int push_num = 0;
  char command[10];

  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%s", command);
    if (!strcmp(command, "push"))
    {
      scanf("%d", &push_num);
      push(&stack, push_num);
    }
    else if (!strcmp(command, "pop"))
      printf("%d\n", pop(&stack));
    else if (!strcmp(command, "top"))
      printf("%d\n", top(&stack));
    else if (!strcmp(command, "size"))
      printf("%d\n", size(&stack));
    else if (!strcmp(command, "empty"))
      printf("%d\n", empty(&stack));
  }
  return 0;
}