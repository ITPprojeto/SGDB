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
void createFile(int new_line, int qdt_colun, char ***table, int max, int space, char *nome)
{
  int i, j, q;

  FILE *arquivo;

  arquivo = fopen("nome.txt", "w");

  fprintf(arquivo, "%s\n", nome);

  for (i = 1; i < new_line + 2; i++)
  {
    fprintf(arquivo, "\n");
    for (j = 1; j < qdt_colun + 1; j++)
    {
      if (strlen(table[i][j]) < max)
      {
        space = max - strlen(table[i][j]);

        fprintf(arquivo, "%s", table[i][j]);

        for (q = 0; q < space; q++)
        {
         fprintf(arquivo, " ");
        }

        fprintf(arquivo, "||" );
      }

      else
      {
      fprintf(arquivo, "%s||", table[i][j]);
      }
    }
  }

}
//Vinicius

void showTable(int new_line, int qdt_colun, char ***table, int max, int space)
{
 int i, j, q = 0;

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

char *** insertItens(int new_line, int qdt_colun, char ***table)
{
  int i, j;

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

int maxSizeStr(int new_line, int qdt_colun, char ***table, int maior)
{
 int i, j;

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

void search(int new_line, int qdt_colun, char ***table)
{
  int i, j, tam;
  char pesquisa[100];

  printf("Digite o Dado que deseja pesquisar:\n");
  scanf(" %s", pesquisa);

  for (i = 1; i < new_line + 2; i++)
  {
    for (j = 1; j < qdt_colun + 1; j++)
    {
      tam = strncmp(pesquisa, table[i][j], strlen(pesquisa));

      if(tam == 0)
      {
      printf("Ta na Posição [%d][%d]\n", i, j);
      }
    }
  }
}


void showColum(int qdt_colun, char ***table)
{
  int k;

  for (k = 1; k < qdt_colun + 1; k++)
  {
    printf("Coluna %d = %s\n", k, table[1][k]);
  }
}
