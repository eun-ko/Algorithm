#include <stdio.h>
#include <stdlib.h> //malloc
#include <queue>
using namespace std;

#define MAX_VERTICES 32001

typedef struct GraphNode
{
  int vertex;
  struct GraphNode *link; //자기참조
} GraphNode;

typedef struct GraphType
{
  int n;
  GraphNode *adj_list[MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g)
{
  g->n = 0;
  for (int v = 0; v < MAX_VERTICES; v++)
    g->adj_list[v] = NULL;
}

void insert_vertex(GraphType *g, int v)
{
  if ((g->n) + 1 > MAX_VERTICES)
  {
    fprintf(stderr, "그래프 : 정점의 개수 초과");
    return;
  }
  g->n++;
}

void insert_edge(GraphType *g, int u, int v)
{
  GraphNode *node;
  if (u - 1 >= g->n || v - 1 >= g->n) //문맥상과 실제 인덱스 구별하기!!
  {
    fprintf(stderr, "그래프: 정점 번호 오류");
    return;
  }
  node = (GraphNode *)malloc(sizeof(GraphNode));
  node->vertex = v - 1;
  node->link = g->adj_list[u - 1];
  g->adj_list[u - 1] = node;
}

void topo_sort(GraphType *g)
{
  int i;
  queue<int> q;
  GraphNode *node;
  int *in_degree = (int *)malloc(g->n * sizeof(int));
  for (i = 0; i < g->n; i++)
    in_degree[i] = 0;
  for (i = 0; i < g->n; i++)
  {
    GraphNode *node = g->adj_list[i];
    while (node != NULL)
    {
      in_degree[node->vertex]++;
      node = node->link;
    }
  }
  for (i = 0; i < g->n; i++)
  {
    if (in_degree[i] == 0)
      q.push(i);
  }
  while (!q.empty())
  {
    int w = q.front();
    q.pop(); //pop안하면 무한루프
    printf("%d ", w + 1);
    node = g->adj_list[w];
    while (node != NULL)
    {
      int u = node->vertex;
      in_degree[u]--;

      if (in_degree[u] == 0)
        q.push(u); //진입차수가 0이면 후보가 됨.

      node = node->link;
    }
  }
  free(in_degree);
  return;
}

int main()
{
  GraphType g;
  graph_init(&g);
  int n, m; //정점 간선
  scanf_s("%d %d", &n, &m);

  for (int i = 0; i < n; i++)
  {
    insert_vertex(&g, i);
  }
  for (int i = 0; i < m; i++)
  {
    int a, b;
    scanf_s("%d %d", &a, &b);
    insert_edge(&g, a, b);
  }

  topo_sort(&g);
}