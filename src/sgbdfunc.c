#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/sgdb.h"


void menu()
{  
    printf("---------------- Banco de Dados ----------------\n");
    printf("---------------- ITP/PTP 2018.1 ----------------\n");
    printf("          Feito por Moises & Vinicius\n");
    printf("\n");

    int option = 0;
    printf("selecione uma opção:\n1.Criar Tabela\n2.Inserir itens na tabela\n3.Listar tabelas\n4.Mostrar dados da tabela\n5.Pesquisar na tabela\n6.Deletar item da Tabela\n7.Deletar Tabela\n" );

    while (option <  9) {
      printf("teste loop\n");
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
          showAllTables();
          printf ("\n");
        break;

        case 4 :
          showTables();
          printf ("\n");
        break;

        case 5 :
          search();
          printf ("\n");
        break;

        case 6 :
          deleteItemTable();
          printf ("\n");
        break;

        case 7:
          deleteTable();
          printf ("\n");
        break;

        default:
          printf ("Valor inválido!\n");
      }
    }

    printf("Encerrando programa!\n");
}

void showAllTables()
{
  FILE *arq;
  char table[200];

  arq = fopen("allTables.txt", "r");

  printf("\n");

  printf("Tabelas:\n");

  while (fscanf(arq, " %s", table) != EOF) 
  {
  printf("%s\n", table);
  }
}

void writeFile(char *tableName, char *itemTable, char *operation)
{
  
  FILE *arq, *allTables;


  arq = fopen(tableName, operation);

  fprintf(arq, " %s ", itemTable);

  fclose(arq);
}


void insertItens()
{
  int qtd_lines, qtd_colums, n, dataType[n];
  char ***table, tableName[100];
  FILE *arq, *allTables;

  table = (char***) malloc(50 * sizeof(char **));

  printf("Digite o nome da tabela:\n");
  scanf("%s", tableName);
  

  allTables = fopen("allTables.txt", "a+");
  fprintf(allTables, "%s\n", tableName);
  fclose(allTables);

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

  char tableName[100], ***table;
  int qtd_lines, qtd_colums, count = 0, pk, portugal;
  FILE *arq;

  printf("Digite o nome da tabela:\n");
  scanf("%s", tableName);

  if(arq == NULL)
  {
    printf("Esse arquivo não existe\n");
    menu();
  }

  arq = fopen(tableName, "r");
  char linha[100];
  fscanf(arq, "%d %d", &qtd_colums, &portugal);
  fclose( arq );

  printf("Digite a quantidade de itens:\n");
  scanf("%d", &qtd_lines);
  printf("%d\n", qtd_lines);
  arq = fopen( tableName, "r+" ); 


  fseek(arq, 2, SEEK_SET);
  fprintf(arq, "%d ", portugal + qtd_lines);
  fclose(arq);

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

void deleteTable()
{
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
  int qtd_lines, qtd_columns, searchColum, inteiro, dataType[qtd_columns], option;
  float flutuante;
  double duplo;
  char content[100], ***table, fileContent[256], tableName[100], searchitem[100];
  FILE *arq;

  
  printf("Digite o nome do arquivo que deseja pesquisar: ");
  scanf(" %[^\n]%*c", tableName);

  if(arq == NULL)
  {
    printf("Esse arquivo não existe\n");
    menu();
  }
  
  arq = fopen(tableName, "r");

  if(arq == NULL){
    printf("Esse arquivo não existe\n");
  }

  fscanf(arq, "%d %d", &qtd_columns, &qtd_lines);

  for(int j = 0; j < qtd_columns ; j++)
  {
    fscanf(arq, "%d", &dataType[j]);
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
      printf("%d %s\n", j, table[i][j]);
    }
  }

  printf("Digite a coluna que deseja pesquisar: ");
  scanf("%d", &searchColum);

  
  printf("Digite como deseja fazer sua busca :\n");
  printf("1 - valor maior que o desejado: \n");
  printf("2 - valor maior ou igual ao valor desejado: \n");
  printf("3 - valor igual ao informado: \n");
  printf("4 - valor menor que o informado: \n");
  printf("5 - valor menor ou igual que o informado: \n");
  printf("6 - pesquisar palavras: \n");
  scanf("%d", &option);
 
  printf("Digite o dado que deseja pesquisar:\n");
  scanf(" %[^\n]%*c", searchitem);

 if (option == 1)
 {
    if (dataType[searchColum] == 1)
    { 
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if(atoi(table[i][j]) > atoi(searchitem))
          printf("É maior que o dado pesquisado: %d\n", atoi(table[i][j]));
        }
      }
    }
    
    if (dataType[searchColum] == 2)
    {
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if(atof(table[i][j]) > atof(searchitem))
          printf("É maior que o dado pesquisado: %0.2f\n", atof(table[i][j]));
        }
      }
    }
      
    if(dataType[searchColum] == 3)
    {
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if (atof(searchitem) > atof(table[i][j]))
          printf("É maior que o dado pesquisado: %f\n", atof(table[i][j]));
        }
      }
    }
  }

 if (option == 2)
 {
    if (dataType[searchColum] == 1)
    { 
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if(atoi(table[i][j]) >= atoi(searchitem))
          printf("É maior ou igual ao dado pesquisado: %d\n", atoi(table[i][j]));
        }
      }
    }
    
    if (dataType[searchColum] == 2)
    {
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if(atof(table[i][j]) >= atof(searchitem))
          printf("É maior ou igual ao dado pesquisado: %0.2f\n", atof(table[i][j]));
        }
      }
    }
      
    if(dataType[searchColum] == 3)
    {
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if (atof(searchitem) >= atof(table[i][j]))
          printf("É maior ou igual ao dado pesquisado: %f\n", atof(table[i][j]));
        }
      }
    }
  }

 if (option == 3)
 {
    if (dataType[searchColum] == 1)
    { 
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if(atoi(table[i][j]) == atoi(searchitem))
          printf("É igual ao dado pesquisado: %d\n", atoi(table[i][j]));
        }
      }
    }
    
    if (dataType[searchColum] == 2)
    {
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if(atof(table[i][j]) == atof(searchitem))
          printf("É igual ao dado pesquisado: %0.2f\n", atof(table[i][j]));
        }
      }
    }
      
    if(dataType[searchColum] == 3)
    {
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if (atof(searchitem) == atof(table[i][j]))
          printf("É igual ao dado pesquisado: %f\n", atof(table[i][j]));
        }
      }
    }
  }

 if (option == 4)
 {
    if (dataType[searchColum] == 1)
    { 
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if(atoi(table[i][j]) < atoi(searchitem))
          printf("É menor que o  dado pesquisado: %d\n", atoi(table[i][j]));
        }
      }
    }
    
    if (dataType[searchColum] == 2)
    {
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if(atof(table[i][j]) < atof(searchitem))
          printf("É menor que dado pesquisado: %0.2f\n", atof(table[i][j]));
        }
      }
    }
      
    if(dataType[searchColum] == 3)
    {
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if (atof(searchitem) < atof(table[i][j]))
          printf("É menor que o dado pesquisado: %f\n", atof(table[i][j]));
        }
      }
    }
  } 

  if (option == 5)
 {
    if (dataType[searchColum] == 1)
    { 
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if(atoi(table[i][j]) <= atoi(searchitem))
          printf("É menor ou igual ao dado pesquisado: %d\n", atoi(table[i][j]));
        }
      }
    }
    
    if (dataType[searchColum] == 2)
    {
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if(atof(table[i][j]) <= atof(searchitem))
          printf("É menor ou igual ao dado pesquisado: %0.2f\n", atof(table[i][j]));
        }
      }
    }
      
    if(dataType[searchColum] == 3)
    {
      for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if (atof(searchitem) <= atof(table[i][j]))
          printf("É menor ou igual ao dado pesquisado: %f\n", atof(table[i][j]));
        }
      }
    }
  }

  if (option == 6)
  {
    for(int i = 1; i < qtd_lines ; i++ )
      { 
        for (int j = searchColum; j < searchColum + 1; j++) 
        {
          if (strcmp(table[i][j], searchitem) == 0)
          printf("Foi Encontrado: %s\n", table[i][j]);
        }
      }
  }

  fclose(arq);
  free(table);
  menu();
}

