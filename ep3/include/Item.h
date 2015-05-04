/*
 * This code is from "Algorithms in C, Third Edition,"
 * by Robert Sedgewick, Addison Wesley Longman, 1998.
 */
#include <string.h>
#include <stdio.h>

struct t_item
{
  char Lemma[1024];
  char word[1024];
  int indexes[1024];
  int cur;
};
typedef struct t_item *Item;
typedef char *Key;

#define maxItem 100000

#define NULLitem NULL

Key key(Item);
int eq(Key,Key);
int less(Key,Key);

Item ITEMnew(char *, char *);
void ITEMaddIndex(Item,int);
void ITEMshow(Item);
