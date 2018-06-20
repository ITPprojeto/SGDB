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
          printf("teste\n");
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

        case 6:
          deleteItemTable();
          printf ("\n");
        break;



        default:
          printf ("Valor inválido!\n");
      }
    }
}

void writeFile(char *tableName, char *itemTable, char *operation)
{
  char path[255];
  FILE *arq, *allTables;

  strcpy(path, "tables/");
  strcat(path, tableName);

  arq = fopen(path, operation);

  allTables = fopen("allTables.txt", "a+");

  fprintf(arq, " %s ", itemTable);

  fprintf(allTables, "%s\n", tableName);

  fclose(arq);
  fclose(allTables);
}

void  insertItens()
{
  int qtd_lines, qtd_colums;
  char ***table, tableName[100], qtdLinesStr[100], qtdColumnsStr[100];

  table = (char***) malloc(50 * sizeof(char **));

  printf("Digite o nome da tabela:\n");
  scanf("%s", tableName);

  //if create pra evitar duas funções de inserir boolean e identificar exitencia da tabela
  printf("Digite a quantidade de colunas e a quantidade de itens:\n");
  scanf("%s %s", qtdLinesStr, qtdColumnsStr);

  writeFile(tableName, qtdLinesStr, "a+");
  writeFile(tableName, qtdColumnsStr, "a+");
  writeFile(tableName, "\r\n", "a+");

  qtd_lines = atoi(qtdLinesStr);
  qtd_colums = atoi(qtdColumnsStr);

  for (int i = 0; i < qtd_lines; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 0; j < qtd_colums; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
        //fprintf(arq, "%d %d\n", qtd_colums, qtd_lines);
        //writeFile(tableName, qtd_lines, table[i][j]);
        if (i == 0) {
          printf("Digite o nome da coluna:\n");
        }else{
          printf("Digite um item da tabela:\n");
        }

      scanf(" %s", table[i][j]);
      //USAR FGETS NOMES COMPOSTOS (PROBLEMA /N)
      //fgets(table[i][j], 100, stdin);

      if (j == qtd_colums - 1)
      {
        strcat(table[i][j], "\r\n");
      }

      writeFile(tableName, table[i][j], "a+");
    }
  }
  menu();
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
  printf("selecione uma opção:\n 1.Criar Tabela\n 2.Inserir itens na tabela \n 3.Listar tabela\n4.Deletar item da tabela\n5.Deletar tabela\n" );
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

void deleteItemTable(){
  char tableName[100], pk[100], ***table;
  int *metaData, lines, columns, index;
  FILE *arq;

  printf("Digite o nome da tabela\n");
  scanf("%s", tableName);


  metaData = tableMetadata(tableName);
  lines = metaData[0];
  columns = metaData[1];

  printf("Digite a PK do item que deseja excluir\n");
  scanf("%s", pk);

  table = fileToMatrix("tables/alunos");

  //isola a coluna das chaves primarias e confere
  for (int i = 1; i < lines; i++) {
    if(strcmp(pk, table[i][0]) == 0)
    {
      index = i;
    }
  }

  arq =   fopen("tables/professores", "w");

  //subsititui valores anteriores da matriz pelo proximo
  for (int i = 0; i < lines-1; i++) {
    for (int j = 0; j < columns; j++) {
      if (i == index) {
        fprintf(arq, "%s\n", table[i+1][j]);
      }else{
        fprintf(arq, "%s\n", table[i][j]);
      }
    }
    fprintf(arq, "%s\n", "\r\n");
  }
  fclose(arq);
}

char ***fileToMatrix(char *tableName){

  int qtd_lines, qtd_columns;
  char content[100], ***table, fileContent[256], path[256];
  FILE *arq;

  // strcpy(path, "tables/");
  // strcat(path, tableName);

  arq = fopen(tableName, "r");
  fscanf(arq, "%d %d", &qtd_columns, &qtd_lines);

  table = (char***) malloc(50 * sizeof(char **));

  for(int i = 0; i < qtd_lines; i++ ){
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 0; j < qtd_columns; j++) {
      fscanf(arq, "%s", fileContent);
      table[i][j] = (char*) malloc(50 * sizeof(char));
      strcpy(table[i][j], fileContent);
    }
  }

  fclose(arq);

  return table;
}

int *tableMetadata(char *tableName){
  char path[255];
  strcpy(path, "tables/");
  strcat(path, tableName);

  FILE *arq;
  int *qtdLineCol, qtd_columns, qtd_lines;

  arq = fopen(path, "r");
  qtdLineCol = malloc(1 * sizeof(int));
  fscanf(arq, "%d %d", &qtd_columns, &qtd_lines);

  qtdLineCol[0] = qtd_lines;
  qtdLineCol[1] = qtd_columns;

  fclose(arq);

  return qtdLineCol;
}


int checkPrimarykey(){
  // if(exist){
  //   return 0;
  // }else{
  //   return 1;
  // }
}
