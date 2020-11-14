#include <stdio.h>
#include <string.h>

const int MAX_STACK_SIZE = 100;

typedef struct
{
  int stack[MAX_STACK_SIZE];
  int top = -1;
} Stack;

void push(Stack *s, int item)
{
  s->stack[++(s->top)] = item;
}
int is_empty(Stack *s)
{
  return (s->top == -1) ? 1 : 0;
}
int top(Stack *s)
{
  return s->stack[s->top];
}
int peek(Stack *s)
{
  if (is_empty(s))
  {
    printf("스택 비어있음");
  }
  else
    return s->stack[s->top];
}
int pop(Stack *s)
{
  if (is_empty(s))
  {
    printf("스택 비어있음");
  }
  else
    return s->stack[(s->top)--];
}

int calculate_priority(char c)
{
  switch (c)
  {
  case '+':
  case '-':
  {
    return 1;
    break;
  }
  case '*':
  case '/':
  {
    return 2;
    break;
  }
  case '(':
  {
    return 0;
    break;
  }
  }
}

void to_postfix(char exp[])
{
  int i = 0;
  char ch, till_left_parenthesis;
  int len = strlen(exp);
  Stack s;

  for (i = 0; i < len; i++)
  {
    ch = exp[i];
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
      while (!is_empty(&s) && (calculate_priority(ch) <= calculate_priority(peek(&s))))
        printf("%c", pop(&s));
      //in stack priority가 더 크면 스택에 있는 문자 출력
      push(&s, ch);
      break;
    case '(':
      push(&s, ch);
      //왼쪽 괄호 일단 push
      break;
    case ')':
      till_left_parenthesis = pop(&s);
      while (till_left_parenthesis != '(')
      {
        printf("%c", till_left_parenthesis);
        till_left_parenthesis = pop(&s);
      }
      break;
    default:
      printf("%c", ch);
      break;
    }
  }
  while (!is_empty(&s))
    printf("%c", pop(&s));
}

int main()
{
  char exp[100];
  scanf_s("%s", exp);
  to_postfix(exp);
}