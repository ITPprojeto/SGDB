//UMA FUNÇÃO FAZ 1 COISA
FILE open(char file, char operation){
  FILE *arq = fopen(name, "r");
  if (arq == NULL)
  {
    FILE *table = fopen(name, "w");
    return table;
    //posso dar fclose fora daqui?
    //fechar todos os arquvivos na main()? ou em cada função?
  }
  else
  {
    return printf("A tabela já exite, selecione outra operação\n");
  }
}

FILE create_table(char *table_name){
  //verificar exitytência da tabela, se não criar nova
  //while para inserir quantidade (quase) inifita de intens
  printf("Insira a quantidade de colunas:\n", );
  scanf("%d", qtd_colum);
  //(*char) cast é necessário?
  char **table = (*char) malloc(qtd_colum*sizeof(char));
  int new_line = 0;
  //(*char) cast é necessário?
  while(option != "n"){
    //digitar sim ou dar enter
    printf("Adicionar item? (s/n)\n");
    scanf("%s\n", option);
      //aumentar quantidade de linhas
    **table = realloc(table, new_line*sizeof(char));
      //ler valor de coluna a coluna
      //definir tipo de valor? tudo vai ser str?
      //usar os 2 laços pra ajudar na alocação das colunas
    for (int i = new_line; i < new_line; i++) {
      //alocar novas colunas da linha nova
      table[i] = malloc(qtd_colum*sizeof(char));
      for (int j = 0; j < qtd_colum; j++) {
        if (new_line == 0) {
          printf("Digite o nome da coluna:\n");
        }else{
          //imprimi a coluna atual da linha que está sendo inserida
          printf("%s:\n", table[0][j]);
        }
        scanf("%s", table[j][i]);
      }
    }
    printf("linha inserida!\n");
    new_line++;
  }
  //table - linha 0 são os nomes das colunas e as outras linhas dados
  //table[colunas, dados]
  return table;
}

chhar inserir_itens(){
  //atenção campo é obrigatório
  //se ' ' então valor igual a NULL
  //valor da coluna precisa ser único!
  //receber a4ray de valores, inserir em uma linha formatado
  //inserir linha igual a dados/quantidade_colunas
  //ultima linha total items, total de colunas
}

FILE editar_tabela(){

}

void pesquisar(){

}

void listar(){

}

void menu(){
    printf("selecione uma opção\n", );
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
        printf ("Domingo\n");
        break;

        case 2 :
        printf ("Segunda\n");
        break;

        case 3 :
        printf ("Terça\n");
        break;

        case 4 :
        printf ("Quarta\n");
        break;

        case 5 :
        printf ("Quinta\n");
        break;

        default :
        printf ("Valor invalido!\n");
      }
    }
}

int selecionar_operacao(){

}

int main() {

  return 0;
}
