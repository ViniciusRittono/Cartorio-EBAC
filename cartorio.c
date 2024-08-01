#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de aloção de espaço de memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h>// biblioteca responsavel por cuidar das strings

int registro()// função responsavel pra cadrastrar os usuarios do sistemas

{
	//inicio da criação de variaveis/strings
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
//final de de ciação de viriaveias/strings

        printf("Digite o CPF a ser cadrastrado:");//colete informação do usuario
        scanf("%s" , cpf);//%s refere-se as strings
    
        strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
    
        FILE *file; // cria o arquivo
        file = fopen(arquivo, "w"); // cria o arquivo e o w significa escrever
        fprintf(file,cpf);// salvo o valor da variavel
        fclose(file);// fachar o arquivo    

        file = fopen(arquivo, "a");
        fprintf(file, "," );
        fclose(file);
    
        printf("Digite o nome a ser cadrastrado: ");
        scanf("%s" , nome);
    
        file = fopen(arquivo, "a");
        fprintf(file,nome);
        fclose(file);
    
        file = fopen(arquivo, "a");
        fprintf(file, "," );
        fclose(file);

        printf("Digite o sobrenome a ser cadrastrado:");
        scanf("%s", sobrenome);
    
        file = fopen(arquivo, "a");
        fprintf(file,sobrenome);
        fclose(file);
    
        file = fopen(arquivo, "a");
        fprintf(file, "," );
        fclose(file);
    
        printf("Digite o cargo a ser cadrastrado:");
        scanf("%s", cargo);
    
        file = fopen(arquivo, "a");
        fprintf(file,cargo);
        fclose(file);
    
        system("pause");
        
}

int consulta()
{
	setlocale(LC_ALL, "portuguese_brazil");	//definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s" , cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		 printf("Nao foi possivel abri o arquivo, nao localizado!.\n");
		 
	}
	
	while(fgets(conteudo, 200, file ) != NULL)
	{
		printf(" \nEssas sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}
int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuario a ser deletado: ");
    scanf("%s" , cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL);
    {
    	printf(" O usuario nao se encontra no sistema! . \n");
    	system("pause");
    	
	}
    
}



int main()
{
	int opcao=0; //difinindo as variaveis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
		
    intopcao://definindo variaveis
	
	
        setlocale(LC_ALL, "portuguese_brazil");	//definindo linguagem

	    printf("### cartorio da EBAC ###\n\n"); //inicio do menu

	    printf("escolha a opcao desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - deletar nomes\n\n"); 
	    printf("opcao: ");//final do menu
	
	
	    scanf("%d",&opcao); //aemazenando a escolha do usuario
	
	    system("cls");//responsavel por limpar a tela
	
	
	    switch(opcao) //inicio da seleção de menu
	    {
		    case 1:
		    registro();//chamada de função
		    break;
		
		    case 2:
			consulta();
	        break;
	        
	        case 3:
	        deletar();
	        break;
	    
	        default:
			printf("Esta opcao nao esta disponivel!\n");
            system("pause");
            break;
	        //fim de seleção		
	    }
    
}
}