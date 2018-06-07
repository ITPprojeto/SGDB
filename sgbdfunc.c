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

void escreverarq(int new_line, int qdt_colun, char *nome, int cont)
{
  FILE *arq;

  arq = fopen("Teste.txt", "a+");

  fprintf(arq, " %s ", nome);

  if (cont == qdt_colun)
  {
    fprintf(arq, "\n");
    cont = 0;
  }

  fclose(arq);
}


char *** insetiritens(int new_line, int qdt_colun, char ***table, char *nome, int cont)
{
  int i;
  int j;

  table = (char***) malloc(50 * sizeof(char **));
      
  for (i = 1; i < new_line + 1; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (j = 1; j < qdt_colun + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      scanf(" %[^\n]%*c", table[i][j]);
      nome = table[i][j];
      escreverarq(new_line, qdt_colun, nome, cont);
      cont++;
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
      escreverarq(new_line, qdt_colun, nome, cont);
      cont++;
    }
  } 
  return table;  
}


void search(int new_line, int qdt_colun, char ***table)
{
  int i;
  int j;
  int tam;
  char pesquisa[100];

  printf("Digite o Dado que deseja pesquisar:\n");
  scanf(" %s", pesquisa);

  for (i = 2; i < new_line + 2; i++)
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


void mostrarcoluna(int qdt_colun, char ***table)
{
  int k;

  for (k = 1; k < qdt_colun + 1; k++)
  {
    printf("Coluna %d = %s\n", k, table[1][k]);
  }
}
