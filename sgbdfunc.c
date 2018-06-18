#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
          search();
          printf ("\n");
        break;

        case 5 :
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

  // fprintf(arq, " %lf ;", itemTable);
  //
  // fprintf(arq, " %d ;", itemTable);
  //
  // fprintf(arq, " %c ;", itemTable);
  //
  fprintf(arq, " %s ;", itemTable);
  //
  // fprintf(arq, " %f ;", itemTable);

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
  FILE *arq;

  table = (char***) malloc(50 * sizeof(char **));

  printf("Digite o nome da tabela:\n");
  scanf("%s", tableName);

  arq = fopen(tableName, "w");

  printf("Digite a quantidade de colunas:\n");
  scanf("%d", &qtd_colums);
  fprintf(arq, "%d\n", qtd_colums);
  fclose(arq);

  printf("Digite a quantidade de entradas de dados:\n");
  scanf("%d", &qtd_lines);

  for (int i = 0; i < 1; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 1; j < qtd_colums + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      if (i == 00) {
        printf("Digite a chave primária da tabela: [%d] e o seu tipo: ", j);
      }else{
        printf("Digite o nome da coluna: [%d] e o seu tipo: ", j);
      }
      scanf(" %[^\n]%*c", table[i][j]);
      writeFile(tableName, qtd_lines, table[i][j]);
    }
  }

  for (int i = 1; i < qtd_lines + 1; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 1; j < qtd_colums + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      printf("Digite a informação da coluna [%s]: ", table[0][j]);
      scanf(" %[^\n]%*c", table[i][j]);
      writeFile(tableName, qtd_lines, table[i][j]);
    }
  }

  printf("selecione uma opção:\n 1.Criar Tabela\n 2.Inserir itens na tabela \n 3.Listar tabela\n4.Deletar item da tabela\n5.Deletar tabela\n" );
  return table;
}

char *** insertItensAfterFile()
{

  char tableName[100], ***table;
  int qtd_lines, qtd_colums, count = 0;
  FILE *arq;

  printf("Digite o nome da tabela:\n");
  scanf("%s", tableName);
  arq = fopen(tableName, "r");

  fscanf(arq, "%d", &qtd_colums);
  fclose(arq);

  printf("Digite a quantidade de itens:\n");
  scanf("%d", &qtd_lines);

  table = (char***) malloc(50 * sizeof(char **));

  for (int i = 1; i < qtd_lines + 1; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 1; j < qtd_colums + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      //printf("Digite a informação da coluna [%s]: ", table[0][j]);
      scanf(" %[^\n]%*c", table[i][j]);
      writeFile(tableName, qtd_colums, table[i][j]);
      count++;
    }
  }
  printf("selecione uma opção:\n 1.Criar Tabela\n 2.Inserir itens na tabela \n 3.Listar tabela\n4.Deletar item da tabela\n5.Deletar tabela\n" );
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

  printf("selecione uma opção:\n 1.Criar Tabela\n 2.Inserir itens na tabela \n 3.Listar tabela\n4.Deletar item da tabela\n5.Deletar tabela\n" );
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
  printf("selecione uma opção:\n 1.Criar Tabela\n 2.Inserir itens na tabela \n 3.Listar tabela\n4.Deletar item da tabela\n5.Deletar tabela\n" );
}

// void deleteItemTable(char tableName){
//   writeFile(tableName);
// }

void search()
{
  FILE *arq;

  char search[100], nameFile[100], string[100];

  printf("Digite o nome da tabela que deseja pesquisar\n");
  scanf(" %s", nameFile);

  arq = fopen(nameFile, "r");

  printf("Digite o Dado que deseja pesquisar:\n");
  scanf(" %s", search);

  while( fscanf(arq, "%s", string) != EOF)
  {
   if( strncmp(search, string, strlen(search)) == 0)
   {
    printf("Foi encontrado : %s\n", string);
   }
  }

  fclose(arq);
  printf("selecione uma opção:\n 1.Criar Tabela\n 2.Inserir itens na tabela \n 3.Listar tabela\n4.Deletar item da tabela\n5.Deletar tabela\n" );
}

char fileToMatrix(char tableName){
  //converter taberla pra matriz
  //receber
  //rescrever arquivo pulando a linha
  //receber quantidade de linhas e colunas
  //primeir linha do arquivo linhaxxoluna
  for (size_t i = 0; i < count; i++) {
    for (size_t i = 0; i < count; i++) {
      /* code */
    }
  }
}


int checkPrimarykey(){
  if(exist){
    return 0;
  }else{
    return 1;
  }
}
