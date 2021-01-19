#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, answer;
int lab[8][8]; //연구소

//상,하,좌,우 표시
const int y[] = {-1, +1, 0, 0};
const int x[] = {0, 0, -1, +1};

/*  행(n)-y 열(m)-x  */

void find_safe_space()
{
  queue<int> q;
  int temp[8][8]; //바이러스 확산시키전 상태 저장할 배열
  int visited[8][8] = {
      0,
  }; //bfs 방문 표시할 배열

  for (int y = 0; y < n; y++)
  {
    for (int x = 0; x < m; x++)
    {
      temp[8][8] = lab[8][8];
      if (temp[y][x] == 2) //바이러스가 있을때
      {
        q.push(y * 10 + x); //바이러스 위치를 q에 넣기
        /* 10으로 나눈 값이 y축, 나머지가 x축 위치로 표시 */
        visited[y][x] = 1;
      }
    }
  }

  while (!q.empty())
  {
    int current = q.front();
    q.pop();

    int current_y = current / 10;
    int current_x = current % 10; //현재 바이러스의 x,y 위치

    temp[current_y][current_x] = 2;

    for (int i = 0; i < 4; i++)
    { //상하좌우 탐색
      int next_y = current_y + y[i];
      int next_x = current_x + x[i];

      if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m)
        continue; //연구소 바깥 인덱스인 경우

      if (visited[next_y][next_x] == 0 && temp[next_y][next_x] == 0)
      {
        visited[next_y][next_x] = 1;
        q.push(next_y * 10 + next_x);
      }
    }
  }

  int safe_space_cnt = 0;
  for (int y = 0; y < n; y++)
  {
    for (int x = 0; x < m; x++)
    {
      if (temp[y][x] == 0)
        safe_space_cnt++;
    }
  }

  answer = max(answer, safe_space_cnt);
}

void make_wall(int wall_cnt, int y, int x)
{
  if (wall_cnt == 3)
  {
    //바이러스 확산 시켜서 안전영역 찾기
    find_safe_space();
    return;
  }

  for (int i = y; i < n; i++)
  {
    for (int j = x; j < m; j++)
    {
      if (lab[i][j] == 0)
      {
        lab[i][j] == 1;
        make_wall(wall_cnt + 1, i, j);
        lab[i][j] = 0; //백트래킹
      }
    }
    x = 0;
  }
}

int main()
{
  scanf("%d %d", &n, &m);

  for (int y = 0; y < n; y++)
  {
    for (int x = 0; x < m; x++)
    {
      scanf("%d", &lab[y][x]);
    }
  }

  make_wall(0, 0, 0);

  printf("%d", answer);
}