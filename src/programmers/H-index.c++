//https://programmers.co.kr/learn/courses/30/lessons/42747#

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    //6 5 3 1 0
    sort(citations.rbegin(),citations.rend());
    for(int i=0;i<citations.size();i++){
        if(citations[i]>=(i+1)) answer++;
    }
    return answer;
}