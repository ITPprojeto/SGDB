
#include <stdio.h>
#include <stdlib.h>
#include "sgdb.h"
int main() {
  char ***table;
  int qdt_lines = 1;
  int qdt_colun = 0;
  char nome[100];
  int entrada = 0;
  int cont = 1;
  int i, j;


  printf("Insira a quantidade de colunas: \n");
  scanf("%d", &qdt_colun);

  //printf("Digite a quantidade de dados a ser inserida: \n");
  //scanf("%d", &qdt_lines);

  table = insetiritens(qdt_lines, qdt_colun , table); 
  
  printf("Deseja insetir itens? \n");
  scanf("%d", &entrada);

  while (entrada != 0)
  {
  table = insetiritensposteriori(qdt_lines, qdt_colun, table, nome, cont);
  qdt_lines++;
  printf("Deseja insetir itens? \n");
  scanf("%d", &entrada);
  }

  return 0;
}
