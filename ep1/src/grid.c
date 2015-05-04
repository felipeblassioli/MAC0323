#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
void init_grid(grid *g, int r, int c)
{
  int i,j;
  g->rows=r; g->cols=c;
  g->cells = malloc (sizeof(lnk*)*(r+3));
  /* Alocamos memoria com 2 espacos extras,
   * para evitar overflow.
   * Assim se rows=2 e cols=3
   * Serao validos:
   * cells[2][3], tanto como cells[0][3], cells[0][0]...
   */
  for(i=0; i<=r+2; i++)
  {
    g->cells[i] = malloc(sizeof(lnk*)*(c+3));
    for(j=0; j<=c+2;j++)
      g->cells[i][j]=NULL;      
  }
}
void destroy_grid(grid *g)
{
  int i,j;
  lnk n;
  for(i=0;i<=g->rows+2;i++)
  {
    for(j=0;j<g->cols+2;j++)
      for(n=g->cells[i][j];n!=NULL;n=n->next)
        free(n);
    free(g->cells[i]);
  }

  free(g);
}
void insertgrid(grid *g, pt_do_edge do_edge, float x, float y, int index)
{
  float weight;
  int X,Y,i,j;
  lnk n;
  lnk m = malloc(sizeof *m);
  if(m==NULL)
  {
    fprintf(stderr, "Malloc falhou em insertgrid.\n");
    exit(1);
  }
  X=x*g->rows+1; Y=y*g->cols+1;
  m->p.x = x; m->p.y = y; m->index = index;
  for(i=X-1; i<=X+1; i++)
    for(j=Y-1; j<=Y+1; j++)
      for(n=g->cells[i][j]; n!=NULL; n=n->next){
        weight = distance(n->p, m->p);
        do_edge(n->index, m->index, weight);
      }
  m->next=g->cells[X][Y];
  g->cells[X][Y]=m;
}
