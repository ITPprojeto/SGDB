#include <stdio.h>
#include <stdlib.h>
#include "sgdb.h"

FILE *open(const char *name, const char *operation){

  FILE *arq = fopen(name, operation);

  if (arq == NULL)
  {
    printf("!!! Tabela não encontrada !!!\n");
  }
}

char *create_table(char *table_name){

  int count_colum = 1, qtd_colum;

  printf("Digite a quantidade de colunas:\n");
  scanf(" %d", &qtd_colum);
  char **colums = malloc(qtd_colum*sizeof(char));
  colums[0] =  table_name;

  for (int i = 1; i <= qtd_colum; i++) {
    colums[i] = malloc(50*sizeof(char));
    printf("Digite o nome da coluna:\n");
    scanf(" %s", colums[i]);
  }

  printf("%d colunas inseridas em %s\n", qtd_colum, &table_name);

  return *colums;
}


void showTable(char **table)
{
  int i;
  //new_line
  int j;
  //qnt_collun

  for ( i = 0; i < 1; i++)
  {
   for ( j = 0; j < 1; j++ )
    {
     printf("%s \n", &table[i][j]);
    }
  }
}

char *** insetiritens(int new_line, int qdt_colun, char ***table)
{
  int i;
  int j;

  table = (char***) malloc(50 * sizeof(char **));
    
  for (i = 0; i < new_line; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (j = 0; j < qdt_colun; j++)
    {
      printf("Pode Digitar a informação do indice [%d][%d]: \n", i, j);
      table[i][j] = (char*) malloc(50 * sizeof(char));
      scanf(" %s", table[i][j]);
    }
  } 

  return table;  
}
