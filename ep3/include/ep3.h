#ifndef _EP3_
#define _EP3_
#include "Sentence.h"
#include "Metadata.h"
#include "ST.h"
#include "ST2.h"
#define INITIAL_LIST_SIZE 2056

/* utils.c */
int is_word(char *token);
void storeMeta(int senIndex, Metadata *meta);
void readFile(char *fname);
/* print.c */
void printStatistics();
void printAll(char *word, int detailLevel);
void printExact(char *word, int detailLevel);
void printLemmas(int printWords);
void printTokens(int onlyWords);
void init();

Sentence sentences[INITIAL_LIST_SIZE];
int nwords, nwordsd, ntokens, nsentences;
#endif