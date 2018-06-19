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
          fileToMatrix("alunos");
        break;

        default:
          printf ("Valor inválido!\n");
      }
    }
}

void writeFile(char *tableName, char *itemTable)
{
  char path[255];
  FILE *arq, *allTables;

  strcpy(path, "tables/");
  strcat(path, tableName);

  arq = fopen(path, "a+");

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

  writeFile(tableName, qtdLinesStr);
  writeFile(tableName, qtdColumnsStr);
  writeFile(tableName, "\r\n");

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

      writeFile(tableName, table[i][j]);
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

void deleteItem(){
  printf("DIgite o nome da tabela\n");
  printf("Digite a PK do item que deseja excluir\n");
  for (size_t i = 0; i < numcol; i++) {
    if(table[i][0] == deleteItem)
    {
      indice = i;
    }
  }

  for (size_t i = indice; i < qtd_line; i++) {
    for (size_t j = 0; j < count; j++) {
      table[i][j] = table[i+1][j+1];
    }
  }
}

char ***fileToMatrix(char *tableName){
  int qtd_lines, qtd_columns;
  char content[100], ***table, fileContent[256];
  FILE *arq;

  arq = fopen("tables/alunos", "r");
  fscanf(arq, "%d %d", &qtd_columns, &qtd_lines);

  table = (char***) malloc(50 * sizeof(char **));

  // while (fscanf(arq, "%s", fileContent) != EOF) {
  //
  // }

  for(int i = 0; i < qtd_lines; i++ ){
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 0; j < qtd_columns; j++) {
      fscanf(arq, "%s", fileContent);
      table[i][j] = (char*) malloc(50 * sizeof(char));
      table[i][j] = fileContent;
      printf("%s\n", table[i][j]);
    }
  }

  fclose(arq);
  return table;
}


int checkPrimarykey(){
  // if(exist){
  //   return 0;
  // }else{
  //   return 1;
  // }
}
