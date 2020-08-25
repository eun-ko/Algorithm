#include <stdio.h>

//각자리수가 등차수열을 이룰 때 한수.
int isHan(int n)
{
    int i, cnt = 0, h, t, o;
    if (n < 100)
        return n;
    //한자리수, 두자리수는 모두 한수에 해당함
    else
    {
        for (i = 100; i <= n; i++)
        {
            h = i / 100;
            //백의자리수
            t = (i % 100) / 10;
            //십의 자리수
            o = (i % 100) % 10;
            //일의 자리수
            if ((h - t) == (t - o))
                cnt++;
            //한수이면 cnt에 1씩 더하기
        }
        return (99 + cnt);
        //99까지는 모두 한수이므로 99개의 한수에 cnt더하기
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", isHan(n));
    return 0;
}