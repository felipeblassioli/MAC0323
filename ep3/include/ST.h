/*
 * This code is from "Algorithms in C, Third Edition,"
 * by Robert Sedgewick, Addison Wesley Longman, 1998.
 */
#ifndef _ST_H_
#define _ST_H_
#include "Item.h"
void STinit();
 int STcount();
void STinsert(Item);
Item STsearch(Key);
void STdelete(Key);
void STdelete_r(int);
Item STselect(int);
void STsort(void (*visit)(Item));

void STdraw(); 

void STinitrand(int);
int STrandrank();
#endif
