#include <stdio.h>
#include <stdlib.h>
//trabalhar com ponteiro da tabela global já que usa 1 tabela por vez?
FILE *open(const char *name, const char *operation){

  FILE *arq = fopen(name, operation);

  if (arq == NULL)
  {
    printf("tabela não encontrada\n");
  }
}

char *create_table(char *table_name){

  int count_colum = 1, qtd_colum;

  printf("Digite a quantidade de colunas:\n");
  scanf(" %d", &qtd_colum);
  char **colunas = malloc(qtd_colum*sizeof(char));


  for (int i = 1; i <= qtd_colum; i++) {
    colunas[i] = malloc(50*sizeof(char));
    printf("Digite o nome da coluna:\n");
    scanf(" %s", colunas[i]);
  }

  return *colunas;
}

// FILE close(){
//   for (int i = 0; i < count; i++) {
//     fclose();
//   }
// }

//free all ponteiros


int main() {

  create_table("teste");

  return 0;
}
