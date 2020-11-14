#include <stdio.h>
#include <math.h>
//abs메소드 사용을 위한 math헤더

struct point
{
    int x, y;
};
//구조체 이용

int GetDaisyDistance(struct point *p1, struct point *p2)
{
    return (abs(p1->x - p2->x) + abs(p1->y - p2->y));
    //데이지는 대각선이동 불가능하므로,
    //존과의 x축 y축 거리차이의 합이 최단경로
}

int GetBessieDistance(struct point *p1, struct point *p2)
{
    // 베시는 대각선이동 가능,
    // 따라서 존과의 x축 거리차와 y축 거리차 중 짧은 값이 최단경로
    int x = abs(p1->x - p2->x);
    int y = abs(p1->y - p2->y);
    if (x > y)
        return x;
    else
        return y;
}

int main(void)
{
    int bx, by;
    //베시의 x,y좌표
    int dx, dy;
    //데이지의 x,y좌표
    int jx, jy;
    //존의 x,y좌표
    scanf("%d %d", &bx, &by);
    scanf("%d %d", &dx, &dy);
    scanf("%d %d", &jx, &jy);
    //좌표 입력받기
    struct point b = {bx, by};
    struct point d = {dx, dy};
    struct point j = {jx, jy};
    if (GetBessieDistance(&b, &j) < GetDaisyDistance(&d, &j))
        printf("bessie");
    else if (GetBessieDistance(&b, &j) > GetDaisyDistance(&d, &j))
        printf("daisy");
    else
        printf("tie");
}