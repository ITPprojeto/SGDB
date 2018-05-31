#include<stdio.h>
#include<stdlib.h>

FILE *open(char *name, char operation){

  FILE *arq = fopen(name, "r");

  if (arq == NULL)
  {
    FILE *table = fopen(name, "w");
    return table;
  }
  else
  {
    printf("A tabela já existe, selecione outra operação\n");

    return NULL;
  }
}

char create_table(char *table_name){
  int qtd_colum = 0;
  char option;

  printf("Insira a quantidade de colunas:\n");
  scanf("%d", &qtd_colum);
  char **table = malloc(qtd_colum*sizeof(char));
  int new_line = 0;
  while(option != 'n'){
    printf("Adicionar item? (s/n)\n");
    scanf("%s", &option);
    table = realloc(table, new_line*sizeof(char));
    for (int i = new_line; i <= new_line; i++) {
      table[new_line] = malloc(qtd_colum*sizeof(char));
      for (int j = 0; j < qtd_colum; j++) {
        if (new_line == 0) {
          printf("Digite o nome da coluna:\n");
        }else{
          printf("%s:\n", table[0][j]);
        }
        scanf("%s", table[j][i]);
      }
    }
    printf("linha inserida!\n");
    new_line++;
  }
  return table;
}

int main() {

  return 0;
}
