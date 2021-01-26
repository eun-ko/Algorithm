//https://programmers.co.kr/learn/courses/30/lessons/12903

#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
  string answer = "";
  if (s.length() % 2 != 0)
  {
    answer = s.substr(s.length() / 2, 1);
  }
  else
  {
    answer = s.substr(s.length() / 2 - 1, 2);
  }
  return answer;
}