#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "cliente.h"

int menuPrincipal (void);
void menuCliente (void);
Cliente* insereCliente (void);
void salvaCliente (Cliente*);
void exibeCliente (Cliente*);
void listaClientes (Cliente*);
void buscaCliente (void);
void alteraCliente (void);
void editaCodigoCliente (void);
void editaNomeCliente (void);
void editaCPFCliente (void);
void editaEnderecoCliente (void);
void editaTelefoneCliente (void);
void editaDadosCliente (void);
void excluirCliente (void);
void excluirCliente (void);


void menuCliente (void) {
    Cliente* cli;
	int op;
	do { 
		system("cls || clear");
        printf("\n\t------------------------------------\n");
        printf("\t\t   CLIENTE");
        printf("\n\t------------------------------------\n\n\n");
		puts("\t1. Cadastrar Novo Cliente");
        puts("\t2. Exibir Clientes");
        puts("\t3. Pesquisar Cliente");
        puts("\t4. Alterar Cadastro");
        puts("\t5. Excluir Cadastro");
        puts("\t6. Menu Principal");
		puts("\t0. Sair");
        puts("\t----------------------------------");
		printf("\tSelecine uma opcao >>> ");
		scanf("%d", &op);

            switch (op) {
                case 1:
                    cli = insereCliente ();
                    break;
                case 2:
                    listaClientes (cli);
                    break;
                case 3:
                    buscaCliente ();
                    break;
                case 4:
                    alteraCliente ();
                    break;
                case 5:
               		excluirCliente ();
                    break;
                case 6:
                	menuPrincipal ();
                    break;
                case 0:
                    exit(0);
                    break;
                default:
                    puts("\tOpcao invalida. Tente novamente!\n");
                    break;
            }
    

	} while (op != 0);

}


Cliente* insereCliente (void) {
    Cliente* cli;
	char resp;
	struct tm *info;
	time_t segundos;

    cli = (Cliente*) malloc(sizeof(Cliente));

    system("cls || clear");
    printf("\n\t------------------------------------\n");
    printf("\t\t   NOVO CLIENTE");
    printf("\n\t------------------------------------\n\n\n");
	printf("\tCodigo Cliente: ");
    scanf("	%3[^\n]", cli->codigo);
	printf("\tNome: ");
	scanf(" %51[^\n]", cli->nome);
	printf("\tCPF: ");
	scanf(" %12[^\n]", cli->cpf);
	printf("\tEndereco: ");
	scanf(" %51[^\n]", cli->endereco);
	printf("\tTelefone: ");
	scanf(" %12[^\n]", cli->telefone);

	printf("\n\n\tDeseja salvar o cadastro? (S ou N) ");
	scanf("%s",&resp);
	
	if (resp == 'S' || resp == 's') {   
		time(&segundos);
		info = localtime(&segundos);
		strftime(cli->data, 31, "%d/%m/%Y as %X", info);
		cli->dia = info->tm_mday;
		cli->mes = info->tm_mon;
		cli->ano = info->tm_year; 

	    salvaCliente (cli);   
		printf("\n\tCadastro realizado com sucesso!\n");

    } else {
        printf("\n\tCadastro cancelado!\n");
    }

    return cli;
    getchar();
    getchar();
}


void salvaCliente(Cliente* cli) {
    FILE* arqc; 
	cli->status = 'a';

	arqc = fopen("cliente.txt", "at"); 
	
	if (arqc == NULL) {
        printf("\n\n\n");
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...\n");
		exit (1);
	
	}

	fwrite(cli, sizeof(Cliente), 1, arqc);
	fclose(arqc);
}


