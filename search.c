FILE *arq;
int datatype;

printf("Digite o nome da tabela que deseja pesquisar: ")
"%s", tableName;

arq = fopen(tableName, "r");

fscanf("%d", datatype);

printf("Digite seu metodo de pesquisa :\n");

printf("1 - valor maior que o desejado: \n");

if(datatype == 1)
while( fscanf(arq, "%d", &inteiro) != EOF)
{
	if(inteiro > entrada)
	printf("%d\n", inteiro);
}

if(datatype == 2)
while( fscanf(arq, "%f", &flutuante) != EOF)
{
	if(flutuante > entrada)
	printf("%f\n", flutuante);
}

if(datatype == 3)
while( fscanf(arq, "%lf", &duplo) != EOF)
{
	if(duplo > entrada)
	printf("%lf\n", duplo);
}

printf("2 - valor maior ou igual ao valor desejado: \n");

if(datatype == 1)
while( fscanf(arq, "%d", &inteiro) != EOF)
{
	if(inteiro => entrada)
	printf("%d\n", inteiro);
}
if(datatype == 2)
while( fscanf(arq, "%f", &flutuante) != EOF)
{
	if(flutuante => entrada)
	printf("%f\n", flutuante);
}
if(datatype == 3)
while( fscanf(arq, "%lf", &duplo) != EOF)
{
	if(duplo => entrada)
	printf("%lf\n", duplo);
}

printf("3 - valor igual ao informado: \n");

if(datatype == 1)
while( fscanf(arq, "%d", &inteiro) != EOF)
{
	if(inteiro == entrada)
	printf("%d\n", inteiro);
}
if(datatype == 2)
while( fscanf(arq, "%f", &flutuante) != EOF)
{
	if(flutuante == entrada)
	printf("%f\n", flutuante);
}
if(datatype == 3)
while( fscanf(arq, "%lf", &duplo) != EOF)
{
	if(duplo == entrada)
	printf("%lf\n", duplo);
}

printf("4 - valor menor que o informado: \n");

if(datatype == 1)
while( fscanf(arq, "%d", &inteiro) != EOF)
{
	if(inteiro < entrada)
	printf("%d\n", inteiro);
}

if(datatype == 2)
while( fscanf(arq, "%f", &flutuante) != EOF)
{
	if(flutuante < entrada)
	printf("%f\n", flutuante);
}

if(datatype == 3)
while( fscanf(arq, "%lf", &duplo) != EOF)
{
	if(duplo < entrada)
	printf("%lf\n", duplo);
}

printf("5 - valor menor ou igual que o informado: \n");

if(datatype == 1)
while( fscanf(arq, "%d", &inteiro) != EOF)
{
	if(inteiro <= entrada)
	printf("%d\n", inteiro);
}

if(datatype == 2)
while( fscanf(arq, "%f", &flutuante) != EOF)
{
	if(flutuante <= entrada)
	printf("%f\n", flutuante);
}

if(datatype == 3)
while( fscanf(arq, "%lf", &duplo) != EOF)
{
	if(duplo <= entrada)
	printf("%lf\n", duplo);
}
