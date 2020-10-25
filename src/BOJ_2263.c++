#include <stdio.h>

int inorder[100001] = {};
int postorder[100001] = {};
int inorder_index[100001] = {};

void get_preorder(int is, int ie, int ps, int pe)
{
  if (is > ie || ps > pe)
    return;
  int root_index = inorder_index[postorder[pe]]; //후순위의 끝이 루트의 인덱스임
  printf("%d ", inorder[root_index]);            //V
  //후순위를 통해 구한 루트를 기준으로 왼/오를 중순위에서 나눠서 원소 개수구하기
  int l_size = root_index - is;
  int r_size = ie - root_index;

  get_preorder(is, root_index - 1, ps, ps + l_size - 1); //is~root_index-1까지 inorder에서 체크, ps~ps+l_size-1까지 postorder에서 체크
  //L
  get_preorder(root_index + 1, ie, ps + l_size, pe - 1); //R
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
  {
    scanf(" %d", &inorder[i]);
    inorder_index[inorder[i]] = i; //해당하는 값의 인덱스를 저장
  }

  for (int i = 1; i <= n; i++)
  {
    scanf(" %d", &postorder[i]); //루트 구할때 필요
  }
  get_preorder(1, n, 1, n);
  return 0;
}