#include <stdio.h>
#include <stdlib.h>
#include "plist.h"

/* Leitura dos pontos de STDIN */
void init_plist(plist *buffer)
{
  int N;
  point pt;
  lnk n,m;
  N=1;
  /* List's Head */
  n=malloc(sizeof *n);
  n->p=readPoint(); n->index=N;
  buffer->head=n;
  while((pt = readPoint())!=NULL)
  {
    N++;
    m = malloc(sizeof *m);
    m->p = pt; m->index=N;
    n->next=m;
    n=m;
  }
  buffer->size=N;
}

/* Preenche buffer com pontos aleatorios */
void init_plist_random(plist *buffer, int N, unsigned int seed)
{
  int i;
  lnk n,m;
  srand(seed);
  /* List's Head */
  n=malloc(sizeof *n);
  n->p=randPoint(); n->index=1;
  buffer->head=n;
  /* Remaining points */
  for(i=2; i<=N;i++)
  {
    m=malloc(sizeof *m);
    m->p = randPoint(); m->index=i;
    n->next=m;
    n=m;
    m->next=NULL;
  }
  buffer->size=N;
}
void destroy_plist(plist *buffer)
{
  lnk n;
  int c;
  for(n=buffer->head,c=0;n!=NULL;n=n->next,c++)
    free(n);
  free(buffer);
}
void print_plist(plist *bfr, int size)
{
  int i;
  lnk n = bfr->head;
  for(i=0;i<size;i++)
  {
    printPoint(n->p);
    n = n->next;
  }
}
