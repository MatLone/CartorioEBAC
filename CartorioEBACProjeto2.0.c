#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os calores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cagor a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen (arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf ("N�o foi possivel abrir o arquivo, n�o localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas S�o as informa��es do usu�rio:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
	
}

int deletar()
{
char cpf[40];

printf("Digite o CPF do usu�rio a ser deletado: ");
scanf("%s", cpf);

if(remove(cpf) == 0) {
    printf("Usu�rio deletado com sucesso.\n");
} else {
    printf("Erro ao deletar usu�rio.\n");
}

FILE *file;
file = fopen(cpf, "r");
if(file == NULL) {
    printf("O usu�rio n�o se encontra no sistema!\n");
} else {
    fclose(file);
}

}


int main()
{
    int opcao=0; //Definindo Vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
    
	{
		
		system("cls");
	
	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
	printf("### Cart�rio da EBAC ###\n\n"); //Inicio do Menu
	printf("Escolha a opc�o desejada do menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n"); 
	printf("\t4 - Sair do Sistema\n\n\n");
	printf("op��o:  ");//Fim do Menu
	
    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
    
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
		printf("Obrigado por utilisar o sistema\n");
		return 0;
    
    	default:
    	printf("Essa op��o n�o est� disponivel!\n");
    	system("pause");
    	break; 	
		
	}

}

}
