#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

//인접한건 레이저 그냥 쌍 맞으면 막대기
int main()
{
  char parenthesis[100001];
  scanf("%s", parenthesis);
  int len = strlen(parenthesis);
  int result = 0;
  stack<int> par_index_stack;

  for (int i = 0; i < len; i++)
  {
    //여는 괄호
    if (parenthesis[i] == '(')
    {
      par_index_stack.push(i);
      //괄호말고 인덱스 push
    }
    //닫는 괄호
    else
    {
      //인접했을 경우 체크, 레이저 만난 경우
      if (par_index_stack.top() + 1 == i)
      {
        par_index_stack.pop(); //laser pop
        result += par_index_stack.size();
      }
      //닫는괄호 (쇠막대기 끝인 거니까 1더해주기)
      else
      {
        par_index_stack.pop(); //stick pop
        result += 1;
      }
    }
  } //loop end;
  printf("%d", result);
}