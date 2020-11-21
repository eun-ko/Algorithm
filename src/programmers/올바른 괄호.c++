//https://programmers.co.kr/learn/courses/30/lessons/12909

#include <string>
#include <stack>
#include <stdio.h>

using namespace std;

bool solution(string s)
{
  bool answer = true;
  char check;
  stack<char> parenthesis_stack;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == ')')
    {
      if (parenthesis_stack.size() == 0)
      {
        answer = false;
        break;
      }
      else
        parenthesis_stack.pop();
    }
    else
    {
      parenthesis_stack.push(s[i]);
    }
  }
  if (parenthesis_stack.size() > 0)
    answer = false; //짝 맞게 다 pop했는데 남아있으면 안됨
  return answer;
}