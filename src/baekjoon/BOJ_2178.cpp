#include <stdio.h>
#include <queue>
using namespace std;

int map[101][101]; // 미로 저장할 배열
bool visited[101][101]; // 미로 방문여부 체크할 배열
int cnt[101][101]; // 지난 칸 수를 누적하여 저장할 배열

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우 순으로 탐색

int n,m; // m X n 크기의 미로

// x:행, y:열
void bfs(int x,int y){
  // 방문 표시후 칸 수 더해서 누적
  visited[x][y]=true;
  cnt[x][y]++;
  
  //bfs 운행을 위한 큐 생성
  queue<pair<int,int>> q;
  q.push({x,y});

   // 큐에 값이 아직 있다는것은 아직 방문하지 않은 노드가 있다는 뜻이므로 큐 빌때까지 반복
  while(!q.empty()){
    int qx=q.front().first;
    int qy=q.front().second;
    q.pop();

    //큐에서 제거한 후에, 그 제거한 노드와 인접한 노드들을 상하좌우로 탐색.
    for(int i=0;i<4;i++){
      int nx=qx+dir[i][0];
      int ny=qy+dir[i][1];

      // 그렇게 인접한 노드의 범위가 유효하고, 인접한 노드중에 아직 방문하지 않았고 1로 표시되어 이동가능한 경우 큐에 삽입
      if(nx>=0 && nx<n &&ny>=0 && ny<m && !visited[nx][ny] && map[nx][ny]==1){
        visited[nx][ny]=true;
        cnt[nx][ny]=cnt[qx][qy]+1;
        q.push({nx,ny});
      }
    }

  }
}

int main(){
    // 입력구간
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        // 연속된 숫자를 하나씩 숫자로 받기 -> 꼭 "%1d"로, 또는 string으로 받아서 파싱하기!!
        scanf("%1d",&map[i][j]);
      }
    }
    
    bfs(0,0);

    // (0,0)부터 입력받았으므로 (n-1,m-1)까지의 누적값 출력 
    printf("%d",cnt[n-1][m-1]);
    
    return 0;
}
