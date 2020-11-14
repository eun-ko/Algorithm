#include <stdio.h>
#include <string.h>
int main()
{
  char parenthesis_input[100001];
  int stack_size = 0, result = 0;
  scanf("%s", parenthesis_input);
  int len = strlen(parenthesis_input);
  for (int i = 0; i < len; i++)
    if (parenthesis_input[i] == '(') //열린괄호
      stack_size++;                  //push (stack size가 현재 겹쳐져있는 막대기 개수)
    else                             //닫힌괄호
    {
      stack_size--;                        //pop (스택이용하는경우 조건문 밖에서 pop하면 top값이 달라주니까 안됨)
      if (parenthesis_input[i - 1] == '(') //laser
        result += stack_size;
      else
        result++;
    }
  printf("%d", result);
  return 0;
}