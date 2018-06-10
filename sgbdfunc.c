#include <stdio.h>
#include <stdlib.h>
#include "sgdb.h"


void menu(){

    int option;
    printf("selecione uma opção:\n 1.Criar Tabela\n 2.Listar tabela\n" );

    while (option != 6) {
      scanf("%d", &option);

      switch (option)
      {
        case 1:
          insertItens();
          //writeFile();
        break;

        case 2 :
          printf ("\n");
        break;

        case 3 :
          printf ("\n");
        break;

        case 4 :
          printf ("\n");
        break;

        case 5 :
          printf ("\n");
        break;

        default:
          printf ("Valor inválido!\n");
      }
    }
}

void writeFile(int qdt_colun, char *itemtabela)
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


char *** insertItens()
{
  int qtd_lines, qtd_colums;
  char ***table = (char***) malloc(50 * sizeof(char **));

  printf("Digite a quantidade de linhas:\n");
  scanf("%d", &qtd_lines);
  printf("Digite a quantidade de colunas:\n");
  scanf("%d", &qtd_colums);


  for (int i = 1; i < qtd_lines + 1; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 1; j < qtd_colums + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      scanf(" %[^\n]%*c", table[i][j]);
      writeFile(qtd_lines, table[i][j]);
    }
  }

  return table;
}

char *** insertItensAfterFile(int new_line, int qdt_colun, char ***table, char *nome, int cont)
{

  table = (char***) malloc(50 * sizeof(char **));

  for (int i = new_line; i < new_line + 1; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 1; j < qdt_colun + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      scanf(" %s", table[i][j]);
      nome = table[i][j];
      writeFile(qdt_colun, table[i][j]);
      cont++;
    }
  }
  return table;
}

int transform(int new_line, int qdt_colun, char ***table)
{

  for (int i = 1; i < new_line + 1; i++)
  {
   for (int j = 1; j < qdt_colun + 1; j++)
   {
    table[i][j] = realloc(table[i][j], 50 * sizeof(int));
    *table[i][j] = atoi(table[i][j]);
   }
  }

  //return *table;
}
