#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "plist.h"

/* Parte 1: connected.c */
int find_edges_shorter_than(float dist, plist *points);
/* Parte 2: emst.c */
float find_min_dist(plist *points);

/* Parametros do Programa */
int N,M,r;  
float d;  
int Cflag, Dflag, pflag, vflag, Vflag, Lflag;
unsigned int seed;  
int DIMENSION;

void readParameters(int argc, char *argv[])
{
  int opt;
  /* Default Values */
  M=-1; 
  d=-1; 
  N=-1; 
  vflag=0; 
  Vflag=0; 
  Cflag=0; 
  Dflag=0;
  Lflag=0;
  seed = 123;
  
  /* Parse Params */
  /* getopt() is not ANSI compliant */
  while ((opt = getopt(argc, argv, "N:M:D:d:s:CvVL")) != -1) 
  {
     switch(opt)
     {
       case 'N':
         N = atoi(optarg);
         break;
       case 'M':
         M = atoi(optarg);
         break;
       case 'D':
         DIMENSION = atoi(optarg);
         break;	
       case 'd':
         d = atof(optarg);
         break;
       case 's':
         seed = atoi(optarg);
         break;
       case 'C':
         Cflag = 1;
         break;
       case 'v':
         vflag=1;
         break;
       case 'V':
         vflag=1;
         Vflag=1;
         break;
       case 'L':
         Lflag=1;
         break;
     }
  }
}

/*********************/
/*       Main        */
/*********************/
int main(int argc, char *argv[])
{
  plist *buffer;
  
  /* Set global variables */
  readParameters(argc,argv);    
  
  buffer = malloc(sizeof(plist));    
  /* Parte 1 */
  if(Cflag&&d!=-1)
  {
    /* Leitura de Pontos */
    init_plist(buffer);
    r=find_edges_shorter_than(d,buffer);
    /*printf("r=%d buffer->size=%d\n",r,buffer->size);*/
    if(r==buffer->size-1)
      printf("Conexo!\n");
    else
      printf("Nao conexo!\n");
  }
  else if(N!=-1&&d!=-1)
  {
    /*
     * Para -N100 -d0.1 -v
     * Seu programa deve gerar a lista de pontos aleatorios,
     * verificar se eh conexo e entao exibir a lista de pontos.
     */
    init_plist_random(buffer, N, seed);
    r=find_edges_shorter_than(d,buffer);
    if(r==buffer->size-1)
      printf("Conexo!\n");
    else
      printf("Nao conexo!\n");
    if(vflag) print_plist(buffer,buffer->size);
  }    
  
  /* Parte 2 */
  if(Lflag)
  {
    /* Leitura de Pontos */
    init_plist(buffer);
    d=find_min_dist(buffer);
    /* Limiar de conexidade */
    printf("d* = %f\n",d);
  }
  else if(N!=-1&&M!=-1)
  { 
    int i;
    float s=0;
    free(buffer);
    /*
     * Seu programa deve gerar M instancias aleatorias: p_1, p_2 .. p_M
     * e deve determinar d*(p_i) para todo 1 <= i <= M .
     */
    for(i=0;i<M;i++){
      buffer=malloc(sizeof(plist));
      /* Gera instancia aleatoria p_i */
      init_plist_random(buffer, N, seed+13*i);
      d=find_min_dist(buffer);
      /* d*(p_i) : Limiar de Conexidade para instancia aleatoria p_i */
      if(vflag) printf("d*(p_%d) = %f\n",(i+1),d);
      s+=d;
      if(Vflag) print_plist(buffer,buffer->size);
      destroy_plist(buffer);
    }
    /* media dos d*(p_j) */
    s/=M;
    printf("Limiar de conexidade tipico = %f\n",s);
  }
  exit(EXIT_SUCCESS);
}
