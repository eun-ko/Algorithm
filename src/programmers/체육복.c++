//https://programmers.co.kr/learn/courses/30/lessons/42862

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> students(n, 1); //학생들의 체육복 유무 표시할 벡터
    for (int i = 0; i < lost.size(); i++)
    {
        students[lost[i] - 1]--; //도난 당한 학생들 -1
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        students[reserve[i] - 1]++; // 여벌 있는 학생들 +1
    }
    for (int i = 0; i < n; i++)
    {
        if (students[i] == 0 && students[i - 1] == 2 && i >= 1)
        {
            students[i - 1]--; //앞학생이 여벌 빌려줌 (-1)
            students[i]++;     //i번째 학생이 여벌 빌림
        }
        if (students[i] == 0 && students[i + 1] == 2 && i <= n - 2)
        {
            students[i + 1]--; //뒷학생이 여벌 빌려줌 (+1)
            students[i]++;
        }
    }
    for (auto s : students)
    {
        if (s > 0)
            answer++; //0이 아닌 학생 개수 세기
    }
    return answer;
}