void exibeCliente (Cliente* cli) {

	if ((cli == NULL) || (cli->status == 'd')) {
		printf("\tCliente nao Cadastrado!\n");

	} else {
		printf("\n\tCliente cadastrado em : %s \n", cli->data);
	    printf("\n\tCodigo Cliente: %s", cli->codigo);
		printf("\n\tNome: %s", cli->nome);
		printf("\n\tCpf: %c%c%c.%c%c%c.%c%c%c-%c%c", cli->cpf[0],cli->cpf[1],cli->cpf[2],
	    cli->cpf[3],cli->cpf[4],cli->cpf[5],cli->cpf[6],cli->cpf[7],cli->cpf[8],cli->cpf[9],
	    cli->cpf[10]);
	    printf("\n\tEndereco: %s",cli->endereco);
		printf("\n\tTelefone: (%c%c)%c%c%c%c%c-%c%c%c%c", cli->telefone[0],cli->telefone[1],
	    cli->telefone[2],cli->telefone[3],cli->telefone[4],cli->telefone[5],cli->telefone[6],
	    cli->telefone[7],cli->telefone[8],cli->telefone[9],cli->telefone[10]);
	    printf("\n\t---------------------------------------------\n");
	}
	
}


void listaClientes (Cliente* cli) {
	FILE* arqc;

	arqc = fopen("cliente.txt", "rt");
	cli = (Cliente*) malloc(sizeof(Cliente));

	if (arqc == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t----------------------------------------------\n");
	printf("\t\t   LISTA DE CLIENTES");
	printf("\n\t------------------------------------------------\n\n\n");
	while(fread(cli, sizeof(Cliente), 1, arqc)){
		if(cli->status != 'd'){
			exibeCliente(cli);
		}
	}

	fclose(arqc);
	free(cli);
	getchar();
	getchar();
}


void buscaCliente(void){
    FILE* arqc;
    Cliente* cli;
    char busca[12];
    int achou;

	arqc = fopen("cliente.txt", "rb");
	cli = (Cliente*) malloc(sizeof(Cliente));

    if (arqc == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
    system("cls || clear");
    printf("\n\t------------------------------------\n");
    printf("\t\t   PESQUISA CLIENTE");
    printf("\n\t------------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);
    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, arqc))){
   		if ((strcmp(cli->cpf, busca) == 0) && (cli->status == 'a')){
    		achou = 1;
   		}
  	}
	fclose(arqc);
	if (achou) {
		exibeCliente(cli);

  	} else {
		printf("\n\n\tCliente nao cadastrado\n");
	}

	free(cli);
	getchar();
	getchar();
}


void alteraCliente (void) {
	int op;
	do { 
		system("cls||clear");
		printf("\n\t-----------------------------------\n");
		printf("\t\t   ALTERAR DADOS DO CLIENTE");
		printf("\n\t-----------------------------------\n\n\n");
		puts("\t1. Codigo do Cliente");
        puts("\t2. Nome");
        puts("\t3. CPF");
        puts("\t4. Endereco");
        puts("\t5. Telefone");
		puts("\t6. Todos os Campos");
        puts("\t7. Menu Cliente");
		puts("\t0. Sair");
		puts("\t-------------------------------------");
		printf("\tSelecine uma opcao >>> ");
		scanf("%d", &op);

		switch (op) {
			case 1:
				editaCodigoCliente ();
				break;
			case 2:
                editaNomeCliente ();
				break;
			case 3:
                editaCPFCliente ();
				break;
			case 4:
				editaEnderecoCliente();
				break;
			case 5:
				editaTelefoneCliente();
				break;
			case 6:
				editaDadosCliente();
				break;
			case 7:
				menuCliente ();
				break;
			case 0:
				exit(0);
				break;
			default:
				puts("\tOpcao invalida. Tente novamente!\n");
            break;
		}

	} while (op != 0);
    getchar();
}



