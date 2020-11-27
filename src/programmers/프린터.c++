
//https://programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
  queue<int> index;        //queue에 index 삽입
  vector<int> print_order; //정렬된 결과 (pq와 같은 역할)
  for (int i = 0; i < priorities.size(); i++)
  {
    index.push(i);
  }
  while (!index.empty())
  {
    int currnet_index = index.front(); //front()하고 pop해주기!! (런타임)
    index.pop();
    if (priorities[currnet_index] != *max_element(priorities.begin(), priorities.end())) //최고 우선순위와 같은 경우
    //max_element 주소값반환하니까 *로 값 받기!!!
    {
      index.push(currnet_index);
    }
    else
    {
      print_order.push_back(currnet_index);
      priorities[currnet_index] = 0; //최고 우선순위 쓴 후에는 0으로 바꿔줘야함
    }
  }
  for (int i = 0; i < print_order.size(); i++)
  {
    if (print_order[i] == location)
      return i + 1;
  }
}