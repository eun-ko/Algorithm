#include <stdio.h>

int best[501][501]; //최적 경로의 합을 저장해나갈 best배열
int a[501][501];    //사용자로부터 입력받을 숫자 삼각형 저장할 배열
int prev[501][501]; //어디서 온건지 저장할 배열
int route[20];      //경로를 저장할 배열
int maxin;          //최대레벨에서의 가장 큰 값에 해당하는 인덱스를 넣어줄 변수

int get_max(int a, int b)
{
    return a > b ? a : b;
}
//매개변수로 받은 두 정수 값중 더 큰 값을 출력하는 함수 정의
int main()
{
    int n, max = 0;
    /*
    n: 최대 레벨 입력받을 변수
    max : 경로의 합중 최대를 저장할 변수
    */
    scanf_s("%d", &n);
    //최대 레벨 n을 입력 받아서 저장
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf_s("%d", &a[i][j]);
    //정수 삼각형 입력받아서 이차원 배열에 저장
    best[1][1] = a[1][1]; //초기값 저장
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            best[i][j] = a[i][j] + get_max(best[i - 1][j], best[i - 1][j - 1]);
            /* 정수 삼각형의 현재레벨에 있는 값에
                그 전 레벨의 값중 더 큰 값을 더해서 저장해줌 */
            if (best[i - 1][j] > best[i - 1][j - 1])
                prev[i][j] = j;
            else
                prev[i][j] = j - 1;
            /* 어디서 온건지 저장하기 위해 어떤값이 더 컸냐에 따라
            그 값의 열에 해당하는 인덱스를 저장해줌 */
        }
    for (int i = 1; i <= n; i++)
    {
        max = get_max(max, best[n][i]);
        //최대레벨에 있는 best값중 최대값을 찾아서 max에 넣어줌
        if (max == best[n][i])
            maxin = i;
        //최대레벨에서의 가장 큰 값에 해당하는 index를 maxin에 넣어줌
    }
    printf("합은 : %d\n", max); //최적의 경로값 출력
    int i = n;                  //최대레벨을 route배열의 인덱스가 될 i변수에 넣어줌
    while (n != 0)
    { //최대레벨이 0이 아닐때까지 반복
        route[--i] = a[n][maxin];
        //최적 경로에 해당하는 숫자 삼각형의 값을 저장해줌
        maxin = prev[n--][maxin];
        //최적 경로에 있는 숫자 삼각형을 prev를 이용하여 역 추적해나감
    }
    printf("경로에 있는 수들은 : ");
    for (int k = 0; k < 5; k++)
        printf("%d ", route[k]);
    //경로에 있는 수 출력
    return 0;
}