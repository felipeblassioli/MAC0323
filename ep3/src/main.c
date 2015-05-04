#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ep3.h"

int main(int argc, char **argv){
  int flags[256];
  char *fname;
  char opt[10], buffer[256];
  int i;
  if(argc==2)
  {
    fname = strstr(argv[1],"-f");
    fname += 2;

    init();
    readFile(fname);

    while(1)
    {
      memset(flags,0,sizeof(int)*256);
      buffer[0]='\0';
      printf("Instrucoes da forma -<opcoes> <palavra>\n");
      scanf("%s",opt);
      for(i=1;i<strlen(opt);i++)
      {
        flags[(int)opt[i]]=1;
        switch(opt[i])
        {
          case 'e':
            scanf("%s",buffer);
            break; 
          case 'a':
            scanf("%s",buffer);
            break;
          /* Todos os tokens */
          case 't':
            printTokens(0);
            break;
          /* Todas as palavras */
          case 'd':
            printTokens(1);
            break;
          /* Todos os lemmas */
          case 'l':
            printLemmas(0);
            break;
          /* Todas as palavras e lemmas */
          case 'L':
            printLemmas(1);
            break;
          /* estatisticas */
          case 's':
            printStatistics();
            break;
        }
      }
      if(flags['e'])
      {
        if(flags['V'])
          printExact(buffer,2);
        else if(flags['v'])
          printExact(buffer,1);
        else
          printExact(buffer,0);
      }
      else if(flags['a'])
      {
        if(flags['V'])
          printAll(buffer,2);
        else if(flags['v'])
          printAll(buffer,1);
        else
          printAll(buffer,0);
      }
      else if(flags['F'])
        break;
    }
  } 
  else
  {
    printf("Uso: ./ep3 -f<NOME_ARQUIVO>. Exm: ./ep3 -fmanifesto.txt.out\n");
  }
  return 0;
}
