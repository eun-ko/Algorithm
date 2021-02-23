//https://programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index=-1;
    for (int i = 0; i < number.length() - k; i++) {
        char max = 0;
        for (int j = index + 1; j <= k + i; j++) {
            if (max < number[j]) {
                index = j;
                max = number[j];
            }
        }
        answer += max;
    }
    return answer;
}