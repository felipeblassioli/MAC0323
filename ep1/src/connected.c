/***************************/
/* Parte 1: Implementacoes */
/***************************/
#include <stdlib.h>
#include "plist.h"
#include "dsets.h"
#include "grid.h"

grid *g;
dsets *dset;

float d;
int edges;

void filter_by_dist (int u, int v, float w);

/* Variavel externa: d */
void filter_by_dist (int u, int v, float w)
{
  int r1,r2;
  if(w<d)
  {
    r1=disj_find(dset,u); r2=disj_find(dset,v);
    if(r1!=r2)
    {
      disj_union(dset,r1,r2);
      edges++;
    }
  }
}
int find_edges_shorter_than(float dist, plist *points)
{
  int i;
  lnk n;
  int G=1/dist;
  d=dist;  
  g = malloc(sizeof *g);
  init_grid(g,G,G);
  dset = malloc(sizeof *dset);
  init_dsets(dset,points->size);

  edges=0;
  for(n = points->head, i=1; n != NULL; n=n->next, i++)
  {
    insertgrid(g,filter_by_dist, n->p.x, n->p.y, i);
  }
  free(g);
  free(dset);
  return edges;
}
