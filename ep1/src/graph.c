#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
void init_graph(graph *g, int V, int maxEdges)
{
  g->V=V;
  g->E=0;
  g->allocatedSize = maxEdges;
  g->edges = (edge *)malloc(sizeof(edge)*maxEdges);
  if(g->edges == NULL)
  {
    fprintf(stderr, "Malloc failed! Too many edges = %d\n", maxEdges);
    exit(1);
  }
}
void destroy_graph(graph *g)
{
  free(g->edges);
  free(g);
}
int compare_edge(const void *a, const void *b)
{
  if(((edge *)a)->weigth < ((edge *)b)->weigth) return -1;
  else if(((edge *)a)->weigth > ((edge *)b)->weigth) return 1;
  else return 0;
}

void init_edge(edge *e, int u, int v, float weigth)
{
  e->u=u;
  e->v=v;
  e->weigth=weigth;
}

void add_edge(graph *g, int u, int v, float weigth)
{
  edge *tmp;
  int newSize;
  if(g->E==g->allocatedSize)
  {
    /* printf("Realloc! Gotta extend g->edges. old_size=%d ", g->allocatedSize); */
    newSize = g->allocatedSize * 4;
    /* printf("new_size=%d\n",newSize); */
    tmp = realloc(g->edges, sizeof(edge)*newSize);
    if(tmp==NULL)
    {
      fprintf(stderr, "ERROR: Could not extend edges array for newSize = %d\n", newSize);
      exit(1);
    }
    g->edges=tmp;
    g->allocatedSize=newSize;
  }
  init_edge(&g->edges[g->E],u,v,weigth);
  g->E++;
}
void print_edge(edge *e)
{
  printf("%d-%d weigth=%f\n", e->u, e->v, e->weigth);
}
