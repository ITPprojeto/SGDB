#include <stdlib.h>
#include <stdio.h>

void writeFile(int qdt_colun, char *itemtabela)
{
  FILE *arq;

  arq = fopen("Teste.txt", "a+");

  fprintf(arq, " %s ", itemtabela);

  /*
  if (cont == qdt_colun)
  {
    fprintf(arq, "\n");
    cont = 0;
  }
  */

  fclose(arq);
}

void menu(){
    printf("selecione uma opção\n" );
    /* ________________
    | Lista de opções: |
    | option1          |
    | option1          |
    | option1          |
    | option1          |
    | option1          |
    |________________  |
    */
    while (valor != 'fim') {
      switch ( valor )
      {
        case 1 :
        printf ("\n");
        break;

        case 2 :
        printf ("\n");
        break;

        case 3 :
        printf ("\n");
        break;

        case 4 :
        printf ("\n");
        break;

        case 5 :
        printf ("\n");
        break;

        default :
        printf ("Valor invalido!\n");
      }
    }
}
