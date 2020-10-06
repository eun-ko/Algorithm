#include <stdio.h>

int main()
{
  int queue[10001];
  char command[10];
  int front = 0;
  int back = 0;
  int n;
  int push_num = 0;
  scanf_s("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf_s("%s", command);
    if (command[1] == 'u')
    {
      //push
      scanf_s("%d", &push_num);
      queue[back++] = push_num;
      //idx 0부터 삽입
    }
    else if (command[1] == 'm')
    {
      //empty
      printf("%d\n", back - front ? 0 : 1);
    }
    else if (command[1] == 'o')
    {
      //pop
      printf("%d\n", back - front ? queue[front++] : -1);
      //front값 출력후 index증가시키기(실제로 값이 배열에서 사라지진 않아서 야매식..)
    }
    else if (command[1] == 'r')
    {
      //front
      printf("%d\n", back - front ? queue[front] : -1);
    }
    else if (command[1] == 'a')
    {
      //back
      printf("%d\n", back - front ? queue[back - 1] : -1);
    }
    else if (command[1] == 'i')
    {
      //size
      printf("%d\n", back - front);
    }
  }
}