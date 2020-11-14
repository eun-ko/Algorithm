//https://programmers.co.kr/learn/courses/30/lessons/42748

#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
  vector<int> answer;
  for (int i = 0; i < commands.size(); i++)
  {
    vector<int> sorted_array;
    for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
    { //-1 해주기 주의!
      sorted_array.push_back(array[j]);
    }
    sort(sorted_array.begin(), sorted_array.end());
    answer.push_back(sorted_array[commands[i][2] - 1]);
  }
  return answer;
}