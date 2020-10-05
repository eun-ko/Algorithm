#include <stdio.h>

void hanoi_tower(int n, int from, int aux, int to)
{
  if (n == 1)
    printf("%d %d\n", from, to);
  else
  {
    hanoi_tower(n - 1, from, to, aux);
    printf("%d %d\n", from, to);
    hanoi_tower(n - 1, aux, from, to);
  }
}
int main()
{
  int n;
  int count = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    count *= 2;
  printf("%d\n", count - 1);
  hanoi_tower(n, 1, 2, 3);
}