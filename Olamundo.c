#include <stdio.h>//biblioteca de comunica��o com o usuario
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>// biblioteca de aloca��es de texto por regi�o
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
		printf ("N�o foi possivel acessor o arquivo, n�o localizado.\n");
}

  while(fgets (conteudo, 200, file) !=NULL)
{
	
  	printf ("\nEssas s�o as informa��es do usuario: ");
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
		printf("O usuario n�o se encontra no sistema\n");
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
 
   printf("###Cart�rio da EBAC ###\n\n");//inicio do menu
   printf("Escolha a op��o desejada do menu\n\n");
   printf("\t1 - Registrar nomes\n");
   printf("\t2 - Consultar os nomes\n");
   printf("\t3 - Deletar os nomes\n\n");
   printf("\t4 - Sair do sistema\n");
   printf("Op��o: "); //fim do menu
   
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
   printf("A op��o que voc� escolheu n�o est� disponivel\n");
   system("pause"); 
   break;
  }


}

}


