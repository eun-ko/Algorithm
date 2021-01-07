#include <stdio.h>

int answer[10] = {
    1,
    2,
    4,
};
int count_add_case(int n)
{
  for (int i = 3; i <= n; i++)
  {
    answer[i] = answer[i - 1] + answer[i - 2] + answer[i - 3];
  }

  if (n == 1)
    return answer[0];
  else if (n == 2)
    return answer[1];
  else if (n == 3)
    return answer[2];
  else
  {
    return answer[n - 1];
  }
}

int main()
{
  int t, n;
  scanf_s("%d", &t);
  for (int i = 0; i < t; i++)
  {
    scanf_s("%d", &n);
    printf("%d\n", count_add_case(n));
  }
}