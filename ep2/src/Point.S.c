#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Point.h"

#define DEFAULT_NORM 0.5
extern int DIMENSION;

/* Retorna um float no intervalo [-0.5,0.5] */
/* Lembrando que S e C tem diametro 1 */
float randFloat()
{
  return ((rand()%1000)/1000.0)-0.5;
}

float norma(point x)
{
  float norm;
  int i;
  norm=0;
  for(i=0;i<DIMENSION;i++)
    norm+=(x[i]*x[i]);
  return sqrt(norm);
}  
/*
Como gerar pontos na superficie de uma esfera?
O jeito pensado foi com base na equacao:
  u/||u|| = v/||v||
Dai
  v = u * ||v|| / ||u||
Onde v eh o vetor com norma ||v|| = 1/2.
u eh um vetor (D-upla) de norma ||u||.
*/
point randPoint()
{
  int i;
  float normp;
  point p = malloc(sizeof (float) * DIMENSION);
  /* Geramos um vetor p */
  for(i=0;i<DIMENSION;i++)
    p[i]=randFloat();
  normp = norma(p);
  /* Achamos um vetor p com norma = 1/2 */
  for(i=0;i<DIMENSION;i++)
    p[i]=p[i]*(DEFAULT_NORM/normp);
  /*normp=norma(p);*/
  /*printf("Gerado (esfera): norma = %f",normp); printPoint(p);*/
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
  /*float normp;*/
  r=1;
  p = malloc(sizeof (float) * DIMENSION);
  for(i=0; i<DIMENSION;i++)
    if(scanf("%f",&p[i])!=1)
    {
      r=0;
      break;
    }
  if(r==0) return NULL;
  /*normp=norma(p);
  printf("Lido: norma=%f ",normp); printPoint(p);*/
  return p;	
}

void printPoint(point p)
{
  int i;
  for(i=0;i<DIMENSION;i++)
    printf("%f ",p[i]);
  printf("\n");	
}
