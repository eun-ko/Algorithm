#include <stdio.h>

//버블 정렬
int main(void)
{
    int n, i, j, tmp;
    int arr[1001];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = n - 1; i > 0; i--)
    {
        // 0 ~ (i-1)까지 반복
        for (j = 0; j < i; j++)
        {
            // i루프 돌때마다(각 패스) 가장 큰 원소가 맨 뒤로 이동하므로
            // 끝에 자료가 검사에서 제외됨
            if (arr[j] > arr[j + 1])
            {
                //서로 인접한 두 원소 검사 후 크기순 아닐 시 swap
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for (i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}