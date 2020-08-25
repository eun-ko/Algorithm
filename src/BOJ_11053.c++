#include <stdio.h>

// 가장 긴 증가하는 부분 수열 길이 출력 + "수열까지" 출력하기.

int main(void)
{
    int n;             //수열의 크기 입력받을 변수
    int h[1010] = {0}; //부분 수열의 길이 저장할 배열
    int p[1010] = {0}; //전 값의 인덱스 저장할 배열
    int s[1010] = {0}; //수열의 원소 저장할 배열
    int max = 0;       //h배열중 최대값을 저장할 변수
    int index;         //최대 부분 수열의 길이를 가지는 인덱스를 저장할 변수
    scanf_s("%d", &n); //수열의 크기 입력받기
    int MAX = n + 1;
    for (int i = 1; i < MAX; i++)
        scanf_s("%d", &s[i]); //수열의 원소 입력받기
    for (int i = 1; i < MAX; i++)
        for (int j = 0; j < i; j++)
            if ((s[i] > s[j]) && (h[i] < (h[j] + 1)))
            //수열의 i번째 원소보다 더 작은 값에 대해서 적용
            {
                h[i] = h[j] + 1;
                //h값을 전원소의h값에 1을 더해준 후 갱신해줌
                p[i] = j;
                //전 원소의 인덱스를 저장
            }
    for (int i = 1; i < MAX; i++)
    {
        if (max < h[i])
        {
            max = h[i];
            //인덱스를 증가시켜나가면서, max값보다 큰 h값을 max에 갱신시켜서 넣어줌
            index = i;
            //최대 부분 수열의 길이에 해당하는 인덱스 i값을 index변수에 저장하기
        }
    }
    printf("최장 증가 부분 수열의 길이는 %d\n", max);
    //LIS의 길이를 출력
    int lis[1010] = {};
    //최대 부분 수열에 해당하는 원소들을 저장할 배열
    int i = max;
    //h의 최대값 max를 lis배열의 인덱스가 될 i변수에 넣어줌
    while (index != 0)
    {
        //인덱스가 0이 아닐때 까지 반복
        lis[--i] = s[index];
        //인덱스에 해당하는 수열의 원소를 lis배열에 넣어줌
        index = p[index];
        //전 원소의 인덱스로 갱신하여 loop수행하게끔함
    }
    printf("그 수열은 : ");
    for (i = 0; i < max; i++)
        printf("%d ", lis[i]);
    //해당 수열 출력
    return max;
}