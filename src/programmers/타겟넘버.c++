//https://programmers.co.kr/learn/courses/30/lessons/43165

#include <vector>
using namespace std;

// 전역변수 answer
int answer = 0;

// index : numbers벡터의 인덱스
void get_target_number(vector<int> numbers, int target, int sum, int index){
    //종료 조건
    if (index == numbers.size()){
        if (sum == target) {
            answer++;
        }
        // 같지 않을때도 return
        return;
    }
    // 종료 조건이 만족되지않으면 계속 탐색
    get_target_number(numbers, target, sum + numbers[index], index + 1);
    get_target_number(numbers, target, sum - numbers[index], index + 1);
}

// numbers=[a,b,c,d,e]가 있으면 a부터 시작해서 다음원소에 각각 +,-해보며 dfs로 sum합산

int solution(vector<int> numbers, int target)
{
  get_target_number(numbers, target, 0, 0);
  return answer;
}