void editaCodigoCliente (void) {
    FILE* arqc;
    Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	arqc = fopen("cliente.txt", "r+t");
	cli = (Cliente*) malloc(sizeof(Cliente));
	
    if(arqc == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t\tPESQUISA CLIENTE");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);
 
    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, arqc))) {
   		if ((strcmp(cli->cpf, busca) == 0) && (cli->status == 'a')) {
    		achou = 1;
   		}
  	}

	if(achou){
		exibeCliente(cli);
		printf("\tDeseja realmente editar o codigo deste cliente? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t\t   ALTERANDO CODIGO");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo Codigo: ");
			scanf(" %3[^\n]",cli->codigo);
			cli->status = 'a';
			fseek(arqc, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, arqc);
			printf("\n\tCodigo alterado com sucesso!\n");

		} else {
			printf("\n\tO codigo do cliente permanece inalterado!\n");
		}
		
  	} else {
		printf("\n\n\tCliente nao cadastrado\n");
	}

	fclose(arqc);
	free(cli);
	getchar();
	getchar();
}


void editaNomeCliente (void) {
    FILE* arqc;
    Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	arqc = fopen("cliente.txt", "r+t");
	cli = (Cliente*) malloc(sizeof(Cliente));
	
    if (arqc == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t\t   PESQUISA CLIENTE");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);
   
    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, arqc))){
   		if ((strcmp(cli->cpf, busca) == 0) && (cli->status == 'a')){
    		achou = 1;
   		}
  	}

	if(achou){
		exibeCliente(cli);
		printf("\tDeseja realmente editar o nome deste cliente? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t\t   ALTERANDO NOME");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo Nome: ");
			scanf(" %51[^\n]",cli->nome);
			cli->status = 'a';
			fseek(arqc, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, arqc);
			printf("\n\tNome alterado com sucesso!\n");

		}
		else{
			printf("\n\tO nome do cliente permanece inalterado!\n");
		}
		
  	} else {
		printf("\n\n\tCliente nao cadastrado\n");
	}

	fclose(arqc);
	free(cli);
	getchar();
	getchar();
}


void editaEnderecoCliente (void) {
    FILE* arqc;
    Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	arqc = fopen("cliente.txt", "r+t");
	cli = (Cliente*) malloc(sizeof(Cliente));

    if (arqc == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t\t   PESQUISA CLIENTE");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);

    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, arqc))){
   		if ((strcmp(cli->cpf, busca) == 0) && (cli->status == 'a')){
    		achou = 1;
   		}
  	}

	if(achou){
		exibeCliente(cli);
		printf("\tDeseja realmente editar o endereco deste cliente? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t\t   ALTERANDO ENDERECO");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo Endereco: ");
			scanf(" %51[^\n]",cli->endereco);
			cli->status = 'a';
			fseek(arqc, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, arqc);
			printf("\n\tEndereco alterado com sucesso!\n");

		} else {
			printf("\n\tO Endereco do cliente permanece inalterado!\n");
		}
		
  	} else {
		printf("\n\n\tCliente nao cadastrado\n");
	}

	fclose(arqc);
	free(cli);
	getchar();
	getchar();
}


void editaCPFCliente (void) {
    FILE* arqc;
    Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	arqc = fopen("cliente.txt", "r+t");
	cli = (Cliente*) malloc(sizeof(Cliente));

    if(arqc == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t\t   PESQUISA CLIENTE");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);
   
    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, arqc))){
   		if ((strcmp(cli->cpf, busca) == 0) && (cli->status == 'a')){
    		achou = 1;
   		}
  	}
	if(achou){
		exibeCliente(cli);
		printf("\tDeseja realmente editar o cpf deste cliente? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t\t   ALTERANDO CPF");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo CPF: ");
			scanf(" %12[^\n]",cli->cpf);
			cli->status = 'a';
			fseek(arqc, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, arqc);
			printf("\n\tCPF alterado com sucesso!\n");

		} else {
			printf("\n\tO CPF do cliente permanece inalterado!\n");
		}
		
  	} else {
		printf("\n\n\tCliente nao cadastrado\n");
	}

	fclose(arqc);
	free(cli);
	getchar();
	getchar();
}


