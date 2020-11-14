#include <stdio.h>

int remaind(int *arr)
{
    int i, result = 0;
    //서로 다른 나머지 개수 저장할 변수 result
    int cnt[42] = {
        0,
    };
    //나머지값 체크할 배열 cnt 모두 0으로 초기화
    //cnt index(0~41)가 나머지를 의미. cnt의 원소값이 같은 나머지값을 가지는 arr원소의 개수를 의미함
    for (i = 0; i < 10; i++)
    {
        cnt[arr[i] % 42]++;
        //인자로 받은 배열안의 원소들을 42로 나눈 나머지를 cnt에 체크
    }
    for (i = 0; i < 42; i++)
    {
        if (cnt[i] != 0)
            result++;
        //cnt에 체크한 값이 0이 아니라면 result에 1씩 더해나감
    }
    return result;
}
int main(void)
{
    int arr[10];
    int i;
    //수 10개 입력받아 배열에 저장.
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    //배열을 인자로보내기
    printf("%d", remaind(arr));
}