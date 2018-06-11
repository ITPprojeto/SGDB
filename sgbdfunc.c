#include <stdio.h>
#include <stdlib.h>
#include "sgdb.h"


void menu(){

    int option;
    printf("selecione uma opção:\n 1.Criar Tabela\n 2.Inserir itens na tabela \n 3.Listar tabela\n" );

    while (option != 6) {
      scanf("%d", &option);

      switch (option)
      {
        case 1:
          insertItens();
          printf ("\n");
        break;

        case 2 :
          insertItensAfterFile();
          printf ("\n");
        break;

        case 3 :
          showTables();
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

void writeFile(char *tableName, int qdt_colun, char *itemTable)
{
  FILE *arq;

  FILE *alltables;
  //ARQUIVO .TABLE E .METADADO (2 arquivos diferentes)
  arq = fopen(tableName, "a+");

  alltables = fopen("alltables.txt", "a+");

  fprintf(arq, " %s ", itemTable);

  fprintf(alltables, "%s\n", tableName);

  /*
  if (cont == qdt_colun)
  {
    fprintf(arq, "\n");
    cont = 0;
  }
  */

  fclose(arq);

  fclose(alltables);
}

char *** insertItens()
{
  int qtd_lines, qtd_colums;
  char ***table, tableName[100];

  table = (char***) malloc(50 * sizeof(char **));

  printf("Digite o nome da tabela:\n");
  scanf("%s", tableName);

  printf("Digite a quantidade de colunas:\n");
  scanf("%d", &qtd_colums);

  printf("Digite a quantidade de itens:\n");
  scanf("%d", &qtd_lines);

  for (int i = 1; i < qtd_lines + 1; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 1; j < qtd_colums + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      scanf(" %[^\n]%*c", table[i][j]);
      writeFile(tableName, qtd_lines, table[i][j]);
    }
  }

  return table;
}

char *** insertItensAfterFile()
{

  char tableName[100], ***table;
  int qtd_lines, qtd_colums, count = 0;

  printf("Digite o nome da tabela:\n");
  scanf("%s", tableName);

  //!!! temporário, será usado um metadado do arquivo para definir a quantidade d ecolunas
  printf("Digite a quantidade de colunas:\n");
  scanf("%d", &qtd_colums);

  printf("Digite a quantidade de itens:\n");
  scanf("%d", &qtd_lines);

  table = (char***) malloc(50 * sizeof(char **));

  for (int i = qtd_lines; i < qtd_lines + 1; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 1; j < qtd_colums + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      scanf(" %s", table[i][j]);
      writeFile(tableName, qtd_colums, table[i][j]);
      count++;
    }
  }
  return table;
}

void showTables()
{
  FILE *alltables;

  char entrada[100];

  alltables = fopen("alltables.txt", "r");

  while (fscanf(alltables, " %s ", entrada) != EOF)
  {
   printf("%s\n", entrada);
  }

  fclose(alltables);
}

int transformTypeData(int new_line, int qdt_colun, char ***table)
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
