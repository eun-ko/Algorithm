// https://programmers.co.kr/learn/courses/30/lessons/43164

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int visit[10001];
 
bool dfs(string cur, vector<vector<string>> tickets, vector<string> &answer,  int used_ticket_cnt)
{
    answer.push_back(cur);

    if (used_ticket_cnt == tickets.size()) {
      // 주어진 항공권을 모두 이용하였다면 dfs함수 종료
      return true;
    }
    
    for(int i = 0 ; i < tickets.size(); i++)    
    { 
      // 현재 탐색중인 cur공항이 출발지가 되는 항공권이 있고, 그 항공권이 아직 사용되지 않았다면 사용되었다고 표시한 후에 dfs 계속 이어나가기
        if (tickets[i][0] == cur && visit[i] == 0)
        {
            visit[i] = 1;
           
            if (dfs(tickets[i][1], tickets, answer, used_ticket_cnt + 1)){
              return true;
            }
            // dfs가 False를 반환하였다면 길이 없는것이므로 사용표시를 해제한 후에 다시 다음 for문으로 넘어가서 다른 공항을 찾는다.
            visit[i] = 0;
        }
    }
    // for문을 도는동안 경로가 될 수 있는게 없었다면 넣었던 공항을 제거하고 false 반환
    answer.pop_back();
    return false;
}
 
vector<string> solution(vector<vector<string>> tickets) 
{
    vector<string> answer;
  
    sort(tickets.begin(), tickets.end());
    
    //출발지인 ICN 부터 사용된 티켓수는 0개로 탐색 시작
    dfs("ICN", tickets, answer, 0);
    
    return answer;
}


