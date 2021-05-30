//https://programmers.co.kr/learn/courses/30/lessons/42628

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);

    vector<int> q;

    for(auto o : operations) {
        string operation = o.substr(0,1);
        int num = stoi(o.substr(2));
        // 삽입
        if(operation == "I") {
            q.push_back(num);
            sort(q.begin(), q.end());
        }
        // 삭제
        else {
            if(q.size() == 0)
                continue;
            // 최대값 삭제
            if(num == 1) {
                q.erase(q.begin() + (q.size()-1));
            }
            // 최소값 삭제
            if(num == -1) {
                q.erase(q.begin());
            }
        }
    }

    if(!q.empty()) {
        answer.clear();
        answer.push_back(q.back());
        answer.push_back(q.front());
    }

    return answer;
}