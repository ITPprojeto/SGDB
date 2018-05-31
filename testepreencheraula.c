#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void retorno(int *linhafinal, int *colunafinal)
{
  int linha = 1;
  int coluna = 1;
  char entrada = 'n';	

  printf("Deseja inserir novos dados? y/n \n");

  scanf("%c", &entrada);

  if (entrada == 'y')
  {
  	(*linhafinal)++;
  	(*colunafinal)++;
  }

  //colunafinal = &coluna;
 // linhafinal = &linha;

  printf("%d %d\n", *colunafinal, *linhafinal);
}

int main()
{   
	int linha = 1;
	int coluna = 1;
    int *linhafinal = &linha;
    int *colunafinal = &coluna;

    retorno(linhafinal, colunafinal);

    printf("%d %d\n", *linhafinal, *colunafinal);

    char testando[*linhafinal][*colunafinal][100];
    int i;
    int j;

    for (i = 0; i < *colunafinal; i++)
    {
    	for (j = 0; j < *linhafinal; j++)
    	{
    		scanf(" %s", &testando[i][j][100]);
    	}
    }

    for (i = 0; i < *colunafinal; i++)
    {
    	for (j = 0; j < *linhafinal; j++)
    	{
    		printf("%s\n", &testando[i][j][100]);
    	}
    }
 
	return 0;
}