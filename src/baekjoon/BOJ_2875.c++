#include <stdio.h>

int main()
{
  int n, m, k;
  scanf_s("%d %d %d", &n, &m, &k);
  int answer = 1;
  while (1)
  {
    int contest_n = 2 * answer;
    int contest_m = answer;
    if (3 * answer > n + m - k || 2 * answer > n || answer > m)
      break;
    answer++;
  }
  printf("%d", answer - 1);
}