#include <stdio.h>

int main()
{
    int n, m, cycle = 0;
    scanf("%d", &n);
    m = n;
    //n은 계속 갱신되므로 초기값 저장할 m필요
    printf("m에n넣어줌\n");
    int ten, one, sum_one;
    do
    {
        ten = n / 10;
        one = n % 10;
        sum_one = (ten + one) % 10;
        n = one * 10 + sum_one;
        //수 갱신
        cycle++;
        printf("n은 %d m은 %d\n", n, m);
    } while (n != m);
    printf("%d", cycle);
}