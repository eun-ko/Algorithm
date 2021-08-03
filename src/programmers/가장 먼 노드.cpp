// https://programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[20001]; 
int dist[20001]; // dist[i] : i 노드까지 가는데 거친 간선의 개수
// distance로 선언시 using namespace std 때문에 reference ambiguous 에러 발생
vector<int> graph[20001]; // 연결정보 저장할 인접리스트
queue<int> q; // bfs 운행할 큐
int max_dist=0;

void bfs(int x){

    visited[x]=true;
    q.push(x);
    dist[x]=0; // 1번 노드까지의 거친 간선의 개수는 0
    
    while(!q.empty()){
        
        int x=q.front();
        q.pop();
        // printf("pop!! : %d\n",x);
        
        for(int i=0;i<graph[x].size();i++){
          // 큐의 맨 앞에 있던 x와 연결된 노드들 탐색
            int connected_with_x=graph[x][i];

            if(visited[connected_with_x]==false){
                
                visited[connected_with_x]=true;
                dist[connected_with_x]=dist[x]+1;
                
                q.push(connected_with_x);
                // printf("push!! : %d\n",graph[x][i]);

                if(dist[connected_with_x]>max_dist){
                    max_dist=dist[connected_with_x]; // 필요시 최대값 갱신
                }
                
            }
        }
        
        
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0;i<edge.size();i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
        // 양방향 연결
    }
    
    bfs(1);
    
    for(int i=0;i<n;i++){
      // 가장 멀리 떨어진 노드가 몇 개인지 체크
        if(dist[i]==max_dist){
            answer++;
        }
    }
    
    return answer;
}