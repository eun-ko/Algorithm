#include <stdio.h>

int main()
{
  int e, s, m;
  scanf_s("%d %d %d", &e, &s, &m);
  int year = 1;
  while (true)
  {
    if ((year - e) % 15 == 0 && (year - s) % 28 == 0 && (year - m) % 19 == 0)
    {
      printf("%d", year);
      break;
    }
    year++;
  }
}