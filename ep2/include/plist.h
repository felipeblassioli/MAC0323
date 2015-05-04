#ifndef PLIST_H
#define PLIST_H
#include "Point.h"

typedef struct t_node *lnk;
struct t_node {
  point p;
  int index;
  lnk next;
};

typedef struct t_plist plist;
struct t_plist
{
  lnk head;
  int size;  
};

void init_plist(plist *buffer);
void init_plist_random(plist *buffer, int N, unsigned int seed);
void destroy_plist(plist *buffer);
void print_plist(plist *bfr, int size);
#endif
