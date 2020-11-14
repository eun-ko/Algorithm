#include <stdio.h>
#include <string.h>
//문자열 연습
int main(void)
{
    int n, i;
    scanf("%d", &n);
    //입력받을 문자열 개수
    char arr[n][1000];
    //이차원 배열이용
    for (i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
        //문자열 입력받을때, &연산자 필요 없음
    }
    for (i = 0; i < n; i++)
    {
        printf("%c%c\n", arr[i][0], arr[i][strlen(arr[i]) - 1]);
        //마지막 문자 : i행의 문자열의 길이 -1
    }