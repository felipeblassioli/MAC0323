#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Metadata.h"

char *Meta_toString(Metadata *meta)
{
  char *ret = (char *)malloc(sizeof(char)*256);
  sprintf(ret, "[Text=%s; Lemma=%s]",meta->Text,meta->Lemma);
  return ret;
}

/* Buffer eh uma string da forma: "[Text=xxxx ... Lemma=xxxx" */
Metadata *parseMetadata(char *buffer)
{
  char *lemma, *text;

  Metadata *ret = (Metadata *)malloc(sizeof(*ret));
  /* Text= */
  text=strstr(buffer,"Text");
  sscanf(text+5,"%s",ret->Text);
  /* Lemma= */
  lemma=strstr(buffer,"Lemma");
  lemma+=6;
  strcpy(ret->Lemma,lemma);  
  strcpy(ret->string, buffer);
  return ret;
}
