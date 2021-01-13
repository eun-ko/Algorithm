//https://programmers.co.kr/learn/courses/30/lessons/42586

#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
  vector<int> answer;
  queue<int> remain_days;

  for (int i = 0; i < progresses.size(); i++)
  {
    progresses[i] = 100 - progresses[i];
    if (progresses[i] % speeds[i] == 0)
      remain_days.push(progresses[i] / speeds[i]);
    else
      remain_days.push(progresses[i] / speeds[i] + 1);
  }

  while (!remain_days.empty())
  {
    int current = remain_days.front();
    remain_days.pop();
    int cnt = 1;                                                   //pop했으니 1부터
    while (current >= remain_days.front() && !remain_days.empty()) // !remain_days.empty() 해주기!!
    {
      remain_days.pop();
      cnt++;
    }
    answer.push_back(cnt);
  }
  return answer;
}