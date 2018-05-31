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

// FILE close(){
//   for (int i = 0; i < count; i++) {
//     fclose();
//   }
// }


int main() {

  FILE *arq;

  char str[100]= "teste de escrita";

  arq = open("teste500.txt", "w");
  fscanf(arq, "%s", str);
  fprintf(arq, "%s\n", str);
  fprintf(arq, "no início do arquivo!\n");
  fprintf(arq, "%s\n", "teste da função open");

  return 0;
}
