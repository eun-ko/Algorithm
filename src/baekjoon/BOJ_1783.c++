#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
  int n = 0;
  int m = 0;
  scanf_s("%d %d", &n, &m);
  if (n == 1)
    printf("%d", 1);
  else if (n == 2)
    printf("%d", min(4, (m + 1) / 2));
  else
  {
    if (m <= 6)
      printf("%d", min(4, m));
    else
      printf("%d", m - 2);
  }
}