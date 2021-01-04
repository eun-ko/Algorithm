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
  int q = 0;
  int answer = 0;
  int price_index = 0;
  while (q == 0)
  {
    q = k / price[price_index];
    price_index++;
  }
  answer += q;
  int remain_k = k - (price[price_index - 1] * q);
  q = 0;
  while (1)
  {
    q = remain_k / price[price_index];
    remain_k = remain_k - (q * price[price_index]);
    price_index++;
    answer += q;
    if (remain_k == 0)
      break;
  }
  printf("%d", answer);
}