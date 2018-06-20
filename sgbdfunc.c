#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sgdb.h"


void menu()
{

    int option;
    printf("selecione uma opção:\n 1.Criar Tabela\n 2.Inserir itens na tabela \n 3.Listar tabela\n4.Deletar item da tabela\n5.Deletar tabela\n" );

    while (option != 7) {
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
          //mostrartabela();
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

        case 7 :
          printf ("\n");
        break;

        default:
          printf ("Valor inválido!\n");
      }
    }

    printf("Encerrando programa!\n");
}
void writeFile(char *tableName, char *itemTable, char *operation)
{
  
  char path[255];
  FILE *arq, *allTables;


  strcpy(path, "tables/");
  strcat(path, tableName);


  arq = fopen(path, operation);

  allTables = fopen("allTables.txt", "a+");
  //if strcmp fscanf tableName retornar resultado não quantida

  fprintf(arq, " %s ", itemTable);

  fprintf(allTables, "%s\n", tableName);

  fclose(arq);
  fclose(allTables);
}


void insertItens()
{
  int qtd_lines, qtd_colums, n, dataType[n];
  char ***table, tableName[100], path[255];
  FILE *arq;

  table = (char***) malloc(50 * sizeof(char **));

  printf("Digite o nome da tabela:\n");
  scanf("%s", tableName);

  strcpy(path, "tables/");
  strcat(path, tableName);

  arq = fopen(path, "w");

  printf("Digite a quantidade de colunas:\n");
  scanf("%d", &qtd_colums);
  fprintf(arq, "%d ", qtd_colums);
  n = qtd_colums;

  printf("Digite a quantidade de entradas de dados:\n");
  scanf("%d", &qtd_lines);
  fprintf(arq, "%d\n", qtd_lines);
  fclose(arq);

  for (int i = 0; i < qtd_lines + 2; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 1; j < qtd_colums + 1; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      if (i == 0)
      {
        printf("1 - Int / 2 - Double / 3 - Float / 4 - String\n");
        printf("Digite o tipo de variavel da coluna [%d] :", j);
      }
      else if (i == 1)
      {
        printf("Digite o nome da coluna %d : ", j);
      }
      else
      {
      printf("Digite o item da tabela da coluna [%s]: ", table[1][j]);
      }
      scanf("%s", table[i][j]); //Esse seria o array das variaveis
      writeFile(tableName, table[i][j], "a+");
    }
  }
  menu();
}

char *** insertItensAfterFile()
{

  char tableName[100], ***table, path[255];;
  int qtd_lines, qtd_colums, count = 0, pk;
  FILE *arq;

  printf("Digite o nome da tabela:\n");
  scanf("%s", tableName);

  strcpy(path, "tables/");
  strcat(path, tableName);

  arq = fopen(path, "r");

  fscanf(arq, "%d", &qtd_colums);
  fclose(arq);

  printf("Digite a quantidade de itens:\n");
  scanf("%d", &qtd_lines);

  fseek(arq, 1, SEEK_SET);
  fprintf(arq, "%d\n", qtd_lines);

  table = (char***) malloc(50 * sizeof(char **));

  for (int i = 0; i < qtd_lines; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 0; j < qtd_colums; j++)
    {
      table[i][j] = (char*) malloc(50 * sizeof(char));
      printf("Digite a informação da coluna [%s]: ", table[0][j]);
      scanf(" %[^\n]%*c", table[i][j]);

      writeFile(tableName, table[i][j], "a+");
    }
  }

  menu();
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
  menu();
}

