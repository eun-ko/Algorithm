#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
  int n = 0;
  int loop = 0;
  scanf("%d %d", &n, &loop);
  queue<int> q;
  //환형 큐 개념
  for (int i = 0; i < n; i++)
  {
    q.push(i + 1);
  }
  printf("<");
  while (!q.empty())
  {
    for (int j = 0; j < loop - 1; j++)
    {
      q.push(q.front());
      q.pop();
      //stl queue front,back은 peek역할이라 pop해줘야함
    }
    printf("%d", q.front());
    q.pop(); //kill
    if (!q.empty())
      printf(", "); //마지막엔 콤마출력x
  }
  printf(">");
}