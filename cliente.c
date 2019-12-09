#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "cliente.h"
#include "validacoes.h"

char menuPrincipal(void);

void menuCliente(void){
    Cliente* cli;
	int op;
	do { 
		system("cls || clear");
        printf("\n\t------------------------------------\n");
        printf("\t               Ciente                   ");
        printf("\n\t------------------------------------\n\n\n");
		puts("\t1. Cadastrar Cliente");
        puts("\t2. Listar Clientes");
        puts("\t3. Buscar Cliente");
        puts("\t4. Editar Cliente");
        puts("\t5. Excluir Cliente");
        puts("\t6. Menu Principal");
		puts("\t0. Sair");
        puts("\t-------------------------------------");
		printf("\tSelecine uma opcao >>> ");
		scanf("%d", &op);
            switch(op){
                case 1:
                    cli = insereCliente();
                    break;
                case 2:
                    listaClientes(cli);
                    break;
                case 3:
                    buscaCliente();
                    break;
                case 4:
                    alteraCliente();
                    break;
                case 5:
               		excluirCliente();
                    break;
                case 6:
                	menuPrincipal();
                    break;
                case 0:
                    exit(0);
                    break;
                default:
                    puts("\n\tOpcao invalida. Tente novamente!\n");
                    break;
            }
    } while (op != 0);
    getchar();
}

Cliente* insereCliente(void){
    Cliente* cli;
	char resp;
	struct tm *info;
	time_t segundos;

    cli = (Cliente*) malloc(sizeof(Cliente));
    system("cls || clear");
    printf("\n\t------------------------------------\n");
    printf("\t            Novo Cliente              ");
    printf("\n\t------------------------------------\n\n\n");
	printf("\tNome do Cliente: ");
	scanf(" %51[^\n]", cli->nome);
	printf("\tCPF: ");
	scanf(" %12[^\n]", cli->cpf);
	while(validaCPF(cli->cpf) == 0){
	    printf("\tCPF invalido! Digite novamente: ");
        scanf(" %12[^\n]",cli->cpf);
    }
	printf("\tEndereco: ");
	scanf(" %51[^\n]", cli->endereco);
	printf("\tTelefone: ");
	scanf(" %12[^\n]", cli->telefone);

	printf("\n\n\tDeseja salvar o cadastro? (S ou N) ");
	scanf("%s",&resp);
	
	if(resp == 'S' || resp == 's'){   
		time(&segundos);
		info = localtime(&segundos);
		strftime(cli->data, 31, "%d/%m/%Y as %X", info);
		cli->dia = info->tm_mday;
		cli->mes = info->tm_mon;
		cli->ano = info->tm_year; 

	    salvaCliente (cli);
	    getchar();   
		printf("\n\tCadastro realizado com sucesso!\n");
    } else{
        printf("\n\tCadastro cancelado!\n");
    }
    return cli;
    getchar();
    getchar();
}

void salvaCliente(Cliente* cli){
    FILE* fpCliente; 
	cli->status = 'a';

	fpCliente = fopen("cliente.dat", "ab"); 
	
	if(fpCliente == NULL){
        printf("\n\n\n");
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...\n");
		exit (1);
	}
	fwrite(cli, sizeof(Cliente), 1, fpCliente);
	fclose(fpCliente);
}

void exibeCliente (Cliente* cli) {
	if((cli == NULL) || (cli->status == 'd')){
		printf("\tCliente nao Cadastrado!\n");
	} else{
		printf("\tCliente cadastrado em : %s \n", cli->data);
		printf("\n\tNome: %s", cli->nome);
		printf("\n\tCPF: %c%c%c.%c%c%c.%c%c%c-%c%c", cli->cpf[0],cli->cpf[1],cli->cpf[2],
	    cli->cpf[3],cli->cpf[4],cli->cpf[5],cli->cpf[6],cli->cpf[7],cli->cpf[8],cli->cpf[9],
	    cli->cpf[10]);
	    printf("\n\tEndereco: %s",cli->endereco);
		printf("\n\tTelefone: (%c%c)%c%c%c%c%c-%c%c%c%c", cli->telefone[0],cli->telefone[1],
	    cli->telefone[2],cli->telefone[3],cli->telefone[4],cli->telefone[5],cli->telefone[6],
	    cli->telefone[7],cli->telefone[8],cli->telefone[9],cli->telefone[10]);
	    printf("\n\t---------------------------------------------\n");
	}	
}

