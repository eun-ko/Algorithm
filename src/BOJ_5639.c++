#include <stdio.h>

int inorder_tree[10001];

void post_order(int node, int bound)
{
  int r_start_index = node + 1;
  while (r_start_index <= bound && inorder_tree[r_start_index] < inorder_tree[node])
    r_start_index++;
  //전위순회한 루트값보다 커지는 곳이 오른쪽 서브트리의 시작 인덱스

  int l_start_index = node + 1;
  if (l_start_index <= r_start_index - 1)
    post_order(l_start_index, r_start_index - 1);
  //재귀,left tree 순회(L)

  if (r_start_index <= bound)
    post_order(r_start_index, bound);
  //재귀,right tree순회(R)

  printf("%d\n", inorder_tree[node]); //root출력(V)
}
int main()
{
  int node_index = 1;
  while (EOF != scanf("%d", &inorder_tree[node_index]))
    node_index++;
  post_order(1, node_index - 1); //node_index가아니라 node_index-1.. node_index++까지 하고 while나오니까
}