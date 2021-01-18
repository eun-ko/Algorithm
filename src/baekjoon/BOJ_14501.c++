#include <stdio.h>
#include <algorithm>
using namespace std;

int n = 0;
int t[16];
int p[16];
int dp[16];
int answer = 0;

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d %d", &t[i], &p[i]);

  for (int i = 1; i <= n; i++)
  {
    if (i + t[i] <= n + 1)
    {
      dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
      answer = max(answer, dp[i + t[i]]);
    }
    dp[i + 1] = max(dp[i + 1], dp[i]);
    answer = max(answer, dp[i + 1]);
  }

  printf("%d\n", answer);
}