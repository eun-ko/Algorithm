//https://programmers.co.kr/learn/courses/30/lessons/68644

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers)
{
  vector<int> answer;
  int temp_sum = 0;
  for (int i = 0; i < numbers.size(); i++)
  {
    for (int j = i + 1; j < numbers.size(); j++)
    {
      temp_sum = numbers[i] + numbers[j];
      if (find(answer.begin(), answer.end(), temp_sum) == answer.end()) //answer벡터에 없으면 추가
        answer.push_back(temp_sum);
    }
  }
  sort(answer.begin(), answer.end()); //오름차순
  return answer;
}