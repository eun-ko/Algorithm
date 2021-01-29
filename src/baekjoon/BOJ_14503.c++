#include <stdio.h>
#include <queue>
using namespace std;

typedef struct robot
{
  int y, x, dir;
} robot;

int n, m;
int map[50][50];
robot r;

//북 동 남 서
const int dy[] = {-1, 0, +1, 0};
const int dx[] = {0, +1, 0, -1};

int main()
{
  scanf("%d %d", &n, &m);
  scanf("%d %d %d", &r.y, &r.x, &r.dir);
  for (int y = 0; y < n; y++)
  {
    for (int x = 0; x < m; x++)
    {
      scanf("%d", &map[y][x]);
    }
  }

  queue<robot> q;
  q.push(r);

  int answer = 0;

  while (!q.empty())
  {
    robot current = q.front();
    q.pop();
    if (map[current.y][current.x] == 0)
    {
      map[current.y][current.x] = 2;
      answer++; //청소가능할 때 청소
    }

    //로봇 시뮬레이션
    for (int i = 0; i < 4; i++)
    {
      robot next;
      next.dir = (current.dir + 3 + (i * 3)) % 4; //왼쪽 회전을 위해 세칸을 더함
      next.y = current.y + dy[next.dir];
      next.x = current.x + dx[next.dir];

      if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] != 0)
      {
        //다음에 갈 곳이 지도 밖인 경우 + 청소할 필요가 없다면
        continue; //회전만 하기
      }
      q.push(next);
      break; //로봇은 큐에 하나만 존재
    }

    //네 방향을 돌아도 갈 곳이 없을 때
    if (q.empty())
    {
      robot next;
      next.dir = current.dir; //후진은 방향이 바뀌지 않음
      next.y = current.y + dy[(next.dir + 2) % 4];
      next.x = current.x + dx[(next.dir + 2) % 4]; // +2 == 180도 회전 (반대방향)
      if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] == 1)
      {
        //다음에 갈 곳이 지도 밖인 경우 + 벽면일 경우
        break; //종료
      }
      q.push(next);
    }
  }

  printf("%d", answer);
}
