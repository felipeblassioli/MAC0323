#include "ep3.h"
#define LINE_SIZE 4056

FILE *fin;
char line[LINE_SIZE];

/* Uma palavra eh um token constituido de letras */
int is_word(char *token)
{
  int i;
  int len = strlen(token);
  for(i=0;i<len;i++)
    if(token[i] < 'A' || token[i] > 'z')
    { 
      return 0; 
    }
  return 1;
}

void storeMeta(int senIndex, Metadata *meta)
{
  Key2 k2; 
  Key k;
  Item2 val2;
  Item val;
  k = meta->Text;
  /* T1 begin: Chaves sao tokens */ 
  val = STsearch(k);
  if(val == NULL)
  {
    val = ITEMnew(meta->Text, meta->Lemma);
    if(is_word(k))
      nwordsd++; /* O token eh uma palavra */
  }
  else
  {
    /* Contagem com repeticao */
    /* Palavra ja existente */
    ntokens++;
    if(is_word(k))
      nwords++;
    STdelete(k);
  }
  ITEMaddIndex(val, senIndex);
  STinsert(val);
  /* T1 end */  
  
  /* T2 begin */
  k2 = meta->Lemma;
  val2 = ST2search(k2);
  if(val2 == NULL)
    val2 = ITEM2new(meta->Lemma);
  else
    ST2delete(k2);
  ITEM2addWord(val2, meta->Text);
  ST2insert(val2);
  /* T2 end */
  Sentence_append(&sentences[senIndex], meta);
}
/*
* Faz a leitura do arquivo devolvido pelo coreNPL.
* O arquivo eh composto por blocos:
*
* Sequence #%d (%d tokens)\n
* ----------- Seq ----------\n
* ----------- Seq ----------\n
* ----------- Seq ----------\n
* [metadata token_1] ... [metadata token_N]\n
*/
void readFile(char *fname)
{
  int c,sentence,tokens;
  char buffer[4056];
  Metadata *meta;
  fin = fopen(fname,"r");
  while(fgets(line, LINE_SIZE, fin)!=NULL)
  {
    sscanf(line, "Sentence #%d (%d tokens)", &sentence,&tokens);

    Sentence_init(&sentences[sentence], sentence);
    /* Ler linhas que precedem a linha de metadata */
    do
    {
      fscanf(fin,"%[^[]",buffer);
      fscanf(fin,"%s",buffer);
      /* Must begin with [text */
    } while(strstr(buffer,"[Text=")==NULL);

    /* ************** */
    /* Parse Metadata */
    /* ************** */
    /* Ja foi lida [Text=XXXX */
    /* Temos de reconstruir/concatenar a string ja lida */
    /* depois ler a parte que falta */
    strcpy(line,buffer);
    fscanf(fin,"%[^]]",buffer);
    strcat(line,buffer);
    meta = parseMetadata(line);
    fgetc(fin); fgetc(fin); /* ] e espaco */
    storeMeta(sentence,meta);

    for(c=2;c<=tokens;c++)
    {
      fscanf(fin,"%[^]]",buffer);
      meta = parseMetadata(buffer);
      fgetc(fin); fgetc(fin); /* ] e espaco */
      storeMeta(sentence,meta);
    }
    fgetc(fin); /* new line */
  
    nsentences++;
  }
  fclose(fin);
}

void init()
{
  STinit(); 
  ST2init();
  nwords=0;
  nwordsd=0;
  ntokens=0;
  nsentences=0;
}
