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
          //mostrartabela();
          printf ("\n");
        break;

        case 5 :
          deleteTable();

          printf ("\n");
        break;

        case 6 :
          printf ("\n");

        default:
          printf ("Valor inválido!\n");
      }
    }
}

void writeFile(char *tableName, int qdt_colun, char *itemTable)
{ 
  FILE *arq;

  arq = fopen(tableName, "a+");

  fprintf(arq, " %s ", itemTable);

  fclose(arq);
}

void writeFilefloat(char *tableName, char *itemTable)
{ 
  FILE *arq;

  arq = fopen(tableName, "a+");

  fprintf(arq, "%f ", atof(itemTable));

  fclose(arq);
}

char *** insertItens()
{
  int qtd_lines, qtd_colums, n, dataType[n];
  char ***table, tableName[100];
  FILE *arq;
  
  table = (char***) malloc(50 * sizeof(char **));

  printf("Digite o nome da tabela:\n");
  scanf("%s", tableName);

  arq = fopen(tableName, "w");

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
        printf("Digite o tipo de variavel da coluna [%d] ", j);
      }
      else if (i == 1)
      {
        printf("Digite o nome da coluna: [%d] ", j);
      }
      else
      {
      printf("Digite o item da tabela da coluna [%s]", table[1][j]);
      }
      scanf("%s", table[i][j]); //Esse seria o array das variaveis
      writeFile(tableName, qtd_lines, table[i][j]);
    }
  }
  menu();
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

void mostrartabela()
{
  char tableName[100], string[100];
  int maxSizeint, pular, cont = 0, space  , q;
  FILE *arq;

  printf("Digite o nome da tabela que deseja ver: ");
  scanf(" %s", tableName);

  arq = fopen(tableName, "r");

  maxSizeint = 0;

  while( fscanf(arq, "%s", string) != EOF)
  {
    if (strlen(string) > maxSizeint)
    {
      maxSizeint = strlen(string);
    }
  }

  fclose(arq);

  fopen(tableName, "r");

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