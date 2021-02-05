//https://programmers.co.kr/learn/courses/30/lessons/68935

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    
    while(n)
    {
        v.push_back(n % 3); //앞뒤반전모양으로 벡터에 저장됨
        n /= 3;
    }
    
    reverse(v.begin(), v.end()); //10진법 계산 편의성을 위해 뒤집기
    
    for(int i = 0; i < v.size(); i++)
        answer += pow(3, i) * v[i]; 
    
    return answer;
}