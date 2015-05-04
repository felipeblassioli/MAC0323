/*
 * This code is from "Algorithms in C, Third Edition,"
 * by Robert Sedgewick, Addison Wesley Longman, 1998.
 */
#ifndef _ST2_H_
#define _ST2_H_
#include "Item2.h"
void ST2init();
 int ST2count();
void ST2insert(Item2);
Item2 ST2search(Key2);
void ST2delete(Key2);
void ST2delete_r(int);
Item2 ST2select(int);
void ST2sort(void (*visit)(Item2));

void ST2draw(); 

void ST2initrand(int);
int ST2randrank();
#endif
