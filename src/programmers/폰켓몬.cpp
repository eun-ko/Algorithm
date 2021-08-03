//https://programmers.co.kr/learn/courses/30/lessons/1845

#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> us;
    
    for(int i = 0; i < nums.size(); i++){
        us.insert(nums[i]);
    }
    
    answer=min(us.size(),nums.size()/2);
    
    return answer;
}