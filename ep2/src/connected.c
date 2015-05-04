/***************************/
/* Parte 1: Implementacoes */
/***************************/
#include <stdlib.h>
#include <stdio.h>
#include "plist.h"
#include "dsets.h"

/* Algoritmo N^2 */
/* Retorna um inteiro cujo valor maximo eh points->size-1 */
int find_edges_shorter_than(float dist, plist *points)
{
  int edges;
  int r1,r2;
  lnk n,m; /* Cursores da lista de pontos */
  float weigth;
  dsets *dset;

  dset = malloc(sizeof *dset);
  init_dsets(dset,points->size);

  edges=0;
  for(n=points->head; n!=NULL; n=n->next)
    for(m=points->head; m!=NULL; m=m->next)
    {
      if(n == m) continue;
      weigth=distance(n->p,m->p);
      if(weigth<dist)
      {
        /*printf("x(%d-%d) weigth = %f dist = %f\n",n->index,m->index,weigth,dist);*/
        r1=disj_find(dset,n->index); 
        r2=disj_find(dset,m->index);
        if(r1!=r2)
        {
          /*printf("UNION r1=%d r2=%d weigth=%f\n",r1,r2,weigth);
          printPoint(n->p);
          printPoint(m->p);*/
          disj_union(dset,r1,r2);
          edges++;
          break;
        }
      }
    }
  free(dset);
  return edges;
}
