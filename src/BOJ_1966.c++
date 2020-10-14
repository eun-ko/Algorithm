#include <stdio.h>
#include <queue>
#include <utility> //pair
using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  int n, pos, imp;
  while (t--)
  {
    queue<pair<int, int>> q; //Queue-문서인덱스,중요도 저장
    priority_queue<int> pq;  //Priority Q-중요도 저장
    int result = 0;          // 큐,result는 for안에서 초기화!!!
    scanf("%d %d", &n, &pos);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &imp);
      q.push({i, imp});
      pq.push(imp);
    }
    while (!q.empty())
    {
      int current_index = q.front().first;
      int current_imp = q.front().second;
      q.pop();                     //pop먼저
      if (pq.top() == current_imp) //중요도 제일 높은 문서랑 같으면
      {
        pq.pop();
        result++;
        if (current_index == pos) //관심있는 문서에 해당하면
        {
          printf("%d\n", result);
          break;
        }
      }
      else
      {
        q.push({current_index, current_imp}); //뒤에 추가
      }
    }
  }
}