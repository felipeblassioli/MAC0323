/***************************/
/* Parte 2: Implementacoes */
/***************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "plist.h"
#include "dsets.h"
#include "graph.h"

dsets *dset;
graph *gr;

float kruskal(graph *g, dsets *dset, float *maxWeigth);
void prepare(int N);

float kruskal(graph *g, dsets *dset, float *maxWeigth)
{
  int totEdges;
  int i;
  int r1,r2;
  int v1, v2;
  float totalWeigth;
  edge *e;
  /* Ordena o conjunto de arestas por peso */
  qsort(g->edges, g->E, sizeof(edge), compare_edge);
  i=0; totEdges=0;
  while(totEdges < g->V-1 && i < g->E)
  {
    /* Edge de menor peso  */
    e=&g->edges[i++];
    v1=e->u; v2=e->v;
    /* 
     * Verifica se os vertices pertencem a mesma arvore.
     * Junta as arvores quando negativo.
     */
    r1=disj_find(dset, v1); r2=disj_find(dset, v2);
    if(r1!=r2)
    {
      totEdges++;
      totalWeigth+=e->weigth;
      disj_union(dset, r1, r2);
      /* print_edge(e); */
      if(*maxWeigth<e->weigth) *maxWeigth = e->weigth;
    }
  }
  /*printf("maxWeigth = %f\n", *maxWeigth);
  printf("totEdges = %d g->V=%d\n",totEdges,g->V);*/
  if(totEdges < g->V-1)
    return -1;  
  return totalWeigth;
}
void prepare(int N)
{
  int maxEdges;
  /*printf("prepare N=%d\n", N);*/
  gr=malloc(sizeof(*gr));
  dset=malloc(sizeof(*dset));
  if(gr==NULL||dset==NULL)
  {
    fprintf(stderr, "ERRO: malloc falhou!\n");
  }
  maxEdges=(N < 25000)? max_edges(N) : 3*N;
  init_graph(gr, N, maxEdges);
  init_dsets(dset, N); 
}

float find_min_dist(plist *points)
{
  lnk n,m;
  int i;
  float weigth;
  /*float mstWeigth;*/ 
  float maxWeigth;
  prepare(points->size);
  
  for(n = points->head, i=1; n != NULL; n=n->next, i++)
  {
    for(m=points->head; m!=NULL;m=m->next)
    {
      if(n==m) continue;
      weigth=distance(n->p,m->p);
      add_edge(gr,n->index,m->index,weigth);
    }
    /*printf("[%d]=(%f,%f)\n",i,n->p.x,n->p.y);*/
    /*insertgrid(g,emst_filter_edges,n->p.x,n->p.y,i);*/
  }
  kruskal(gr,dset,&maxWeigth);
  /*if(mstWeigth==-1)
    printf("Kruskal: O grafo nao era conexo.\n");
  else
    printf("Kruskal: O grafo era conexo!\n");*/
  destroy_graph(gr);
  destroy_dsets(dset);
  return maxWeigth; 
}
