#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insetirintens(char **table)
{
    //Valores inteiros a gente troca por new_line e qnt_colun no malloc - Vinicius
    //Dentro dos 'for' tambem - Vinicius
    int i;
    int j;
    
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 1; j++ )
        {
            scanf(" %s", &table[i][j]);
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
  
  table =  malloc(100 * sizeof(char));
 
  for (i = 0; i < 1; i++ )
  {
    table[i] =  malloc(100 * sizeof(char));
  }

  //Essa parte de alocar roubei do teu main pra ficar igualzinho - Vinicius
  //Mas basta trocar 100 pelo new_line e qnt_colun - Vinicius
    
  insetirintens(table); //Chamamos o preenchimento
    
  for ( i = 0; i < 1; i++)
  {
   for ( j = 0; j < 1; j++ )
    {
     printf("%s \n", &table[i][j]); 
     //Printamos na tela 
     //Essa parte da para aproveitar na função listagem de itens
    }
  }

  //!!!Tem só algum role troncho que numa 2x2 ele mistura algumas informações - Vinicius
  //A gente podia tirar essa duvida com Erick
    
 return 0;
}
