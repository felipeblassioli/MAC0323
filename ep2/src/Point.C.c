#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Point.h"

extern int DIMENSION;

/* Retorna um float no intervalo [-0.5,0.5] */
/* Lembrando que o diametro do cubo eh 1 */
float randFloat()
{
  return ((rand()%1000)/1000.0)-0.5;
}
  
/* retorna um float no intervalo [0,1/sqrt(D)] */
point randPoint()
{
  int i;
  point p = malloc(sizeof (float) * DIMENSION);
  float sqrtD = sqrt(DIMENSION);
  for(i=0;i<DIMENSION;i++)
    p[i]=randFloat()/sqrtD;
  /*printf("Gerado (Cubo): "); printPoint(p);*/
  return p;
}

/* Retorna ||x-y|| */
float distance(point x, point y){
  int i;
  float diff;
  float sum;
  sum=0;
  for(i=0;i<DIMENSION;i++)
  {
    diff=x[i]-y[i];
    sum+=(diff*diff);
  }
  return sqrt(sum);
}

point readPoint()
{
  int i,r;
  point p;
  r=1;
  p = malloc(sizeof (float) * DIMENSION);
  for(i=0; i<DIMENSION;i++)
    if(scanf("%f",&p[i])!=1)
    {
      r=0;
      break;
    }
  if(r==0) return NULL;
  /*printf("Lido: "); printPoint(p);*/
  return p;	
}

void printPoint(point p)
{
  int i;
  for(i=0;i<DIMENSION;i++)
    printf("%f ",p[i]);
  printf("\n");	
}
