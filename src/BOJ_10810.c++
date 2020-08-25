#include <stdio.h>

int main(void)
{
    int n, m, arr[101] = {0}, i, j, a, b, c;
    //인덱스로 체크할 배열 선언하는것 익숙해지기
    scanf("%d %d", &n, &m);
    //바구니 n개, 공을 넣을 횟수 m회 입력받기
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        //a번 바구니부터 b번바구니까지 c번공을 넣는다.
        for (j = a; j <= b; j++)
        {
            arr[j] = c;
            //해당하는 인덱스에 공번호를 대입.
        }
    }
    for (i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}