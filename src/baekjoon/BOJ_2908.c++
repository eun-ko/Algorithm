#include <stdio.h>

int main()
{
    int a, b, ar = 0, br = 0;
    scanf("%d %d", &a, &b);
    ar = (a % 10) * 100 + (a / 10) % 10 * 10 + (a / 100) % 10;
    br = (b % 10) * 100 + (b / 10) % 10 * 10 + (b / 100) % 10;
    printf("%d", ar > br ? ar : br);
}