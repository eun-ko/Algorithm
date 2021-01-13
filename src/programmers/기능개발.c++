//https://programmers.co.kr/learn/courses/30/lessons/42586

#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
  vector<int> answer;
  stack<int> s;
  queue<int> remain_days;

  for (int i = 0; i < progresses.size(); i++)
  {
    progresses[i] = 100 - progresses[i];
    !progresses[i] % speeds[i] ? remain_days.push(progresses[i] / speeds[i]) : remain_days.push(progresses[i] / speeds[i] + 1);
  }

  while (!remain_days.empty())
  {
    if (s.empty())
    {
      s.push(remain_days.front());
      remain_days.pop();
    }
    else
    {
      if (s.top() < remain_days.front())
      {
        int cnt = 0;
        while (!s.empty())
        {
          s.pop();
          cnt++;
        }
        if (cnt != 0)
          answer.push_back(cnt); //pop한 개수를 answer에 push
        s.push(remain_days.front());
        remain_days.pop();
      }
      else
      {
        s.push(remain_days.front());
        remain_days.pop();
      }
    }
  }
  int pops = 0;
  while (!s.empty())
  {
    s.pop();
    ++pops;
  }
  answer.push_back(pops);
  return answer;
}