#include <stdio.h>

int main()
{
  char num[100001];
  int sum = 0;
  int num_index[10] = {
      0,
  }; //입력된 수에 각 숫자가 몇개 들어있는지 배열의 인덱스를 통해 표현
  scanf_s("%s", num);
  for (int i = 0; num[i]; i++)
  {
    int s_to_i = num[i] - '0';
    sum += s_to_i;
    num_index[s_to_i]++;
  }
  if (sum % 3 != 0 || num_index[0] == 0) //30의 배수가 아닌경우
    printf("%d", -1);
  else
  {
    for (int i = 9; i >= 0; i--) //내림차순 출력
    {
      while (num_index[i]) //같은 숫자 들어있을경우도 있기때문에 if가 아니라 while
      {
        printf("%d", i);
        num_index[i]--;
      }
    }
  }
}