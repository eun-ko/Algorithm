#include <stdio.h>

int main()
{
  int n;
  int dp[1001][10] = {
      0,
  }; //i자리에서 j값의 오르막수의 개수
  int answer = 0;

  scanf_s("%d", &n);
  for (int j = 0; j < 10; j++)
    dp[1][j] = 1;
  for (int i = 2; i <= n; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      for (int k = 0; k <= j; k++)
      {
        dp[i][j] += dp[i - 1][k];
      }
      dp[i][j] %= 10007;
    }
  }
  for (int j = 0; j < 10; j++)
    answer = (answer + dp[n][j]) % 10007;

  printf("%d", answer);
}