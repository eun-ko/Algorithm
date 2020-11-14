#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int main()
{
  int n = 0;
  int temp_data = 0;
  queue<int> input_sequence;
  stack<int> temp_stack;
  queue<char> result;

  scanf_s("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf_s("%d", &temp_data);
    input_sequence.push(temp_data);
  }
  //만들 수열 입력받아서 큐에저장

  int recent_stack_input = 1;
  while (!input_sequence.empty())
  {
    if (temp_stack.size() && (temp_stack.top() == input_sequence.front()))
    {
      temp_stack.pop();
      input_sequence.pop();
      result.push('-');
    }
    //스택비어있거나(==), 만들수열의 원소가 클때(<) push
    else if (recent_stack_input <= input_sequence.front())
    {
      while (recent_stack_input <= input_sequence.front())
      {
        temp_stack.push(recent_stack_input++);
        result.push('+');
      }
    }
    //그 외엔 스택수열만들수없음
    else
    {
      printf("NO");
      return 0;
    }
  }
  while (!result.empty())
  {
    printf("%c\n", result.front());
    result.pop();
  }
  return 0;
}
