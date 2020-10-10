#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
  char original_input[600000];
  scanf("%s", original_input);
  int len = strlen(original_input);

  stack<char> left, right; //스택 2개필요 (커서기준 왼/오)

  for (int i = 0; i < len; i++)
    left.push(original_input[i]);

  int n;
  scanf("%d", &n);

  while (n--)
  {
    char command;
    scanf(" %c", &command);

    if (command == 'L')
    {
      if (!left.empty()) //문장 맨 앞이면 무시
      {
        right.push(left.top());
        left.pop();
      }
    }
    else if (command == 'D')
    {
      if (!right.empty()) //문장 맨 뒤면 무시
      {
        left.push(right.top());
        right.pop();
      }
    }
    else if (command == 'B')
    {
      if (!left.empty())
        left.pop();
    }
    else if (command == 'P')
    {
      char c;
      scanf(" %c", &c);
      left.push(c);
    }
  }
  while (!left.empty())
  { //lstack에 있는 값들을 모두 rstack으로
    right.push(left.top());
    left.pop();
  }
  while (!right.empty())
  {
    printf("%c", right.top());
    right.pop();
  }
}
