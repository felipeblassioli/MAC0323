/*
 * This code is from "Algorithms in C, Third Edition,"
 * by Robert Sedgewick, Addison Wesley Longman, 1998.
 */
#include <string.h>
#include <stdio.h>

struct t_item2
{
  char Lemma[1024];
  char *words[1024];
  int n_words;
};
typedef struct t_item2 *Item2;
typedef char *Key2;


#define NULL2item NULL

Key2 key2(Item2);
int eq2(Key2,Key2);
int less2(Key2,Key2);

Item2 ITEM2new(char *);
void ITEM2addWord(Item2,char *);
void ITEM2show(Item2);
