#include <stdio.h>

int solution(int n, int m)
{
    int answer = 0; //지난 날 수
    while (n)
    {
        //n이 0이 아닐때동안
        n--;
        answer++;
        if (answer % m == 0)
            n++;
    }
    return answer;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int answer = solution(n, m);
    printf("%d", answer);
}
