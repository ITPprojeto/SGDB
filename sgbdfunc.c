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

void insertItems(char **table)
{
    //Valores inteiros a gente troca por new_line e qnt_colun no malloc - Vinicius
    //Dentro dos 'for' tambem - Vinicius
    int i;
    int j;

    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 1; j++ )
        {
            scanf(" %s", &table[i][j]);
        }
    }
}
