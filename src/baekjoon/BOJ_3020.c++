#include <stdio.h>
const int MAX_HEIGHT = 500001;

int number_to_destroy[MAX_HEIGHT] = {
    0,
}; //level(index)별 파괴할 개수
int top[MAX_HEIGHT] = {
    0,
}; //index : 조회할 level에 있는 종유석의 개수
int bottom[MAX_HEIGHT] = {
    0,
}; //index : 조회할 level에 있는 석순의 개수

int main()
{
    int N, H;
    scanf("%d %d", &N, &H);
    for (int i = 1; i <= N / 2; i++) //N번 돌면 시간초과
    {
        int s_length, j_length;
        scanf("%d %d", &s_length, &j_length);
        bottom[s_length]++;      //석순부터
        top[H + 1 - j_length]++; //종유석 index를 조회할level과 맞춰주기
    }
    for (int i = H - 1; i >= 1; i--)
    {
        bottom[i - 1] += bottom[i]; //누적합
    }
    for (int i = 1; i < H; i++)
    {
        top[i + 1] += top[i]; //누적합
    }
    number_to_destroy[1] = N / 2; // level 1에는 항상 석순 존재
    number_to_destroy[H] = N / 2; //level H에는 항상 종유석 존재
    int result = number_to_destroy[1];
    int cnt = 2; //최소 개수 lv1,lvH 두가지 경우
    for (int i = 2; i < H; i++)
    {
        number_to_destroy[i] = top[i] + bottom[i];
        if (result > number_to_destroy[i])
        {
            result = number_to_destroy[i];
            cnt = 1; //최소값 갱신
        }
        else if (result == number_to_destroy[i])
            cnt++;
    }
    printf("%d %d", result, cnt);
}