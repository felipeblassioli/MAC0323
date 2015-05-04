#include "ep3.h"
/* Percorre T1 ordenadamente */
void printTokens(int onlyWords)
{
  int n = STcount();
  int i;
  Item item;
  printf("n=%d\n",n);
  for(i=0;i<n;i++)
  {
    item = STselect(i);
    if(!onlyWords)
      printf("%s\n",item->word);
    else if(is_word(item->word))
      printf("%s\n",item->word);
  }
}

/* Percorre T2 ordenadamente */
void printLemmas(int printWords)
{
  int n = ST2count();
  int i,j;
  Item2 item;
  printf("Lemmas n=%d\n",n);
  for(i=0;i<n;i++)
  {
    item = ST2select(i);
    /* Todas as palavras do texto em sua versao lematizada */
    if(is_word(item->Lemma))
    {
      printf("%s -> ",item->Lemma);
      /* Imprimir palavras tambem? */
      if(printWords)
        for(j=0;j<item->n_words;j++)
        {
          if(!is_word(item->words[j])) continue;
          printf("[%s] ",item->words[j]);
        }
      printf("\n");
    }
  }
}

void printExact(char *word, int detailLevel)
{
  int i;
  Item item = STsearch(word);
  printf("Printing %s\n",word);
  if(item==NULL)
  {
    printf("Palavra <%s> nao encontrada.\n", word);
  }
  else
  {
    for(i=0;i<item->cur;i++)
      Sentence_print(&sentences[item->indexes[i]], detailLevel);
  }
}

void printAll(char *word, int detailLevel)
{
  int i;
  Item2 item2;
  char *lemma;
  Item item = STsearch(word);
  if(item == NULL)
  {
    printf("Palavra <%s> nao encontrada.\n", word);
  }else
  {
    lemma = item->Lemma;
    item2 = ST2search(lemma);
    for(i=0;i<item2->n_words;i++)
      if(is_word(item2->words[i]))
        printExact(item2->words[i], detailLevel);
  }
}
void printStatistics()
{
  int ntokensd = STcount(); /* chaves sao tokens */
  int nlemasd = ST2count(); /* chaves sao lemmas */
  ntokens += ntokensd; /* Contamos o excesso em storeMeta() */
  nwordsd += nwords; /* Contamos ambos os valores em storeMeta() */
  /* Dados que vieram da leitura */
  printf("Numero de sentencas: %d\n",nsentences);
  printf("Numero total de tokens: %d\n",ntokens);
  /* Fim dos dados que vieram da leitura */
  printf("Numero total de palavras: %d\n",nwords);
  printf("Numero total de tokens distintos: %d\n",ntokensd);
  printf("Numero total de palavras distintas: %d\n", nwordsd);
  printf("Numero todas de lemas distintos: %d\n",nlemasd); 
}
