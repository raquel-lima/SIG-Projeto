#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>


int main(){
	
	setlocale(LC_ALL, "Portuguese");
	char login[100];
	int opcao, opcao1;
	
	struct dados_cliente{
	  char nome[100];
	  char cpf[100];
	  char telefone[100];
	  char endereco[100];
	  char email[100];
	  }cliente;
	  
	system("color 07");  
	system("cls");
	printf("\t---------------------------------------------------\n");
	printf("\t\tSIG - Custumer Controle de Clientes \n");
	printf("\t---------------------------------------------------\n\n");
	printf("\tLogin: ");
	fflush(stdin);
	scanf("%[^\n]s", login);
	printf("\tSenha: ");
	scanf("%d",&opcao);
	
	switch (opcao){
		case 1234:
			do{
				system("color 70");
				system("cls");
				printf("\t--------------------------------\n");
				printf("\t\tMenu Principal \n");
				printf("\t--------------------------------\n\n");
				printf("\t1 - Clientes \n");
				printf("\t2 - Compras \n");
				printf("\t3 - Informa��es do Sistema \n");
				printf("\t0 - Sair \n");
				printf("\t>>>> ");
				scanf("%d",&opcao);
				printf("\n");
				
				switch(opcao){
					case 1:
					system("cls");
					printf("\t--------------------------------\n");
					printf("\t\tMenu Clientes \n");
					printf("\t--------------------------------\n\n");
					printf("\t1 - Cadastrar \n");
					printf("\t2 - Pesquisar \n");
					printf("\t3 - Alterar \n");
					printf("\t4 - Exlcuir \n");
					printf("\t0 - Sair \n");
					printf("\t>>>> ");
					scanf("%d",&opcao1);
					printf("\n");
					system("pause");
					break;
					case 2:
					system("cls");
					printf("\t--------------------------------\n");
					printf("\t\tMenu Compras \n");
					printf("\t--------------------------------\n\n");
					system("pause");
					break;
					case 3:
					system("cls");
					printf("\t--------------------------------\n");
					printf("\t\tMenu Informa��es do Sistema \n");
					printf("\t--------------------------------\n\n");
					printf("O SIG-Custumer Controle de Clientes tem por objetivo:\n\n");
					printf("Implementar funcionalidades b�sicas relacionadas ao controle de clientes de uma empresa, facilitando sua gest�o. \n\n");
					printf("Para mais informa��es\n");
					printf("E-mail: raquel.discente@gmail.com\n");
					printf("Tel.: (83)9 9986-4860 \n");
					printf("https://github.com/raquel-lima\n\n");
					system("pause");
					break;
					case 0:
					exit(0);
					system("pause");
					break;
					default:
					printf("Op��o inv�lida!\n");
					sleep(1);
					break;					
				}

			}while(opcao > 0);
			break;
	}
	getchar();
	return 0;
}


