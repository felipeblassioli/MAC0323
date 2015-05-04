/*
 * Much of this code is adapted from "Algorithms in C, Third Edition,"
 * by Robert Sedgewick, Addison Wesley Longman, 1998, and from
 * Sedgewick's own Java code for left-leaning red-black trees.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Item2.h"

/*
  Constantes
*/
static const char no_externo[] = "\\Tn";
static const char no_interno[] = "\\Tc*{3pt}";
static const char tree_sep[] = "3mm";
static const char level_sep[] = "5mm";

/*
 * Back to Sedgewick stuff
 */

typedef struct ST2node* link;
struct ST2node { Item2 item; link l, r; int N, red; };

static link head, z;

static link NEW(Item2 item, link l, link r, int N, int red)
  { link x = malloc(sizeof *x); 
    x->item = item; x->l = l; x->r = r; x->N = N; x->red = red;
    return x;
  }

void ST2init()
  { head = (z = NEW(NULL2item, 0, 0, 0, 0)); }

int ST2count() { return head->N; }

#define hl  (h->l)
#define hr  (h->r)
#define hrl  (h->r->l)
#define hll  (h->l->l)

static Item2 searchR(link h, Key2 v)
  { Key2 t = key2(h->item);
    if (h == z) return NULL2item;
    if (eq2(v, t)) return h->item;
    if (less2(v, t)) return searchR(hl, v);
             else return searchR(hr, v);
  }
Item2 ST2search(Key2 v) 
  { return searchR(head, v); } 

static link fixNr(link h)
  { h->N = hl->N + hr->N +1;
    return h;
  }

static link rotL(link h)
  { link x = hr; hr = x->l; x->l = fixNr(h); 
    x->red = x->l->red; x->l->red = 1;
    return fixNr(x);
  }

static link rotR(link h)
  { link x = hl; hl = x->r; x->r = fixNr(h);
    x->red = x->r->red; x->r->red = 1;
    return fixNr(x);
  }

static void colorFlip(link h)
  { h->red = 1 - h->red;
    hl->red = 1 - hl->red;
    hr->red = 1 - hr->red;    
  }

static link mvRedL(link h)
{
  colorFlip(h);
  if (hrl->red) { hr = rotR(hr); h = rotL(h); }
  return h;
}

static link mvRedR(link h)
{
  colorFlip(h);
  if (hll->red) { h = rotR(h); }
  return h;
}

static link balance(link h)
{
  if (hr->red) h = rotL(h);
  if (hl->red && hll->red) h = rotR(h);
  if (hl->red && hr->red) colorFlip(h);
  return fixNr(h);
}

/*
 * Insertions
 */

static link LLRBinsert(link h, Item2 item)
  { Key2 v = key2(item);
    /* Insert a new node at the bottom*/
    if (h == z) return NEW(item, z, z, 1, 1);  

    if (less2(v, key2(h->item)))
      hl = LLRBinsert(hl, item); 
    else
      hr = LLRBinsert(hr, item); 
    
    /* Enforce left-leaning condition */
    if (hr->red && !hl->red) h = rotL(h);
    if (hl->red && hll->red) h = rotR(h);
    if (hl->red && hr->red) colorFlip(h);

    return fixNr(h);
  }

void ST2insert(Item2 item)
  { head = LLRBinsert(head, item); head->red = 0; }

/*
 * Select and sort
 */

Item2 selectR(link h, int r)
{
  int t = hl->N;
  if (t > r) return selectR(hl, r);
  if (t < r) return selectR(hr, r-t-1);
  return h->item;
}

Item2 ST2select(int r)
{
  return selectR(head, r);
}

static void sortR(link h, void(*visit)(Item2))
{
  if (h!=z) {
    sortR(hl, visit);
    visit(h->item);
    sortR(hr, visit);
  }
}

void ST2sort(void(*visit)(Item2))
{ sortR(head, visit); }

/*
 * Needed for deletion
 */

