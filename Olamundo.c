#include <stdio.h>//biblioteca de comunicação com o usuario
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>// biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsavel por cuidar das string

int registro()

{
	setlocale(LC_ALL, "portuguese");
    char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];

    printf("Digite o CPF a ser cadastrado:");
	scanf("%s" , cpf);
	
	strcpy(arquivo,cpf); // responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo para o banco de dados
	file = fopen (arquivo , "w");
	fprintf (file,cpf); // salva o valor do arquivo variavel
	fclose (file); //fecha o arquivo
	
	file = fopen(arquivo ,"a");
	fprintf (file ,",");
	fclose (file);
	
	printf("digite o nome a ser cadastrado:");
	scanf ("%s" , nome);
	file = fopen (arquivo , "a");
	fprintf (file, nome);
	fclose (file);
	
	file = fopen (arquivo , "a");
	fprintf (file, ",");
	fclose (file);
	
	printf("digite o sobrenome a ser cadastrado:");
	scanf ("%s" , sobrenome);
	
	file = fopen (arquivo , "a");
	fprintf (file, sobrenome);
	fclose (file);
	
	file = fopen (arquivo , "a");
	fprintf (file, ",");
	fclose (file);
	
	printf("digite o cargo a ser cadastrado:");
	scanf ("%s" , sobrenome);
	
	file = fopen (arquivo , "a");
	fprintf (file, cargo);
	fclose (file);
	
	file = fopen (arquivo , "a");
	fprintf (file, ",");
	fclose (file);
	
	system ("pause");
		
}

int consulta ()
{
	char cpf[40];
	char conteudo [200];
	
	printf ("Digite o CPF a ser consultado:");
	scanf ("%s",cpf);
	FILE *file;
	file = fopen (cpf, "r");
	
	if(file == NULL)
{
		printf ("Não foi possivel acessor o arquivo, não localizado.\n");
}

  while(fgets (conteudo, 200, file) !=NULL)
{
	
  	printf ("\nEssas são as informações do usuario: ");
  	printf ("%s", conteudo);
  	printf ("\n\n");
  	
}

	
	system ("pause");

}

int deletar()
{
	char cpf [40];
	printf ("Digite o CPF que deseja ser deletado: ");
	scanf ("%s" ,cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)	
	{
		printf("O usuario não se encontra no sistema\n");
		system("pause");
		}	
}


int main ()

 {

	int opcao=0;//definindo variaveis
	int laco=1;
	
	for (laco=1;laco=1;)
{	

	system("cls");
	

   setlocale(LC_ALL, "portuguese");//linguagem que vai ser usada no aplicativo
 
   printf("###Cartório da EBAC ###\n\n");//inicio do menu
   printf("Escolha a opção desejada do menu\n\n");
   printf("\t1 - Registrar nomes\n");
   printf("\t2 - Consultar os nomes\n");
   printf("\t3 - Deletar os nomes\n\n");
   printf("Opção: "); //fim do menu
   
   scanf("%d", &opcao);//armazenar a escolha do usuario
   
   system("cls");

   
   
   switch(opcao)
   
   { 
   case 1: 
   registro();
   break;
   
   case 2:
   consulta();
   break;
   
   case 3:
   deletar();
   break;
   
   case 4:
   printf ("Obrigada por utilizar o sistema!\n");
   return 0;
   break;	
   
   default:
   printf("A opção que você escolheu não está disponivel\n");
   system("pause"); 
   break;
  }


}

}


