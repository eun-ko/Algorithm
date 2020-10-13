#include <stdio.h>
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
      int x, y;
      scanf("%d %d", &x, &y);
    }
    printf("%d\n", n - 1);
    //BFS X, 연결그래프니까 모든 도시여행가능. 무조건 n-1이 최소
  }
}