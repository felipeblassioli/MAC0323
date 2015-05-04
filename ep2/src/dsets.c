#include <stdlib.h>
#include "dsets.h"
void init_dsets(dsets *st, int n)
{
  int i;
  st->size=n;
  st->s = (int *) malloc((n+1)*sizeof(int));
  st->sz = (int *) malloc((n+1)*sizeof(int));
  for(i=0;i<=n;i++)
  {
    st->s[i]=i;
    st->sz[i]=1;
  }
  st->edges=0;
}
void destroy_dsets(dsets *st)
{
  free(st->s);
  free(st->sz);
  free(st);
}
int disj_find(dsets *st, int p)
{
  int i;
  for(i = p ; i != st->s[i]; i = st->s[i]);
    st->s[i]=st->s[st->s[i]];
  return i;
}

void disj_union (dsets *st, int p, int q)
{
  if(st->sz[p] < st->sz[q])
  {
    st->s[p] = q;
    st->sz[q]+=st->sz[p];
  }else{
    st->s[q] = p;
    st->sz[p]+=st->sz[q];
  }
  st->edges++;
}
