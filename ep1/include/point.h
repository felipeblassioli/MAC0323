#ifndef POINT_H
#define POINT_H
typedef struct t_point point;
struct t_point {
  float x; 
  float y;
};

float distance(point a, point b);
#endif
