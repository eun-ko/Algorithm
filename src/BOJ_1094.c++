#include <stdio.h>

int main()
{
  int stick = 64; //초기값
  int x = 0;
  int cnt = 0;
  scanf_s("%d", &x);
  while (x > 0)
  {
    if (stick > x)
      stick /= 2; //절반으로 잘라서 버리기
    else
    {
      cnt++;
      x -= stick;
    }
  }
  printf("%d", cnt);
}