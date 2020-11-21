//https://programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
  int answer = 1;

  map<string, int> clothes_type;

  for (auto c : clothes)
  {
    //cloth[1]은 의상종류에 해당
    clothes_type[c[1]] += 1;
  }

  for (auto i = clothes_type.begin(); i != clothes_type.end(); i++)
  {
    //iterator
    //printf("i->first: %s\n",(i->first).c_str());
    //printf("i->second : %d\n ",i->second);
    answer *= (i->second + 1);
  }
  return answer - 1;
}