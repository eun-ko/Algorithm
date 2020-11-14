#include <stdio.h>

int main(void)
{
    int N;
    int count = 0;
    scanf("%d", &N);

    while (N > 0)
    {
        if (N % 5 == 0)
        {
            N -= 5;
            count++;
        }
        else if (N % 3 == 0)
        {
            N -= 3;
            count++;
        }
        //3이랑 5로 나누어지는 경우, 5보다 큰경우로 나누기
        //(3보다 큰 경우가 없는이유 : ex)1,2,4가 최종으로 남았다면 어차피 안나눠떨어짐)
        else if (N > 5)
        {
            //5보다 클때는 우선 큰봉지로 묶어야하니 5를 빼주기
            N -= 5;
            count++;
        }
        else
        {
            //나누어 떨어지지 않을때는 -1 대입 후 반복문 끝내기.
            count = -1;
            break;
        }
    }
    printf("%d", count);
}