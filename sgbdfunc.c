#include <stdio.h>
#include <stdlib.h>
#include "sgdb.h"


void menu(){

    int option;
    printf("selecione uma opção:\n 1.Criar Tabela\n 2.Inserir itens na tabela \n 3.Listar tabela\n4.Deletar item da tabela\n5.Deletar tabela\n" );

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

          search();

          deleteTable();

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

  FILE *allTables;
  //ARQUIVO .TABLE E .METADADO (2 arquivos diferentes)
  arq = fopen(tableName, "a+");

  allTables = fopen("allTables.txt", "a+");

  fprintf(arq, " %s ", itemTable);
  
  /*
  if(arq == NULL){
    printf("Tabela não encontrada!\n");
  }else{
    fprintf(arq, " %s ", itemTable);
  }
  */

  fprintf(allTables, "%s\n", tableName);

  /*
  if (cont == qdt_colun)
  {
    fprintf(arq, "\n");
    cont = 0;
  }
  */

  fclose(arq);

  fclose(allTables);
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

  for (int i = 1; i < qtd_lines + 1; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 1; j < qtd_colums + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      scanf(" %[^\n]%*c", table[i][j]);
      writeFile(tableName, qtd_colums, table[i][j]);
      count++;
    }
  }
  return table;
}

void showTables()
{
  FILE *allTables;

  char entrada[100];

  allTables = fopen("allTables.txt", "r");

  while (fscanf(allTables, " %s ", entrada) != EOF)
  {
   printf("%s\n", entrada);
  }

  fclose(allTables);
}

int transformTypeData(int qtd_lines, int qtd_colums, char ***table)
{

  for (int i = 1; i < qtd_lines + 1; i++)
  {
   for (int j = 1; j < qtd_colums + 1; j++)
   {
    table[i][j] = realloc(table[i][j], 50 * sizeof(int));
    *table[i][j] = atoi(table[i][j]);
   }
  }

  //return *table;
}

void deleteTable(){
  int status;
  char tableName[100];

  printf("Digite o nome da tabela:\n");
  scanf(" %s", tableName);

  status = remove(tableName);

  if (status == 0) {
    printf("Tabela removida com sucesso!\n");
  }else{
    printf("Erro ao deletar a tabela.\n");
  }
}

void search()
{
  FILE *arq;

  char search[100], nameFile[100], string[100];

  printf("Digite o nome da tabela que deseja pesquisar\n");
  scanf(" %s", nameFile);
  
  arq = fopen(nameFile, "r");

  printf("Digite o Dado que deseja pesquisar:\n");
  scanf(" %s", search);

  while( fscanf(arq, " %s ", string) != EOF)
  {
    if (string == search)
    {
      printf("%s\n", search);
    }
  }

  fclose(arq);
}