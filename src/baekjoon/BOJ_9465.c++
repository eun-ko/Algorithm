#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[2][100001];
int tmp[2][100001];
int answer;

void solve(int n)
{
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &tmp[0][i]);
  }
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &tmp[1][i]);
  }
  dp[0][0] = tmp[0][0];
  dp[1][0] = tmp[1][0];
  dp[0][1] = tmp[0][1] + dp[1][0];
  dp[1][1] = tmp[1][1] + dp[0][0];

  for (int i = 2; i < n; i++)
  {
    //1칸 뒤, 또는 2칸 뒤 중 최대값
    dp[0][i] = tmp[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
    dp[1][i] = tmp[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
  }
  answer = max(dp[0][n - 1], dp[1][n - 1]);
}

int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--) //테케
  {
    scanf("%d", &n);
    solve(n);
    printf("%d\n", answer);
  }
}