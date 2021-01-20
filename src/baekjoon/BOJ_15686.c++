#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, type, answer;
vector<Position> house, chicken_shop, selected_chicken_shop;
struct Position
{
  int y, x;
};

void dfs(int pos) //남겨질 수 있는 치킨집들의 모든 경우의수를 찾는다
{
  if (selected_chicken_shop.size() == m) //m개의 치킨집 선택
  {
    int total = 0;
    for (int i = 0; i < house.size(); i++)
    {
      int min_dist = 1000000;
      for (int j = 0; j < selected_chicken_shop.size(); j++)
      {
        min_dist = min(min_dist, abs(house[i].y - selected_chicken_shop[j].y) + abs(house[i].x - selected_chicken_shop[j].x));
      }
      total += min_dist;
    }
    answer = min(answer, total);
    return;
  }

  for (int i = pos; i < chicken_shop.size(); i++)
  {
    selected_chicken_shop.push_back(chicken_shop[i]);
    dfs(i + 1);
    selected_chicken_shop.pop_back();
  }
}

int main()
{
  Position target;
  answer = 0x7fffffff; //int 양수 최대값

  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++)
  {
    for (int x = 0; x < n; x++)
    {
      scanf("%d", &type);
      {
        if (type == 1) //집
        {
          target.y = y;
          target.x = x;
          house.push_back(target);
        }
        if (type == 2) //치킨집
        {
          target.y = y;
          target.x = x;
          chicken_shop.push_back(target);
        }
      }
    }
  }
  dfs(0);
  printf("%d", answer);
}