void listaClientes(Cliente* cli){
	FILE* fpCliente;
	fpCliente = fopen("cliente.dat", "rb");
	cli = (Cliente*) malloc(sizeof(Cliente));
	if(fpCliente == NULL){
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t---------------------------------------------\n");
	printf("\t              Lista de Clientes                  ");
	printf("\n\t---------------------------------------------\n\n\n");
	while(fread(cli, sizeof(Cliente), 1, fpCliente)){
		if(cli->status != 'd'){
			exibeCliente(cli);
		}
	}
	fclose(fpCliente);
	free(cli);
	getchar();
	getchar();
}

void buscaCliente(void){
    FILE* fpCliente;
    Cliente* cli;
    char busca[12];
    int achou;

	fpCliente = fopen("cliente.dat", "rb");
	cli = (Cliente*) malloc(sizeof(Cliente));
    if(fpCliente == NULL){
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
    system("cls || clear");
    printf("\n\t-------------------------------------\n");
    printf("\t            Busca Cliente                ");
    printf("\n\t-------------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);
	while(validaCPF(busca) == 0){
	    printf("\tCPF invalido! Digite novamente: ");
        scanf(" %12[^\n]",busca);
    }
    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fpCliente))){
   		if ((strcmp(cli->cpf, busca) == 0) && (cli->status == 'a')){
    		achou = 1;
   		}
  	}
	fclose(fpCliente);
	if(achou){
		exibeCliente(cli);
  	} else{
		printf("\n\n\tCliente nao cadastrado\n");
	}
	free(cli);
	getchar();
	getchar();
}

void alteraCliente(void){
	int op;
	do { 
		system("cls || clear");
    	printf("\n\t-------------------------------------\n");
    	printf("\t            Edita Cliente                ");
    	printf("\n\t-------------------------------------\n\n\n");
        puts("\t1. Nome");
        puts("\t2. CPF");
        puts("\t3. Endereco");
        puts("\t4. Telefone");
		puts("\t5. Substiruir Cadastro");
        puts("\t6. Menu Cliente");
		puts("\t0. Sair");
		puts("\t-------------------------------------");
		printf("\tSelecine uma opcao >>> ");
		scanf("%d", &op);
		switch(op){
			case 1:
                editaNomeCliente();
				break;
			case 2:
                editaCPFCliente();
				break;
			case 3:
				editaEnderecoCliente();
				break;
			case 4:
				editaTelefoneCliente();
				break;
			case 5:
				editaDadosCliente();
				break;
			case 6:
				menuCliente();
				break;
			case 0:
				exit(0);
				break;
			default:
				puts("\n\tOpcao invalida. Tente novamente!\n");
            break;
		}

	} while (op != 0);
    getchar();
}

void editaNomeCliente(void){
    FILE* fpCliente;
    Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	fpCliente = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
    if(fpCliente == NULL){
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
    printf("\n\t-------------------------------------\n");
    printf("\t            Edita Cliente                ");
    printf("\n\t-------------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);
	while(validaCPF(busca) == 0){
	    printf("\tCPF invalido! Digite novamente: ");
        scanf(" %12[^\n]",busca);
    }
    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fpCliente))){
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
	    	printf("\n\t-------------------------------------\n");
	    	printf("\t              Edita Nome                 ");
	    	printf("\n\t-------------------------------------\n\n\n");
			printf("\n\tNovo Nome: ");
			scanf(" %51[^\n]",cli->nome);
			cli->status = 'a';
			fseek(fpCliente, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fpCliente);
			printf("\n\tNome alterado com sucesso!\n");

		} else{
			printf("\n\tO nome do cliente permanece inalterado!\n");
		}
  	} else{
		printf("\n\n\tCliente nao cadastrado\n");
	}
	fclose(fpCliente);
	free(cli);
	getchar();
	getchar();
}

void editaEnderecoCliente(void){
    FILE* fpCliente;
    Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	fpCliente = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
    if(fpCliente == NULL){
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-------------------------------------\n");
    printf("\t            Edita Cliente                ");
    printf("\n\t-------------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);
	while(validaCPF(busca) == 0){
	    printf("\tCPF invalido! Digite novamente: ");
        scanf(" %12[^\n]",busca);
    }
    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fpCliente))){
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
	    	printf("\n\t-------------------------------------\n");
	    	printf("\t           Edita Endereco                ");
	    	printf("\n\t-------------------------------------\n\n\n");
			printf("\n\tNovo Endereco: ");
			scanf(" %51[^\n]",cli->endereco);
			cli->status = 'a';
			fseek(fpCliente, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fpCliente);
			printf("\n\tEndereco alterado com sucesso!\n");

		} else{
			printf("\n\tO Endereco do cliente permanece inalterado!\n");
		}	
  	} else{
		printf("\n\n\tCliente nao cadastrado\n");
	}
	fclose(fpCliente);
	free(cli);
	getchar();
	getchar();
}

