/*
 * This code is from "Algorithms in C, Third Edition,"
 * by Robert Sedgewick, Addison Wesley Longman, 1998.
 */
#ifndef _H_ITEM_
#define _H_ITEM_
#include <stdio.h>
#include <stdlib.h>
#include "Item2.h"

Key2 key2 (Item2 i)
{
  return i->Lemma;
}
int eq2(Key2 a, Key2 b)
{
  return strcmp(a,b) == 0;
}
int less2(Key2 a, Key2 b)
{
  return strcmp(a,b) < 0;
}

Item2 ITEM2new(char *lemma)
{
  Item2 ret = (Item2)malloc(sizeof(*ret));
  ret->n_words=0;
  strcpy(ret->Lemma,lemma);
  return ret;
}

void ITEM2addWord(Item2 x, char *word)
{
  int i;
  int n = x->n_words;
  if(n >= 1024)
  {
    fprintf(stderr,"Overflow de palavras!\n");
    exit(1);
  }
  /* verifica se existe na lista */
  for(i=0;i<n;i++)
  {
    if(strcmp(x->words[i],word) == 0)
      return;
  }
  x->words[n] = (char *)malloc(sizeof(char)*strlen(word));
  if(x->words[n] == NULL){
    fprintf(stderr,"Malloc failed!\n");
    exit(1);
  }
  strcpy(x->words[n],word);
  x->n_words = n+1;
}
void ITEM2show(Item2 x)
{ 
}
#endif
