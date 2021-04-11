//https://programmers.co.kr/learn/courses/30/lessons/62048

#include <stdio.h>
#include <algorithm>
using namespace std;

/*
유클리드 호제법

int get_gcd(long long a, long long b){
    int mod,min,max;
    if(a < b) {min = a, max=b;}
    else {min = b; max = a;}
    while(min != 0){
        mod = (max % min);  //mod가 0이면 min이 gcd
        max = min;
        min = mod;
    }
    return max;
}
*/

long long solution(int w,int h)
{
    long long w1=w,h1=h; //1억 이하이므로 long long 타입
    return (w1 * h1) - (w1 + h1 - __gcd(w1,h1));
}