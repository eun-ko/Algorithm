#include <stdio.h>

int main()
{
  int n;
  int dp[1001][10] = {
      0,
  }; //i자리에서 마지막 값이 j일때 오르막수의 개수
  int answer = 0;
  scanf_s("%d", &n);
  for (int j = 0; j < 10; j++)
    dp[1][j] = 1; //한자리수의 경우는 0,1,..9 각각 오르막수 1개씩
  for (int i = 2; i <= n; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      for (int k = 0; k <= j; k++)
      {
        dp[i][j] += dp[i - 1][k]; //ex) dp[2][4]은 dp[1][0]~dp[1][4] 까지의 합. 이런식으로 점화식을 for문 돌리기
      }
      dp[i][j] %= 10007; //자료형 범위 초과 방지를 위해 각 값마다 나머지 연산 해주기
    }
  }
  for (int j = 0; j < 10; j++)
    answer += dp[n][j]; //정답은 n행에 있는 값을 모두 합한것

  printf("%d", answer % 10007);
}