#include <stdio.h>

int coin[101]; //동전의 가치 저장
int dp[10001]; //가치의 합이 k원이 되게 하는 경우의 수 저장

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &coin[i]);
  }
  dp[0] = 1; //0원을 만드는 경우의 수는 아무 동전도 사용안하는 한가지
  for (int i = 1; i <= n; i++)
  {
    for (int j = coin[i]; j <= k; j++)
    {
      dp[j] += dp[j - coin[i]];
    }
  }
  printf("%d", dp[k]);
}
