#include <stdio.h>
//STL stack 사용없이
int main(void)
{
  int num = 0;
  scanf("%d", &num);
  for (int i = 0; i < num; i++)
  {
    int top = 0;
    char exp[51] = {0};
    scanf("%s", exp);
    for (int j = 0; exp[j] != NULL; j++)
    {
      (exp[j] == '(') ? ++top : top--;
      if (top < 0)
        break;
      //닫는괄호쌍이 맞는데 닫는괄호가 하나더 나왔을 경우 break (열린괄호는 나왔어도 추가 검사 효용 O)
    }
    (top == 0) ? printf("YES\n") : printf("NO\n");
  }
}