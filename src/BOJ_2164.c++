#include <stdio.h>
#include <queue>
//카드2
using namespace std;
int main()
{
  int n;
  scanf_s("%d", &n);
  queue<int> q;
  for (int i = 0; i < n; i++)
  {
    q.push(i + 1);
  }
  while (n != 1)
  {
    q.pop();
    q.push(q.front());
    q.pop();
    n--;
  }
  printf("%d", q.front());
}