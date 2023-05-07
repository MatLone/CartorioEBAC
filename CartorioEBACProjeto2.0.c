#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

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
		printf ("Não foi possivel abrir o arquivo, não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas São as informações do usuário:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
	
}

int deletar()
{
char cpf[40];

printf("Digite o CPF do usuário a ser deletado: ");
scanf("%s", cpf);

if(remove(cpf) == 0) {
    printf("Usuário deletado com sucesso.\n");
} else {
    printf("Erro ao deletar usuário.\n");
}

FILE *file;
file = fopen(cpf, "r");
if(file == NULL) {
    printf("O usuário não se encontra no sistema!\n");
} else {
    fclose(file);
}

}


int main()
{
    int opcao=0; //Definindo Variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    
	{
		
		system("cls");
	
	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
	printf("### Cartório da EBAC ###\n\n"); //Inicio do Menu
	printf("Escolha a opcão desejada do menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n"); 
	printf("\t4 - Sair do Sistema\n\n\n");
	printf("opção:  ");//Fim do Menu
	
    scanf("%d", &opcao); //Armazenando a escolha do usuário
    
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
    	printf("Essa opção não está disponivel!\n");
    	system("pause");
    	break; 	
		
	}

}

}
