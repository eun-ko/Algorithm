//https://programmers.co.kr/learn/courses/30/lessons/42884

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector< vector<int> > routes) {
    int answer = 0;
    int prev_enter_point = 30001; //최대값으로 초기화
    
    sort(routes.rbegin(), routes.rend()); //내림차순 정렬
    
    for(int i = 0; i < routes.size(); i++){
        if(prev_enter_point > routes[i][1]){ //진출지점이 prev_enter_poin값보다 작다면 두 차량의 경로가 겹치지 않았으므로
            answer++; //감시 카메라 하나 추가
            prev_enter_point = routes[i][0]; //진입지점을 prev_enter_poin에 넣어서 갱신
        }
    }
    return answer;
}