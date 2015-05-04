#include <stdio.h>
#include <stdlib.h>
#include "plist.h"
float randFloat()
{
  return (rand()%1000)/1000.0;
}

void init_plist(plist *buffer)
{
  int N;
  float x,y;
  lnk n,m;
  N=1;
  scanf("%f %f",&x,&y);
  n=malloc(sizeof *n);
  n->p.x=x; n->p.y=y; n->index=N;
  buffer->head=n;
  while(scanf("%f %f",&x,&y)==2)
  {
    N++;
    m = malloc(sizeof *m);
    m->p.x=x; m->p.y=y; m->index=N;
    n->next=m;
    n=m;
  }
  buffer->size=N;
}
void init_plist_random(plist *buffer, int N, unsigned int seed)
{
  int i;
  float x,y;
  lnk n,m;
  srand(seed);
  x=randFloat(); y=randFloat();
  n=malloc(sizeof *n);
  n->p.x=x; n->p.y=y; n->index=1;
  buffer->head=n;
  for(i=2; i<=N;i++)
  {
    x=randFloat(); y=randFloat();
    m=malloc(sizeof *m);
    m->p.x=x; m->p.y=y; m->index=i;
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
    printf("(%f,%f)\n",n->p.x,n->p.y);
    n = n->next;
  }
}
