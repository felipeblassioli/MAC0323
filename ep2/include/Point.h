#ifndef POINT_H
#define POINT_H
/* Um ponto eh um vetor de floats */
typedef float *point;
/* Devolver um ponto gerado uniformemente ao acaso em X */
point randPoint();
float distance(point a, point b);
point readPoint();
void printPoint(point a);
#endif
