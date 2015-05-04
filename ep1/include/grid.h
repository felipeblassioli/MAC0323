#ifndef GRID_H
#define GRID_H
#include "point.h"
/* Estruturas usadas para range-searching */
typedef void (*pt_do_edge)(int,int,float);
typedef struct t_node *lnk;
struct t_node {
  point p;
  int index;
  lnk next;
};

typedef struct t_grid {
  lnk **cells;
  int rows;
  int cols;
} grid ;

void init_grid(grid *g, int r, int c);
void destroy_grid(grid *g);
void insertgrid(grid *g, pt_do_edge do_edge, float x, float y, int index);
#endif
