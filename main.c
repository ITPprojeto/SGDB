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

char create_table(char *table_name){

  int count_colum = 1;
  char *colunas = (char*) malloc(count_colum*sizeof(char)), option = 's';

  while(option != 'n'){

    if (option == 's') {
      //alocar colunas
      //número do item * 50 (tamanho max string patra evittar realloc(): invalid next size)
      colunas = realloc(colunas, count_colum*50*sizeof(char));
      printf("Digite o nome da coluna:\n");
      scanf(" %s", &colunas[count_colum]);
      printf("coluna inserida!\n");
      printf("Adicionar nova coluna? (s/n)\n");
      scanf(" %s", &option);
      count_colum++;
    }else{
      printf("Digite um valor válido!\n");
      scanf(" %s", &option);
    }

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

  create_table("tabela-teste");

  return 0;
}
