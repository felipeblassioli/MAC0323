#ifndef PLIST_H
#define PLIST_H
#include "grid.h" /* lnk */
typedef struct t_plist plist;
struct t_plist
{
  lnk head;
  int size;  
};

float randFloat();
void init_plist(plist *buffer);
void init_plist_random(plist *buffer, int N, unsigned int seed);
void destroy_plist(plist *buffer);
void print_plist(plist *bfr, int size);
#endif
