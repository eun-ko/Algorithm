//https://programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int min = 0, max = people.size()-1;
    sort(people.begin(), people.end()); // 오름차순으로 정렬 
    while(min <= max){
        if(people[min] + people[max] <= limit){ 
            min++; 
            max--;
        }else{ 
            max--;
        }
        answer++;
    }
    return answer;
}