Item2 getMin(link h)
{
  if (hl == z) return h->item;
  else return getMin(hl);
}

/*
 * Deletions
 */

static link deleteMin(link h)
{
  if (hl == z) { free(h); return z; }
  if (!hl->red && !hll->red) h = mvRedL(h);
  hl = deleteMin(hl);
  return balance(h);
}

void ST2deleteMin()
{
  if (ST2count() == 0) 
    { printf("Underflow"); exit(1); }

  if (!head->l->red && !head->r->red) head->red = 1;

  head = deleteMin(head);
  if (ST2count() > 0) head->red = 0;
}

static link deleteMax(link h)
{
  if (hl->red) h = rotR(h);
  if (hr == z) { free(h); return z; }
  if (!hr->red && !hrl->red) h = mvRedR(h);
  hr = deleteMax(hr);
  return balance(h);
}

void ST2deleteMax()
{
  if (ST2count() == 0) 
    { printf("Underflow"); exit(1); }

  if (!head->l->red && !head->r->red) head->red = 1;

  head = deleteMax(head);
  if (ST2count() > 0) head->red = 0;
}

static link deleteR(link h, Key2 v)
{
  Key2 t = key2(h->item);
  if (less2(v,t)) {
    if (!hl->red && !hll->red) h = mvRedL(h);
    hl = deleteR(hl, v);
  } else {
    if (hl->red) h = rotR(h);
    if (eq2(v,key2(h->item)) && hr == z)
      { free(h); return z; }
    if (!hr->red && !hrl->red) h = mvRedR(h);
    if (eq2(v,key2(h->item))) {
      h->item = getMin(hr);
      hr = deleteMin(hr);
    } else hr = deleteR(hr, v);
  }
  return balance(h);
}

void ST2delete(Key2 v)
{
  if (!head->l->red && !head->r->red) head->red = 1;
  head = deleteR(head, v);
  if (ST2count() > 0) head->red = 0;
}

/*
 * Integrity check

int size(link h) { return h->N; }
      
int height(link h) 
{ int tl, tr;
  if (h==z) return 0;
  tl = height(hl); 
  tr = height(hr); 
  return 1 + tl > tr ? tl : tr;
}

int ST2height() { return height(head); }

int check()
{
  if (!isBST2()) printf("Fails the property of BST2.\n");
  if (!sizeConsistent()) printf("Fails the size consistency.\n");
  if (!rankConsistent()) printf("Fails the rank consistency.\n");
  if (!is23()) printf("Not a 2-3 tree.\n");
  if (!balanced()) printf("Not balanced.\n");
  return
    isBST2() && sizeConsistent() && rankConsistent()
    && is23() && balanced();
}

 */

/* faz_desenho(): deveria chamar faca_desenho();  
   acho que nao deveria devolver valor nenhum...
*/

static int faz_desenho(link h, int nivel)
{
  int d1, d2;

  if (h->N == 0) {
    printf("%s\n", no_externo);
    return 1;
  }

  if (nivel == 0)
    printf("\\pstree[levelsep=%s, treesep=%s]{%s}{\n", level_sep,
	   tree_sep, no_interno);
  else
    printf("\\pstree{%s}{\n", no_interno);
  d1 = faz_desenho(h->l, nivel+1);
  d2 = faz_desenho(h->r, nivel+1);
  printf("}\n");
  return d1 + d2 + 1;
}

void ST2draw()
{
  printf("\\rput{90}{");
  faz_desenho(head, 0);
  printf("}\n");
}

static void printR(link h, int ind)
{ /*int i;
  if (h != z) {
    for (i=0; i<ind; i++) putchar(' ');
    printf("%d%c\n", key2(h->item), h->red?'*':' ');
    printR(hl, ind+2);
    printR(hr, ind+2);
  }*/
}

void ST2print()
{ printf("\n**** %d key2s ****\n", ST2count());
  printR(head, 0);
  printf("**** ****** ****\n");
}
