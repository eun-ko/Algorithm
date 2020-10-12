#include <stdio.h>

typedef struct TreeNode
{
  char data;
  struct TreeNode *left, *right;
} TreeNode;

void preorder(TreeNode *r)
{
  if (r)
  {
    printf("%c", r->data); //v
    preorder(r->left);     //l
    preorder(r->right);    //r
  }
}
void inorder(TreeNode *r)
{
  if (r)
  {
    inorder(r->left);      //l
    printf("%c", r->data); //v
    inorder(r->right);     //r
  }
}
void postorder(TreeNode *r)
{
  if (r)
  {
    postorder(r->left);    //l
    postorder(r->right);   //r
    printf("%c", r->data); //v
  }
}

int main()
{
  int n = 0;
  scanf("%d", &n);
  TreeNode root[27];
  char root_node, left_child, right_child;
  int order;
  for (int i = 0; i < n; i++)
  {
    scanf(" %c %c %c", &root_node, &left_child, &right_child); //for문으로 문자여러개받을때 앞에 버퍼처리!!!!!!런타임에러남 ㅠ
    order = root_node - 'A';                                   //알파벳순서가 트리배열의 순서. 아스키코드값빼주기
    root[order].data = root_node;
    if (left_child == '.')
      root[order].left = NULL;
    else
      root[order].left = &root[left_child - 'A'];

    if (right_child == '.')
      root[order].right = NULL;
    else
      root[order].right = &root[right_child - 'A'];
  }
  preorder(&root[0]);
  printf("\n");
  inorder(&root[0]);
  printf("\n");
  postorder(&root[0]);
}