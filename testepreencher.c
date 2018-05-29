#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int retorno(int *linhafinal, int *colunafinal)
{
  int linha = 1;
  int coluna = 2;
  int entrada = 0;  

  printf("Deseja inserir novos dados? y/n \n");

  scanf("%d", &entrada);

  if (entrada == 1)
  {
    (*linhafinal)++;
    //(*colunafinal)++;
    linhafinal = malloc(sizeof(int) * *linhafinal);
  }

  if (entrada == 2)
  {
    printf("Tudo bem, encerrando o codigo\n");
  }

  return entrada;
}

int main()
{   
  int cont = 0;
  int linha = 1;
  int coluna = 2;
    int *linhafinal = &linha;
    int *colunafinal = &coluna;


    printf("Quantidade de Linhas: %d Quantidade de Colunas: %d\n", *linhafinal, *colunafinal);

    char testando[*colunafinal][*linhafinal][100];
    int i;
    int j;
    
    for (i = 0; i < *linhafinal; i++)
    {
      linhafinal = malloc(sizeof(int) * *linhafinal);
      printf("Valor de linhafinal: %d\n", *linhafinal);
      for (j = 0; j < *colunafinal; j++)
      {
        printf("Indice [%d] [%d]\n", i, j);
        scanf(" %s", &testando[i][j][100]);
      }
    }

    if (retorno(linhafinal, colunafinal) == 1)
    {
      printf("Valor de linhafinal: %d\n", *linhafinal);
      //printf("linhafinal: %d colunafinal: %d \n", *linhafinal, *colunafinal);
      for (i = *linhafinal; i < *linhafinal+1; i++)
        {
         for (j = 0; j < *colunafinal; j++)
         {
           printf("Indice: [%d] [%d]\n", i, j);
         scanf(" %s", &testando[i][j][100]);
         }
      }
    }

    linhafinal = malloc(sizeof(int) * *linhafinal);
    printf("Valor de linhafinal: %d\n", *linhafinal);

    //Porque *linhafinal perder seu valor???
    //Ajeitando isso a gente completa as funções de preencher
    
    /*
    for (i = 0; i < 2; i++)
    {
      for (j = 0; j < *colunafinal; j++)
      {
        printf("Indice: [%d] [%d]\n", i, j);
        printf("%s \n", &testando[i][j][100]);
      }
    }
    */
  return 0;
}