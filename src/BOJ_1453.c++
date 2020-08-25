#include <stdio.h>

int main(void)
{
    int n, check[101] = {0}, i, num, cnt = 0;
    //입력받을 손님 수 n명, 자리 체크할 배열 check 모두 0으로 초기화
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        //앉고싶어하는 자리 입력 받기
        if (check[num] == 0)
            check[num] = 1;
        //앉고싶은자리에 해당하는 인덱스에 1표시
        else
            //1표시가 되어있는 곳이라면 카운트해주기
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}