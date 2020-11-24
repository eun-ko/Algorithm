//https://programmers.co.kr/learn/courses/30/lessons/49993

#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
  int answer = 0;
  for (int i = 0; i < skill_trees.size(); i++)
  {
    vector<char> skill_in_skill_trees; //loop 돌때마다 초기화
    for (int j = 0; j < skill_trees[i].size(); j++)
    {
      for (int k = 0; k < skill.size(); k++)
      {
        if (skill[k] == skill_trees[i][j])
        {
          char tmp = skill[k];
          skill_in_skill_trees.push_back(tmp);
        }
      }
    }
    bool check = true;
    for (int l = 0; l < skill_in_skill_trees.size(); l++)
    {
      if (skill[l] != skill_in_skill_trees[l])
        check = false; //순서 확인
    }
    if (check)
      answer++;
  }

  return answer;
}