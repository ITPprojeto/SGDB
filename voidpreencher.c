#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insetirintens(int new_line, int qdt_colun, char ***table)
{
  int i;
  int j;

  table = (char***) malloc(50 * sizeof(char **));
    
  for (i = 0; i < new_line; i++)
  {
    table[i] = (char**) malloc(50 * sizeof(char*));
    for (j = 0; j < qdt_colun; j++)
    {
      printf("Pode Digitar a informação do indice [%d][%d]: \n", i, j);
      table[i][j] = (char*) malloc(50 * sizeof(char));
      scanf(" %s", table[i][j]);
      printf("Mostrando informação do indice [%d][%d]\n", i, j);
      printf("%s\n", table[i][j]); 
    }
  }   
}

