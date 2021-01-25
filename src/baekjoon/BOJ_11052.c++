#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  vector<int> dp(n + 1);    //dp[i] : 카드 i개 구매했을때의 최대비용
  vector<int> price(n + 1); //price[i] : 카드가 i개 들어있는 카드팩 가격

  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &price[i]);
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      dp[i] = max(dp[i], dp[i - j] + price[j]);
    }
  }

  printf("%d", dp[n]);
}