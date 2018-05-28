#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int m, n;
    int i, j;

    printf("Digite a quantidade de linhas e coluna:\n");
    
    scanf("%d %d", &m, &n);

    //FILE *teste;

    char table [m][n][100];

    for (i = 0; i < m; ++i)
    {
      for (j = 0; j < n; j++)
      {
        fgets(table[i][j], 100, stdin); 
      }
    }


    //teste = fopen("teste.txt", "w");

    printf ("Os dados que voce digitou foram: \n");
    //fprintf (teste, "Os dados que voce digitou foram: \n");
    
    for (i = 0; i < m; i++)
    {
      for (j = 0; j < n; j++)
       {
         printf ("%s\n", table[i][j]);
         //fprintf (teste, "%s\n", table[cont]);
       }
    } 

    //fclose(teste);
    
    return 0;
}
    //Ver como vai ficar a função create table(Vinicius)
    

    /*Vai ser uma "matriz 3" pq uma do string e as duas da tabela
    toda vida que o user concluir o preenchimento das info "lateralmente"
    a gente muda o para as proximas informações tabeladas*/
     
    /*Não sei se devemos tirar o '\n' da string 
    por que com ele fica mais facil de vizualizar 
    o arquivo mas no terminal fica meio feio (vinicius)*/ 
