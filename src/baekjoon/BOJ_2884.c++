#include <stdio.h>
int main()
{
  int h, m;
  scanf_s("%d %d", &h, &m);
  m -= 45;
  if (m < 0)
  {
    m += 60;
    h--;
  }
  if (h < 0)
    h = 23;
  printf("%d %d", h, m);
}