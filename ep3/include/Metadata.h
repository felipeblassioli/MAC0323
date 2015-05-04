#ifndef _METADATA_H_
#define _METADATA_H_
typedef struct t_meta
{
  char Text[256]; /* token */
  char Lemma[256];
  char string[1024]; /* tudo */
} Metadata;

char *Meta_toString(Metadata *meta);
Metadata *parseMetadata(char *buffer);
#endif
