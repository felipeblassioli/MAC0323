#ifndef _SENTENCE_H_
#define _SENTENCE_H_
#define SENTENCE_INIT_SIZE  256
#include "Metadata.h"
typedef struct t_seq
{
  int max_size;
  int index;
  int n_tokens;
  Metadata **annotations;
} Sentence;

void Sentence_init(Sentence *s, int index);
void Sentence_append(Sentence *s, Metadata *meta);
char *Sentence_toString(Sentence *s);
void Sentence_print(Sentence *s, int);
#endif
