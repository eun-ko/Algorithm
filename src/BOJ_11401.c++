#include <stdio.h>
long long mul(long long x, long long y, long long p)
{
    //x의 y승을 p로 나눈 나머지 구하기
    long long ans = 1;
    while (y > 0)
    {
        //y가 0보다 클때까지 반복
        if (y % 2 != 0)
        {
            ans *= x;
            //ans에 x를 곱해나감
            ans %= p;
            //p로 나눈 나머지값을 저장
        }
        x *= x;
        x %= p;
        //x에 x를 곱해나가고 p로 나눈 나머지 값을 저장한다.
        y /= 2;
        //y를 2로 나눠줌
    }
    return ans;
}
int main()
{
    long long n, r, p;
    //n,r,p변수 선언
    scanf("%lld %lld", &n, &r);
    //n,r을 입력받음
    p = 1000000007LL;
    //p에 소수 값 저장
    long long ans = 1;
    long long t1 = 1;
    long long t2 = 1;
    //ans,t1,t2변수 1로 초기화
    for (long long i = 1; i <= n; i++)
    {
        t1 *= i;
        t1 %= p;
        //t1에 n팩토리얼을 계산해나가면서 p로 나눈 나머지 값을 저장함.
    }
    for (long long i = 1; i <= r; i++)
    {
        t2 *= i;
        t2 %= p;
        //t2에 r팩토리얼을 계산해나가면서 p로 나눈 나머지 값을 저장함.
    }
    for (long long i = 1; i <= n - r; i++)
    {
        t2 *= i;
        t2 %= p;
        //위에서 구한 t2값에
        //(n-r)팩토리얼을 계산해가며 p로 나눈 나머지 값을 저장함.
    }
    long long t3 = mul(t2, p - 2, p);
    // mul함수를 호출하여 t3에 값을 저장한다.
    t3 %= p;
    //t3를 p로 나눈 값을 t3에 저장한다.
    ans = t1 * t3;
    // t1과 t3의 값을 곱한다.
    ans %= p;
    // 그 값을 p로 나눈 나머지가 결과가 된다.
    printf("%lld", ans);
    return 0;
}