#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int map[26][26]; // 지도 정보 input 받아서 저장할 배열
bool visited[26][26]; // 방문했는지 확인할 배열

vector<int> v; // 단지 정보를 저장할 벡터

int n; // 지도의 크기
int house_cnt = 0;  

int dir[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} }; // 상하좌우 순서로 이동

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
    // 다음으로 이동할 x,y 좌표 설정
    int nx = x + dir[i][0];
		int ny = y + dir[i][1];

    // 유효한 범위일때 이동 시작
		if (nx >= 0 && ny >= 0 && nx <= n && ny <= n) {
      // 방문하지 않은 단지이고, 지도상에서 집이 있는 곳일때 탐색 시작
			if (visited[nx][ny] == false && map[nx][ny] == 1) {
        visited[nx][ny] = true;
				house_cnt++;
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	scanf("%d",&n);
	
  for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]); 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false && map[i][j] == 1) {
				visited[i][j] = true;
				house_cnt++;
        dfs(i, j);
				// 탐색이 종료되어서 여기로 오게되면 그때까지 house_cnt에 저장한 집의 개수를 v벡터에 삽입
        v.push_back(house_cnt);

        // 집개수 0개로 초기화한 후 다시 다음 for문으로 들어가서 탐색시작
				house_cnt = 0;
			}
		}
	}
	// v의 size가 단지 개수
  printf("%d\n",v.size());
	
  // 오름차순으로 출력해야하므로 정렬
  sort(v.begin(), v.end());
	
  for (int i = 0; i < v.size(); i++) {
    printf("%d\n",v[i]);
	}
}