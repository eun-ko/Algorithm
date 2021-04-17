//https://programmers.co.kr/learn/courses/30/lessons/60057

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int i,j; //i : 비교 단위, j: 비교 위치
    for (i = 1; i <= s.size()/2; i++) { //비교 단위는 한단어에서 문자열길이/2 만큼까지 가능 (완전탐색)
      string tmp = "";
      for ( j = 0; j < s.size(); j+=i) { //비교위치는 비교단위만큼 더해가면서 확인

        if(j+2*i <= s.size()){ // 비교가능할때  (비교단위의 최소 2배가 되는지 확인)

          if(s.substr(j,i)!=s.substr(j+i,i)) {
            //같은값이 반복 안될때
            tmp += s.substr(j,i);
            continue;
          }
          
          else{
            // 같은값이 반복 되는 경우
            tmp += s.substr(j,i);
            int cnt = 1; //반복횟수 count

            while(j+2*i <= s.size() && s.substr(j,i)==s.substr(j+i,i)){
              cnt++;
              j+=i;
            }
            tmp += to_string(cnt);
          } 
        } 
        else{ // 비교불가능할 때
          tmp += s.substr(j); // 남은 문자열을 tmp에 붙여 for문 탈출
          break;
        }
      }

    // 더 짧은 압축열을 찾으면 길이 정답에 업데이트
    if(answer > tmp.size()) answer = tmp.size(); 
  }
  
  return answer;
}