void search()
{
  int qtd_lines, qtd_columns, searchColum, searchitem, inteiro, dataType[qtd_columns];
  float flutuante;
  double duplo;
  char content[100], ***table, fileContent[256], tableName[100];
  FILE *arq;

  printf("Digite o nome do arquivo que deseja pesquisar: ");
  scanf(" %[^\n]%*c", tableName);
  printf("%s\n", tableName);
  arq = fopen(tableName, "r");

  if(arq == NULL){
    printf("Esse arquivo não existe\n");
  }

  fscanf(arq, "%d %d", &qtd_columns, &qtd_lines);

  for(int j = 1; j < qtd_columns + 1; j++)
  {
    fscanf(arq, "%d", &dataType[j]);
    printf("indice de data : %d\n", dataType[j]);
  }

  table = (char***) malloc(50 * sizeof(char **));

  for(int i = 0; i < qtd_lines; i++ )
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 0; j < qtd_columns; j++)
    {
      fscanf(arq, "%s", fileContent);
      table[i][j] = (char*) malloc(50 * sizeof(char));
      strcpy(table[i][j], fileContent);
    }
  }

  printf("Digite o indice da coluna que deseja pesquisar: \n");
  for(int i = 0; i < 1; i++ )
  {
    for (int j = 0; j < qtd_columns; j++)
    {
      printf("%d %s\n", j+1, table[i][j]);
    }
  }

  printf("Digite a coluna que deseja pesquisar: ");
  scanf("%d", &searchColum);

  printf("Digite o dado que deseja pesquisar:\n");
  scanf("%d", &searchitem);

  for(int i = 1; i < qtd_lines  ; i++ ){
    for (int j = searchColum; j < searchColum + 1; j++)
    {
      if (atoi(table[i][j]) == searchitem)
      {
      printf("%d\n",atoi(table[i][j]));
      }
    }
  }
 fclose(arq);
 free(table);
}
void showTables()
{

  char tableName[100], string[100], path[255];
  int maxSizeint, pular, cont = 0, space  , q;
  FILE *arq;

  printf("Digite o nome da tabela que deseja ver: ");
  scanf(" %s", tableName);

  strcpy(path, "tables/");
  strcat(path, tableName);

  arq = fopen(path, "r");

  maxSizeint = 0;

  while( fscanf(arq, "%s", string) != EOF)
  {
    if (strlen(string) > maxSizeint)
    {
      maxSizeint = strlen(string);
    }
  }

  fclose(arq);

  fopen(path, "r");

  fscanf(arq, "%d", &pular);

  while( fscanf(arq, "%s", string) != EOF)
  {
    if (strlen(string) > maxSizeint)
    {
      maxSizeint = strlen(string);
    }

    cont++;

    if (strlen(string) < maxSizeint)
    {
      space = maxSizeint - strlen(string);

      printf("%s", string);

      for (q = 0; q < space; q++)
      {
       printf(" ");
      }
      printf("||");

      if (cont == pular)
      {
      printf("\n");
      cont = 0;
      }
    }

    else
    {
      printf("%s||", string);

      if (cont == pular)
      {
        printf("\n");
        cont = 0;
      }
    }
  }

  fclose(arq);
  menu();
}
void deleteItemTable(){
  char tableName[100], pk[100], ***table, path[255];
  int *metaData, lines, columns, index;
  FILE *arq;

  printf("Digite o nome da tabela\n");
  scanf("%s", tableName);


  metaData = tableMetadata(tableName);
  lines = metaData[1];
  columns = metaData[0];

  table = fileToMatrix(path);

  //isola a coluna das chaves primarias e confere
  for (int i = 1; i < lines; i++) {
    if(strcmp(pk, table[i][0]) == 0)
    {
      index = i;
    }
  }

  arq = fopen(path, "w");
  fprintf(arq, "%d %d\n", lines-1, columns);
  //subsititui valores anteriores da matriz pelo proximo

  for (int i = 0; i < lines - 1; i++) {
    for (int j = 0; j < columns; j++) {
      if (i >= index) {
        fprintf(arq, "%s ", table[i+1][j]);
      }else{
        fprintf(arq, "%s ", table[i][j]);
      }
    }
    fprintf(arq, "%s\n", "");
  }
  fclose(arq);
  menu();
}
char ***fileToMatrix(char *tableName){

  int qtd_lines, qtd_columns;
  char content[100], ***table, fileContent[256], path[256];
  FILE *arq;

  strcpy(path, "tables/");
  strcat(path, tableName);

  arq = fopen(path, "r");
  fscanf(arq, "%d %d",  &qtd_lines, &qtd_columns);

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
