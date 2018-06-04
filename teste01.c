#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insetirintens(int new_line, int qdt_colun, char **table)
{
  int i;
  int j;

  table = (char**) malloc(50 * sizeof(char));
    
  for (i = 0; i < qdt_colun; i++)
  {
    table[i] = (char*) malloc(50 * 100 * sizeof(char));
    for (j = 0; j < new_line; j++)
    {
      printf("Pode Digitar a informação do indice [%d][%d]: \n", i, j);
      scanf(" %s", &table[i][j]);
    }
  }   
}

void mostrartabela(int new_line, int qdt_colun, char **table)
{
  int i;
  int j;

  for (i = 0; i < qdt_colun; i++)
  {
   for (j = 0; j < new_line; j++)
    {
     printf("Mostrando informação do indice [%d][%d]\n", i, j);
     printf("%s\n", &table[i][j]); 
    }
  }
}

int main()
{
  char **table;
  int i;
  //new_line
  int j;
  //qnt_colun
  int new_line = 2;
  int qdt_colun = 0;
  int option = 10;

  //table = (char**) malloc(50 * sizeof(char));

  printf("Insira a quantidade de colunas:\n");
  scanf("%d", &qdt_colun);

  //table = (char**) malloc(50 * sizeof(char));
  
  /*printf("Digite a opção:\n");
  scanf(" %d", &option);

  if (option == 1)
  {
    new_line++;
    //qdt_colun++;
    criartabela(new_line, qdt_colun, table);
    criartabela(new_line, qdt_colun, table);
  }


  printf("linha inserida!\n");
  new_line++;
  */
  
  //table =  malloc(100 * sizeof(char));
 
  //for (i = 0; i < 1; i++ )
  //{
    //table[i] =  malloc(100 * sizeof(char));
  //}

  //Essa parte de alocar roubei do teu main pra ficar igualzinho - Vinicius
  //Mas basta trocar 100 pelo new_line e qnt_colun - Vinicius
    
  insetirintens(new_line, qdt_colun , table); //Chamamos o preenchimento
  
  mostrartabela(new_line, qdt_colun , table);

  //!!!Tem só algum role troncho que numa 2x2 ele mistura algumas informações - Vinicius
  //A gente podia tirar essa duvida com Erick
    
 return 0;
}