void showTables()
{

  char tableName[100], string[100];
  int maxSizeint, pular, cont = 0, space  , q, lixo[pular + 1];
  FILE *arq;

  printf("Digite o nome da tabela que deseja ver: ");
  scanf(" %s", tableName);

  if(arq == NULL)
  {
    printf("Esse arquivo não existe\n");
    menu();
  }

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

  for(int j = 0; j < pular + 1 ; j++)
  {
    fscanf(arq, "%d", &lixo[j]);
  }

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

void deleteItemTable()
{
  char tableName[100], pk[100], ***table, fileContent[255];
  int *metaData, lines, columns, index, lixo[columns], pular;
  FILE *arq;

  printf("Digite o nome da tabela: \n");
  scanf(" %s",tableName);

  arq = fopen(tableName, "r");

  fscanf(arq, "%d", &columns);

  fscanf(arq, "%d", &lines);

  for(int j = 0; j < columns-1; j++)
  {
    fscanf(arq, "%d", &lixo[j]);
  }

  printf("Digite o nome do item que deseja excluir: \n");
  scanf("%s", pk);

  for(int i = 0; i < lines; i++ )
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (int j = 0; j < columns; j++) 
    {
      fscanf(arq, "%s", fileContent);
      table[i][j] = (char*) malloc(50 * sizeof(char));
      strcpy(table[i][j], fileContent);
    }
  }
  
  for(int i = 0; i < lines; i++ )
  {
    for (int j = 0; j < columns; j++) 
    {
      if (strcmp(table[i][j],pk) == 0)
      {
        table[i][j] = "";
      }
    }
  }

  for(int i = 0; i < lines; i++ )
  {
    for (int j = 0; j < columns; j++) 
    {
      table[i][j];
      writeFile(tableName, table[i][j], "w");
    }
  }
}

char ***fileToMatrix(char *tableName)
{

  int qtd_lines, qtd_columns;
  char content[100], ***table, fileContent[256];
  FILE *arq;

  arq = fopen(tableName, "r");

  if(arq == NULL)
  {
    printf("Esse arquivo não existe\n");
    menu();
  }

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

int *tableMetadata(char *tableName)
{

  FILE *arq;
  int *qtdLineCol, qtd_columns, qtd_lines;

  arq = fopen(tableName, "r");

  if(arq == NULL)
  {
    printf("Esse arquivo não existe\n");
    menu();
  }

  qtdLineCol = malloc(1 * sizeof(int));
  fscanf(arq, "%d %d", &qtd_columns, &qtd_lines);

  qtdLineCol[0] = qtd_lines;
  qtdLineCol[1] = qtd_columns;

  fclose(arq);

  return qtdLineCol;
}
