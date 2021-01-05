#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n = 0;
  vector<int> time;
  scanf_s("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int temp = 0;
    scanf_s("%d", &temp);
    time.push_back(temp);
  }
  sort(time.begin(), time.end());
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += time[i] * (n - i);
  }
  printf("%d", sum);
}