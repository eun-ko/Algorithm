//https://programmers.co.kr/learn/courses/30/lessons/43105

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[500][500]; //dp[i][j] : i행 j열 번째 삼각형까지 오는데까지의 최대합을 저장
int solution(vector< vector<int> > triangle) {
    int answer = 0;
    int n = triangle.size();
    dp[0][0] = triangle[0][0]; //첫째줄에 있는 삼각형을 저장
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<=i; j++) {
            if(j==0) {
                dp[i][j] = dp[i-1][j] + triangle[i][j]; //맨 왼쪽일 경우
            }
            else if(j==i) {
                dp[i][j] = dp[i-1][i-1] + triangle[i][j];// 맨 오른쪽일 경우
            }
            else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    for(int i = 0; i < n;i++) {
        //맨 마지막 행 중에서 최대값을 찾음
        if(answer < dp[n-1][i]) { 
            answer = dp[n-1][i];
        }
    }
    return answer;
}