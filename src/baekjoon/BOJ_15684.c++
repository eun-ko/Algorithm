#include <stdio.h>
#include <algorithm>
using namespace std;

bool visited[11][31];
int answer;
int n, m, h;

bool ladder_game()
{
  for (int i = 1; i <= n; i++)
  {
    int current_index = i; //세로선
    for (int j = 1; j <= h; j++)
    {
      if (visited[current_index][j] == true) //세로선의 오른쪽
        current_index += 1;
      else if (visited[current_index - 1][j] == true) //세로선의 왼쪽
        current_index -= 1;
    }
    if (current_index != i)
      return false; //i번 세로가 i번 세로로 가지 않을때
  }
  return true;
}

void select_line(int index, int cnt)
{
  if (cnt > 3)
    return;
  if (ladder_game())
  {
    answer = min(answer, cnt); //갱신
    return;
  }
  for (int i = index; i <= h; i++)
  {
    for (int j = 1; j < n; j++)
    { //가로가 연속하거나 접하면 안됨
      if (!visited[j][i] && !visited[j - 1][i] && !visited[j + 1][i])
      {
        visited[j][i] = true;
        select_line(i, cnt + 1);
        visited[j][i] = false;
      }
    }
  }
}

int main()
{
  answer = 5;
  scanf_s("%d %d %d", &n, &m, &h);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf_s("%d %d", &a, &b);
    visited[b][a] = true;
  }
  select_line(1, 0);
  printf("%d", answer == 5 ? -1 : answer);
}