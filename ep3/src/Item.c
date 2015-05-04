/*
 * This code is from "Algorithms in C, Third Edition,"
 * by Robert Sedgewick, Addison Wesley Longman, 1998.
 */
#ifndef _H_ITEM_
#define _H_ITEM_
#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

Key key (Item i)
{
  return i->word;
}
int eq(Key a, Key b)
{
  return strcmp(a,b) == 0;
}
int less(Key a, Key b)
{
  return strcmp(a,b) < 0;
}

Item ITEMnew(char *word, char *lemma)
{
  Item ret = (Item)malloc(sizeof(*ret));
  ret->cur=0;
  strcpy(ret->Lemma,lemma);
  strcpy(ret->word,word);
  return ret;
}

void ITEMaddIndex(Item x, int index)
{
  int i;
  /* Adiciona indice se ele nao existir */
  for(i=0;i<x->cur;i++)
    if(index == x->indexes[i])
      return;
  x->indexes[x->cur++]=index;
}
void ITEMshow(Item x)
{ 
  int i;
  printf("Lemma: %s Word: %s\n",x->Lemma,x->word);
  printf("Indexes:\n");
  for(i=0;i<x->cur;i++)
    printf("%d ",x->indexes[i]);
  printf("\n");
}
#endif
