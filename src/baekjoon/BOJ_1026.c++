#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

void init(vector<int> &v, int n)
{
  //주소값으로 넘기기.. vector subscript out of range
  int temp = 0;
  for (int i = 0; i < n; i++)
  {
    scanf_s("%d", &temp);
    v.push_back(temp);
  }
}

int main()
{
  int n = 0;
  int sum = 0;
  scanf_s("%d", &n);
  vector<int> a, b;
  init(a, n);
  init(b, n);
  sort(a.begin(), a.end());   //ascending
  sort(b.rbegin(), b.rend()); //descending
  for (int i = 0; i < n; i++)
  {
    sum += a[i] * b[i];
  }
  printf("%d", sum);
}