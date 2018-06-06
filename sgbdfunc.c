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

void showtable(int new_line, int qdt_colun, char ***table, int max, int space)
{
 int i;
 int j;
 int q = 0;

 for (i = 1; i < new_line + 2; i++)
  {
    printf("\n");
    for (j = 1; j < qdt_colun + 1; j++)
    { 
      if (strlen(table[i][j]) < max)
      {
        space = max - strlen(table[i][j]);

        printf("%s", table[i][j]);

        for (q = 0; q < space; q++)
        {
         printf(" ");
        }

        printf("||");
      }
     
      else
      {
      printf("%s||", table[i][j]);
      }
    }
  }
}

char *** insetiritens(int new_line, int qdt_colun, char ***table)
{
  int i;
  int j;

  table = (char***) malloc(50 * sizeof(char **));
    
  for (i = 1; i < new_line + 2; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (j = 1; j < qdt_colun + 1; j++)
    {
      printf("Pode Digitar a informação da indice [%d][%d]: \n", i, j);
      table[i][j] = (char*) malloc(50 * sizeof(char));
      scanf(" %s", table[i][j]);
    }
  } 

  return table;  
}

int tamanho(int new_line, int qdt_colun, char ***table, int maior)
{ 
 int i;
 int j;

 maior = strlen(table[1][1]);

 for (i = 1; i < new_line + 2; i++)
  {
    for (j = 1; j < qdt_colun + 1; j++)
    {
     if(strlen(table[i][j]) > maior)

     maior = strlen(table[i][j]);
    }
  } 
  return maior;
  
  //Essa mede o tamanho da maior string
}
