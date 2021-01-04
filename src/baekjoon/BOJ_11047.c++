#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n = 0;
  int k = 0;
  scanf_s("%d %d", &n, &k);
  vector<int> price;
  for (int i = 0; i < n; i++)
  {
    int temp = 0;
    scanf_s("%d", &temp);
    price.push_back(temp);
  }
  sort(price.rbegin(), price.rend()); //내림차순 정렬하기
  int answer = 0;
  for (int i = 0; i < n; i++)
  {
    while (k / price[i])
    {
      answer += k / price[i];
      k %= price[i];
    }
  }
  printf("%d", answer);
}
