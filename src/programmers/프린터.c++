
//https://programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location)
{
  int answer = 0;
  //우선 순위 저장할 pq
  priority_queue<int> pq;
  //문서 인덱스와 중요도 저장
  queue<pair<int, int>> q;

  //큐 초기화
  for (int i = 0; i < priorities.size(); i++)
  {
    pq.push(priorities[i]);
    q.push({i, priorities[i]});
  }

  while (!q.empty())
  {
    int current_index = q.front().first;
    int current_priority = q.front().second;
    q.pop();

    if (pq.top() == current_priority) //가장 높은 우선순위와 같을때
    {
      pq.pop();
      answer++; //출력 시작
      if (current_index == location)
        break; //종료
    }
    else
    {
      q.push({current_index, current_priority}); //대기열에 넣기
    }
  }

  return answer;
}