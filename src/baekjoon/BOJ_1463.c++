#include <stdio.h>
#include <algorithm>
using namespace std;

int op_count[1000001];

int main()
{
  int n;
  scanf_s("%d", &n);
  for (int i = 2; i <= n; i++)
  {
    op_count[i] = op_count[i - 1] + 1; //우선 성립
    if (i % 2 == 0)
      op_count[i] = min(op_count[i / 2] + 1, op_count[i]); //갱신
    if (i % 3 == 0)
      op_count[i] = min(op_count[i / 3] + 1, op_count[i]); //갱신
  }
  printf("%d", op_count[n]);
}