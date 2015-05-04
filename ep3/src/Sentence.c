#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sentence.h"
void Sentence_init(Sentence *s, int index)
{
  s->max_size = SENTENCE_INIT_SIZE;
  s->annotations = (Metadata **)malloc(sizeof(Metadata *)*SENTENCE_INIT_SIZE);
  s->index = index;
  s->n_tokens = 0;
}
/* Adiciona token em tokens[] */
void Sentence_append(Sentence *s, Metadata *meta)
{
  int m = s->max_size;
  if(m < s->n_tokens)
  {
    m += 40;
    s->annotations = (Metadata **)realloc(s->annotations,sizeof(Metadata *)*m);
    if(s->annotations == NULL)
      fprintf(stderr,"ERROR: realloc failed!\n");
    s->max_size = m;
  }
  m=s->n_tokens;
  s->annotations[m] = meta;
  s->n_tokens = m+1;
}
char *Sentence_toString(Sentence *s)
{
  int i;
  char *buffer = (char *)malloc(sizeof(char)*4056);
  buffer[0]='\0';
  for(i=0;i<s->n_tokens;i++)
    strcat(buffer,s->annotations[i]->Text);
  return buffer;
}
void Sentence_print(Sentence *s, int detailLevel)
{
  int i,n;
  n=s->n_tokens;
  if(detailLevel >= 1)
    printf("Sentence #%d (%d tokens)\n",s->index,s->n_tokens);
  for(i=0;i<n;i++)
    if(i==n-1)
      printf("%s\n",s->annotations[i]->Text);
    else
      printf("%s ",s->annotations[i]->Text);
  if(detailLevel >= 2)
  {
    /* Imprimir annotations de cada token */
    for(i=0;i<n;i++)
      printf("%s] ",s->annotations[i]->string);
    printf("\n");
  }
}
