//https://programmers.co.kr/learn/courses/30/lessons/43165

#include <vector>
using namespace std;

int answer = 0;

void get_target_number(vector<int> numbers, int target, int sum, int index)
{
  if (index == numbers.size())
  {
    if (sum == target)
    {
      answer++;
    }
    return;
  }
  get_target_number(numbers, target, sum + numbers[index], index + 1);
  get_target_number(numbers, target, sum - numbers[index], index + 1);
}

//numbers=[a,b,c,d,e]가 있으면 a부터 시작해서 다음원소에 각각 +,-해보며 dfs로 sum합산

int solution(vector<int> numbers, int target)
{
  get_target_number(numbers, target, 0, 0);
  return answer;
}