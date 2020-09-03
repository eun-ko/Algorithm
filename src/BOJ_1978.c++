#include <stdio.h>

int main()
{
    int n, arr[1001], num;
    int ans = 0;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            continue;
        //1은 소수아님

        for (int j = 1; j <= arr[i]; j++)
        {
            if (arr[i] % j == 0)
                cnt++;
        }
        if (cnt == 2)
            //1과 자기자신만 나눠떨어졌을경우, cnt==2
            ans++;
        cnt = 0;
        //cnt초기화
    }
    printf("%d", ans);
    return 0;
}