void editaCPFCliente(void){
    FILE* fpCliente;
    Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	fpCliente = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
    if(fpCliente == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-------------------------------------\n");
	printf("\t            Edita Cliente                ");
	printf("\n\t-------------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);
	while(validaCPF(busca) == 0){
	    printf("\tCPF invalido! Digite novamente: ");
        scanf(" %12[^\n]",busca);
    }
    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fpCliente))){
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
			printf("\n\t-------------------------------------\n");
	    	printf("\t                Edita CPF                ");
	    	printf("\n\t-------------------------------------\n\n\n");
			printf("\n\tNovo CPF: ");
			scanf(" %12[^\n]",cli->cpf);
			while(validaCPF(cli->cpf) == 0){
		    printf("\tCPF invalido! Digite novamente: ");
	        scanf(" %12[^\n]",cli->cpf);
	    	}
			cli->status = 'a';
			fseek(fpCliente, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fpCliente);
			printf("\n\tCPF alterado com sucesso!\n");
		} else{
			printf("\n\tO CPF do cliente permanece inalterado!\n");
		}
  	} else{
		printf("\n\n\tCliente nao cadastrado\n");
	}

	fclose(fpCliente);
	free(cli);
	getchar();
	getchar();
}

void editaTelefoneCliente(void){
    FILE* fpCliente;
    Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	fpCliente = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
    if(fpCliente == NULL){
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-------------------------------------\n");
    printf("\t            Edita Cliente                ");
    printf("\n\t-------------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);
	while(validaCPF(busca) == 0){
	    printf("\tCPF invalido! Digite novamente: ");
        scanf(" %12[^\n]",busca);
    }
    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fpCliente))){
   		if((strcmp(cli->cpf, busca) == 0) && (cli->status == 'a')){
    		achou = 1;
   		}
  	}
	if(achou){
		exibeCliente(cli);
		printf("\tDeseja realmente editar o telefone deste cliente? (S ou N) ");
		scanf("%s",&resp);
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-------------------------------------\n");
    		printf("\t           Edita Telefone                ");
    		printf("\n\t-------------------------------------\n\n\n");
			printf("\n\tNovo Telefone: ");
			scanf(" %12[^\n]",cli->telefone);
			cli->status = 'a';
			fseek(fpCliente, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fpCliente);
			printf("\n\tTelefone alterado com sucesso!\n");
		} else{
			printf("\n\tO Telefone do cliente permanece inalterado!\n");
		}
  	} else{
		printf("\n\n\tCliente nao cadastrado\n");
	}

	fclose(fpCliente);
	free(cli);
	getchar();
	getchar();
}

void editaDadosCliente(void){
    FILE* fpCliente;
    Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	fpCliente = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
    if(fpCliente == NULL){
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
    printf("\n\t-------------------------------------\n");
	printf("\t            Edita Cliente                ");
	printf("\n\t-------------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);
    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fpCliente))){
   		if((strcmp(cli->cpf, busca) == 0) && (cli->status == 'a')){
    		achou = 1;
   		}
  	}
	if(achou){
		exibeCliente(cli);
		printf("\tDeseja realmente editar todos os dados deste cliente? (S ou N) ");
		scanf("%s",&resp);
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-------------------------------------\n");
    		printf("\t      Substituir Cadastro                ");
    		printf("\n\t-------------------------------------\n\n\n");
			printf("\tNome do Cliente: ");
			scanf(" %51[^\n]", cli->nome);
			printf("\tCPF: ");
			scanf(" %12[^\n]", cli->cpf);
			while(validaCPF(cli->cpf) == 0){
		    printf("\tCPF invalido! Digite novamente: ");
	        scanf(" %12[^\n]",cli->cpf);
	    	}
			printf("\tEndereco: ");
			scanf(" %51[^\n]", cli->endereco);
			printf("\tTelefone: ");
			scanf(" %12[^\n]", cli->telefone);
			cli->status = 'a';
			fseek(fpCliente, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fpCliente);
			printf("\n\tDados alterados com sucesso!\n");

		} else{
			printf("\n\tOs dados do cliente permanecem inalterados!\n");
		}
  	} else{
		printf("\n\n\tCliente nao cadastrado\n");
	}
	fclose(fpCliente);
	free(cli);
	getchar();
	getchar();
}

void excluirCliente(void){
	FILE* fpCliente;
	Cliente* cli;
    char busca[12];
	char resp;
    int achou;

	fpCliente = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
    if(fpCliente == NULL){
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls || clear");
    printf("\n\t------------------------------------\n");
    printf("\t           Exclui Cliente               ");
    printf("\n\t------------------------------------\n\n\n");
	printf("\tDigite o CPF do Cliente: ");
	scanf(" %12[^\n]", busca);
	while(validaCPF(busca) == 0){
	    printf("\tCPF invalido! Digite novamente: ");
        scanf(" %12[^\n]",busca);
    }
    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fpCliente))){
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
			fseek(fpCliente, -1*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fpCliente);
			printf("\n\tCliente excluido com sucesso!\n");
		} else{
			printf("\n\tO cliente permanece cadastrado!\n");
		}
  	} else{
		printf("\n\n\tCliente nao cadastrado\n");
	}
	fclose(fpCliente);
	free(cli);
	getchar();
	getchar();
}

int dataCadastroCliente(Cliente* cli){
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
