#include <stdio.h>
#include <stdlib.h>
#include "sgdb.h"

void escreverarq(int qdt_colun, char *itemtabela)
{
  FILE *arq;

  arq = fopen("Teste.txt", "a+");

  fprintf(arq, " %s ", itemtabela);

  /*
  if (cont == qdt_colun)
  {
    fprintf(arq, "\n");
    cont = 0;
  }
  */

  fclose(arq);
}


char *** insetiritens(int qdt_lines, int qdt_colun, char ***table)
{
  int i;
  int j;

  table = (char***) malloc(50 * sizeof(char **));

  for (i = 1; i < qdt_lines + 1; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (j = 1; j < qdt_colun + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      scanf(" %[^\n]%*c", table[i][j]);
      escreverarq(qdt_lines, table[i][j]);
    }
  }

  return table;
}

char *** insetiritensposteriori(int new_line, int qdt_colun, char ***table, char *nome, int cont)
{
  int i;
  int j;

  table = (char***) malloc(50 * sizeof(char **));

  for (i = new_line; i < new_line + 1; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (j = 1; j < qdt_colun + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      scanf(" %s", table[i][j]);
      nome = table[i][j];
      escreverarq(qdt_colun, table[i][j]);
      cont++;
    }
  }
  return table;
}

int transformar(int new_line, int qdt_colun, char ***table)
{
  int i, j;

  for (i = 1; i < new_line + 1; i++)
  {
   for (j = 1; j < qdt_colun + 1; j++)
   {
    table[i][j] = realloc(table[i][j], 50 * sizeof(int));
    *table[i][j] = atoi(table[i][j]);
   }
  }

  return *table;
}