void editaTelefoneCliente (void) {
    FILE* arqc;
    Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	arqc = fopen("cliente.txt", "r+t");
	cli = (Cliente*) malloc(sizeof(Cliente));

    if(arqc == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t\t   PESQUISA CLIENTE");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);

    achou = 0;
	while ((!achou) && (fread(cli, sizeof(Cliente), 1, arqc))){
   		if ((strcmp(cli->cpf, busca) == 0) && (cli->status == 'a')){
    		achou = 1;
   		}
  	}

	if (achou) {
		exibeCliente(cli);
		printf("\tDeseja realmente editar o telefone deste cliente? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t\t   ALTERANDO TELEFONE");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo Telefone: ");
			scanf(" %12[^\n]",cli->telefone);
			cli->status = 'a';
			fseek(arqc, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, arqc);
			printf("\n\tTelefone alterado com sucesso!\n");

		} else {
			printf("\n\tO Telefone do cliente permanece inalterado!\n");
		}
		
  	} else {
		printf("\n\n\tCliente nao cadastrado\n");
	}

	fclose(arqc);
	free(cli);
	getchar();
	getchar();
}



void editaDadosCliente (void) {
    FILE* arqc;
    Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	arqc = fopen("cliente.txt", "r+t");
	cli = (Cliente*) malloc(sizeof(Cliente));

    if (arqc == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t\t   PESQUISA CLIENTE");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);

    achou = 0;
	while ((!achou) && (fread(cli, sizeof(Cliente), 1, arqc))) {
   		if ((strcmp(cli->cpf, busca) == 0) && (cli->status == 'a')) {
    		achou = 1;
   		}
  	}
	if (achou) {
		exibeCliente(cli);
		printf("\tDeseja realmente editar todos os dados deste cliente? (S ou N) ");
		scanf("%s",&resp);
	
		if (resp == 'S' || resp == 's') {   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t\t   ALTERANDO TODOS OS DADOS");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\tCodigo Cliente: ");
			scanf("	%3[^\n]", cli->codigo);
			printf("\tNome: ");
			scanf(" %51[^\n]", cli->nome);
			printf("\tCPF: ");
			scanf(" %12[^\n]", cli->cpf);
			printf("\tEndereco: ");
			scanf(" %51[^\n]", cli->endereco);
			printf("\tTelefone: ");
			scanf(" %12[^\n]", cli->telefone);
			cli->status = 'a';
			fseek(arqc, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, arqc);
			printf("\n\tDados alterados com sucesso!\n");

		} else {
			printf("\n\tOs dados do cliente permanecem inalterados!\n");
		}
		
  	} else {
		printf("\n\n\tCliente nao cadastrado\n");
	}

	fclose(arqc);
	free(cli);
	getchar();
	getchar();
}


void excluirCliente (void) {
	FILE* arqc;
	Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	arqc = fopen("cliente.txt", "r+t");
	cli = (Cliente*) malloc(sizeof(Cliente));

    if (arqc == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t\t   PESQUISA CLIENTE");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);

    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, arqc))){
   		if ((strcmp(cli->cpf, busca) == 0) && (cli->status == 'a')){
    		achou = 1;
   		}
  	}

	if(achou){
		exibeCliente(cli);
		printf("\tDeseja excluir deste cliente? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			cli->status = 'd';
			fseek(arqc, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, arqc);
			printf("\n\tCliente excluido com sucesso!\n");
		} else {
			printf("\n\tO cliente permanece cadastrado!\n");
		}
		
  	} else {
		printf("\n\n\tCliente nao cadastrado\n");
	}

	fclose(arqc);
	free(cli);
	getchar();
	getchar();
}

int dataCadastroCliente (Cliente* cli) {
	struct tm t;
	t.tm_mday = cli->dia;
	t.tm_mon = cli->mes;
	t.tm_year = cli->ano;
	t.tm_hour = 0;
	t.tm_min= 0;
	t.tm_sec = 1;
	t.tm_isdst = -1;
	int retorno = mktime(&t);

	return retorno/86400;
}


int dataSistema(void) {
	struct tm* t;
	time_t rawtime;
	time(&rawtime);
	t = localtime(&rawtime);
	int retorno = mktime(t);

	return retorno/86400;
}