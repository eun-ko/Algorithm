//https://programmers.co.kr/learn/courses/30/lessons/42840

#include <string>
#include <vector>

using namespace std;

int tester1[5] = {1, 2, 3, 4, 5};
int tester2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int tester3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

int max(int a, int b)
{
  return a < b ? b : a;
}

vector<int> solution(vector<int> answers)
{
  vector<int> answer;
  vector<int> score(3);
  int max_score = 0;
  for (int i = 0; i < answers.size(); i++)
  {
    if (tester1[i % 5] == answers[i])
      score[0]++;
    if (tester2[i % 8] == answers[i])
      score[1]++;
    if (tester3[i % 10] == answers[i])
      score[2]++;
  }
  max_score = max(max(score[0], score[1]), score[2]);
  //3개 max비교
  for (int i = 0; i < 3; i++)
  {
    if (score[i] == max_score)
      answer.push_back(i + 1);
  }
  return answer;
}