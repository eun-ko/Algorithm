#include <stdio.h>
#include <string.h>
//문자열 처리 함수 strlen를 위한 헤더 포함
int main(void)
{
    char s[1001];
    //입력받을 문자열 S
    int arr[26], t, i, j, sum = 0, len;
    //입력받을 테스트 데이터 개수 t 및 반복문 지역변수 i,j
    //알파벳 26자리 체크할 배열 arr[26]
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%s", s);
        for (j = 0; j < 26; j++)
            arr[j] = 1;
        //arr배열 1로 초기화
        sum = 0;
        len = strlen(s);
        for (j = 0; j < len; j++)
        {
            arr[s[j] - 'A'] = 0;
            //문자에서 'A'만큼의 차를 구하면 아스키코드값에 해당함
        }
        //해당하는 알파벳이 있는 번호는 0으로 만들기(등장하지 않는 알파벳의 아스키코드 합을 구해야 하므로 알파벳이 존재하면 0으로 표시)
        for (j = 0; j < 26; j++)
            sum += arr[j] * (j + 'A');
        //'A'를 다시 더해주면 아스키코드값
        //등장한 알파벳은 0이므로 전체 for loop를 돌아도 sum값에 영향을 주지 않음.

        printf("%d\n", sum);
    }
    return 0;
}