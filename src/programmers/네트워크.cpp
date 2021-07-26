//https://programmers.co.kr/learn/courses/30/lessons/43162

#include <vector> 
using namespace std; 

int check[200]; 

void dfs(int current_computer, int n, vector< vector<int> > computers) { 
  // current_computer번째 컴퓨터를 체크했다고 표시하기
  check[current_computer] = 1;

  for(int i=0; i<n; i++) { 
    // current_computer와 연결된 컴퓨터들 탐색시작. 
    if(check[i] == 0 && computers[current_computer][i] == 1) {   
      // 다른 컴퓨터와 연결되어 있고, 그 컴퓨터가 아직 탐색하지 않은 컴퓨터라면 탐색 시작
      dfs(i, n, computers); 
    } 
  } 
} 

int solution(int n, vector< vector<int> > computers) { 
  int answer = 0;

  for(int i=0; i<n; i++) { 
    // 아직 검사하지 않은 컴퓨터일때 탐색 시작
    if(check[i] == 0) { 
      dfs(i, n, computers);
      
      // 재귀적으로 호출한 dfs함수가 여기로 돌아올때가 연결된 그래프 하나이므로 answer+1을 해준다.
      answer++; 
    } 
  } 

  return answer;
}