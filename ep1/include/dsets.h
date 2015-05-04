#ifndef DSETS_H
#define DSETS_H
typedef struct
{
  int edges;
  int *sz;
  int *s;
  int size;
} dsets;

void init_dsets(dsets *st, int n);
void destroy_dsets(dsets *st);
int disj_find(dsets *st, int p);
void disj_union (dsets *st, int p, int q);
#endif
