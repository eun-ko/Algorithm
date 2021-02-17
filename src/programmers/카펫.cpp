//https://programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    
    vector<int> answer;
    int block_sum = brown + yellow;
    for (int height = 3; ; height++) {
        // 가로길이가 세로길이 이상이니까 height을 기준으로
        if ((block_sum % height)==0) {
            int width = block_sum / height;
            if (((height - 2) * (width - 2)) == yellow) {
                answer.push_back(width);
                answer.push_back(height);
                break; //시간제한
            }
        }
    }
    return answer;
  
}