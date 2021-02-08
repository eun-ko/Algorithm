//https://programmers.co.kr/learn/courses/30/lessons/12899

#include <string>
using namespace std;

string solution(int n) {
    string answer = "";
    int num[3] = {4,1,2};
    
    while(n)
    {
        int remainder = n % 3;
        n /= 3;
    
        if(remainder == 0)
            n -= 1;
        
        answer = to_string(num[remainder]) + answer;
    }
    return answer;
}