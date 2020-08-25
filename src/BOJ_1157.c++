#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[1000001];
    int arr[26] = {0}, i, len, max = 0, idx, cnt = 0;
    //알파벳 사용여부 체크할 배열 0으로 초기화.
    scanf("%s", str);
    len = strlen(str);
    //문자열 입력받고 길이구하기

    for (i = 0; i < len; i++)
    {
        //대소문자 구별이 없음.
        if (str[i] >= 'A' && str[i] <= 'Z')
            arr[str[i] - 'A']++;
        if (str[i] >= 'a' && str[i] <= 'z')
            arr[str[i] - 'a']++;
        //아스키코드를 이용하여 사용된 알파벳이 있다면 1 더해주기
    }
    for (i = 0; i < 26; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            //max값 갱신
            idx = i;
            //그 max값에 해당하는 인덱스를 idx변수에 저장하기
            cnt = 0;
            //cnt값을 0으로 다시 초기화
        }
        else if (arr[i] == max)
        {
            cnt++;
            //가장 많이 사용된 알파벳이 여러개인 경우를 체크하기 위함.
        }
    }
    if (cnt > 0)
        printf("?");
    //가장 많이 사용된 알파벳이 여러개인 경우
    else
        printf("%c", idx + 'A');
    //인덱스에 다시 'A'를 더해주어 정확한 아스키코드 값으로 변환시키기.(상대적 차이가 아닌값)
    return 0;
}