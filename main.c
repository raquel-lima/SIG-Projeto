#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <conio.h>
#include <windows.h>


typedef struct cliente {
    int cod;
    char nome[50];
    char cpf[15];
    char end[50];
    char tel[20];
    char status;
}Cliente;


void move_cursor (int x, int y, char c[10]);
void menuPrincipal (void);

 
void menuCliente (void);
void cadastrarCliente (Cliente* cli);
void salvarCliente (Cliente* cli);
void pesquisarCliente (Cliente* cli);
void verCliente (Cliente* cli);
void menuAlterarCliente (void);
void mudaCodigoCliente (void);
void mudaNomeCliente (void);
void mudaCpfCliente (void);
void mudaEnderecoCliente (void);
void mudaTelefoneCliente (void);
void mudaCamposCliente (void);
void excluirCliente (Cliente* cli);
void exibirClientes (Cliente* cli);


int main (void) {

    menuPrincipal ();
    getchar();
    return 0;
}


void menuPrincipal (void) {

	system("MODE con cols=80 lines=24");
	
    char op;
    int posx = 4;
    int posy = 6;

    do {
        move_cursor(30,1,"::: MENU PRINCIPAL :::");
	    move_cursor(5,6,"1 - Cliente");
	    move_cursor(5,8,"2 - Pet");
	    move_cursor(5,10,"3 - Servicos");
	    move_cursor(5,12,"4 - Agendamentos");
	    move_cursor(5,14,"5 - Informacoes sobre o Sistema");
	    move_cursor(5,16,"Sair");
	    move_cursor(5,20,"Selecione uma opcao e tecle ENTER\n");
        move_cursor(posx, posy, ">");

        op = toupper(getch());

        switch(op){
			case 'H':
                if (posy > 6) {
                    move_cursor(posx, posy, " ");
                    posy-=2;
                    move_cursor(posx, posy, ">");            
                }
            break;
			case 'P':
                if (posy < 16) {
                    move_cursor(posx, posy, " ");
                    posy+=2;
                    move_cursor(posx, posy, ">"); 
                }
            break;
			case 13:
				if (posy == 6) {
                    menuCliente ();
	            }         
				if (posy == 8) {

                }                
                if (posy == 10) {

                }                
                if (posy == 12) {
                   
                }                
                if (posy == 14) {
                  
                }
                if (posy == 16) {
                    exit(EXIT_SUCCESS);
                }
            break;
		}

    }while(1);
    getchar();

}


void menuCliente (void) {
    Cliente* cli;
    char op;
    int posx = 4;
    int posy = 6;

    do {
        system("MODE con cols=80 lines=24");

        move_cursor(30,1,"::: MENU CLIENTE :::");
	    move_cursor(5,6,"1 - Cadastrar");
	    move_cursor(5,8,"2 - Pesquisar ");
	    move_cursor(5,10,"3 - Alterar");
	    move_cursor(5,12,"4 - Excluir");
	    move_cursor(5,14,"5 - Exibir todos");
        move_cursor(5,16,"Menu Principal");
	    move_cursor(38,16,"Sair");
	    move_cursor(5,20,"Selecione uma opcao e tecle ENTER\n");
        move_cursor(posx, posy, ">");

        op = toupper(getch());

        switch(op){
			case 'H':
                if (posy > 6) {
                    move_cursor(posx, posy, " ");
                    posy-=2;
                    move_cursor(posx, posy, ">");            
                }
            break;
			case 'P':
                if (posy < 16) {
                    move_cursor(posx, posy, " ");
                    posy+=2;
                    move_cursor(posx, posy, ">"); 
                }
            break;
			case 'M':  
                if ((posx < 38) && (posy == 16)){
                move_cursor(posx, posy, " ");
                posx+=33;
                move_cursor(posx, posy, ">");             
                }  
            break; 
			case 'K':          
				if ((posx > 5) && (posy == 16)){
                    move_cursor(posx, posy, " ");
                    posx-=33;
                    move_cursor(posx, posy, ">");              
                }
            break;
			case 13:
				if (posy == 6) {
                    cadastrarCliente (cli);
                    salvarCliente (cli);
	            }         
				if (posy == 8) {
                    pesquisarCliente (cli);
                    verCliente (cli);
                }                
                if (posy == 10) {
                	menuAlterarCliente ();
                }                
                if (posy == 12) {
                    excluirCliente (cli);
                }                
                if (posy == 14) {
                    exibirClientes (cli);
                }
                if ((posx == 4) && (posy == 16)) {
                    menuPrincipal ();
                }
                if ((posx == 37) && (posy == 16)) {
                    exit(EXIT_SUCCESS);
                }
            break;

		}

    }while(1);
    getchar();

}

void cadastrarCliente (Cliente* cli) {
    char resp;
    int posx = 4;
    int posy = 6;
    cli = (Cliente*) malloc(sizeof(Cliente));

    system("MODE con cols=80 lines=24");
    move_cursor(30,1,"::: CADASTRO DE CLIENTE :::");
    move_cursor(5,6,"Codigo Cliente: ");
	scanf(" %d", &cli->cod);
	move_cursor(5,8,"Nome: ");
	scanf(" %40[^\n]", cli->nome);
	move_cursor(5,10,"Cpf: ");
	scanf(" %15[^\n]", cli->cpf);
	move_cursor(5,12,"Endereco: ");
	scanf(" %40[^\n]", cli->end);
	move_cursor(5,14,"Telefone: ");
	scanf(" %20[^\n]", cli->tel);
	move_cursor(posx, posy, " ");
	move_cursor(5,18,"Deseja salvar o cadastro (S/N)? ");
	scanf("%c", &resp);
	
	resp = toupper(getche());
	
	if (resp == 'S') {
		cli->status = 'c';
		salvarCliente (cli);
		move_cursor(5,21,"Cadastro salvo, tecle ENTER para voltar ao MENU CLIENTE\n");			
	} else {
		move_cursor(5,21,"Cadastro cancelado, tecle ENTER para voltar ao MENU CLIENTE\n");
	}
	getchar();

}

void salvarCliente (Cliente* cli) {
	FILE* fp; 
	fp = fopen("cliente.dat", "ab"); 
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit (EXIT_FAILURE);
	
	}
	fwrite(cli, sizeof(Cliente), 1, fp);
	fclose(fp); 
		
}

void pesquisarCliente (Cliente* cli) {
    FILE* fp;
    char procurado[15];
    int achou;

    fp = fopen("cliente.dat", "rb");
    cli = (Cliente*) malloc(sizeof(Cliente));
    if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
    system("MODE con cols=80 lines=24");
    move_cursor(30,1,"::: PESQUISAR CLIENTE :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Cliente: ");
	scanf("%15[^\n]", procurado);

    achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fp)))  {
   		if ((strcmp(cli->cpf, procurado) == 0) && (cli->status == 'c')){
    		achou = 1;
   		}
  	}
	fclose(fp);
	if (achou){
		verCliente (cli);
		getchar();
		move_cursor(8,21,"Tecle ENTER para voltar ao MENU CLIENTE\n");
  	}else{
		move_cursor(8,21,"Cliente nao cadastrado, tecle ENTER para voltar ao MENU CLIENTE\n");
    	
	}
	getchar();

}

void verCliente (Cliente* cli) {
	printf("\n");
	printf("\n\tCodigo Cliente: %d\n", cli->cod);
	printf("\n\tNome: %s\n", cli->nome);
	printf("\n\tCpf: %s\n", cli->cpf);
	printf("\n\tEndereco: %s\n", cli->end);
	printf("\n\tTelefone: %s\n", cli->tel);
    printf("\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

}

void menuAlterarCliente (void) {
	Cliente* cli;
    char op;
    int posx = 4;
    int posy = 6;

    do {
		system("MODE con cols=80 lines=24");
        move_cursor(30,1,"::: MENU ALTERAR CLIENTE :::");
	    move_cursor(5,6,"1 - Codigo Cliente");
	    move_cursor(5,8,"2 - Nome");
	    move_cursor(5,10,"3 - CPF");
	    move_cursor(5,12,"4 - Endereco");
	    move_cursor(5,14,"5 - Telefone");
	    move_cursor(5,16,"6 - Todos os Campos");
	    move_cursor(5,18,"Menu Cliente");
	    move_cursor(38,18,"Sair");
	    move_cursor(5,21,"Selecione uma opcao a ser alterada e tecle ENTER\n");
        move_cursor(posx, posy, ">");
        
        op = toupper(getch());
		
		switch(op){
			case 'H':
                if (posy > 6) {
                    move_cursor(posx, posy, " ");
                    posy-=2;
                    move_cursor(posx, posy, ">");            
                }
            break;
			case 'P':
                if (posy < 18) {
                    move_cursor(posx, posy, " ");
                    posy+=2;
                    move_cursor(posx, posy, ">"); 
                }
            break;
			case 'M':  
                if ((posx < 38) && (posy == 18)){
                move_cursor(posx, posy, " ");
                posx+=33;
                move_cursor(posx, posy, ">");             
                }  
            break; 
			case 'K':          
				if ((posx > 5) && (posy == 18)){
                    move_cursor(posx, posy, " ");
                    posx-=33;
                    move_cursor(posx, posy, ">");              
                }
            break;
			case 13:
				if (posy == 6) {
					mudaCodigoCliente ();
	            }         
				if (posy == 8) {
					mudaNomeCliente ();
                }                
                if (posy == 10) {
                	mudaCpfCliente ();   
                }             
                if (posy == 12) {
                	mudaEnderecoCliente (); 
                }                
                if (posy == 14) {
					mudaTelefoneCliente ();
                }
                if (posy == 16) {
					mudaCamposCliente ();
                }
                if ((posx == 4) && (posy == 18)) {
                    menuCliente ();
                }
                if ((posx == 37) && (posy == 18)) {
                    exit(EXIT_SUCCESS);
                }
            break;
		}
		
	}while(1);	
	getchar();

}

void mudaCodigoCliente (void){
	Cliente* cli;
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
	
	system("MODE con cols=80 lines=24");
	
	fp = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
	move_cursor(30,1,"::: PESQUISAR CLIENTE :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Cliente: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fp)))  {
		if ((strcmp(cli->cpf, procurado) == 0) && (cli->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verCliente (cli);
    	move_cursor(8,21,"Deseja alterar o codigo deste cliente (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERANDO CODIGO :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
    		move_cursor(8,6,"Novo Codigo: ");
			scanf("%d", &cli->cod);			
			cli->status = 'c';
			
			fseek(fp, menusUm*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fp);
			move_cursor(8,21,"Codigo alterado com sucesso, tecle ENTER para voltar ao MENU CLIENTE\n");	
			getchar();
    	} else {
			move_cursor(8,21,"Codigo nao alterado, tecle ENTER para voltar ao MENU CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s não foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);

}


void mudaNomeCliente (void){
	Cliente* cli;
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
	
	system("MODE con cols=80 lines=24");
	
	fp = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
	move_cursor(30,1,"::: PESQUISAR CLIENTE :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Cliente: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fp)))  {
		if ((strcmp(cli->cpf, procurado) == 0) && (cli->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verCliente (cli);
    	move_cursor(8,21,"Deseja alterar o nome deste cliente (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERANDO NOME :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
    		move_cursor(8,6,"Novo Nome: ");
			scanf("%50[^\n]", cli->nome);			
			cli->status = 'c';
			
			fseek(fp, menusUm*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fp);
			move_cursor(8,21,"Nome alterado com sucesso, tecle ENTER para voltar ao MENU CLIENTE\n");	
			getchar();
    	} else {
			move_cursor(8,21,"Nome nao alterado, tecle ENTER para voltar ao MENU CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s não foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);

}


void mudaCpfCliente (void){
	Cliente* cli;
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
	
	system("MODE con cols=80 lines=24");
	
	fp = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
	move_cursor(30,1,"::: PESQUISAR CLIENTE :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Cliente: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fp)))  {
		if ((strcmp(cli->cpf, procurado) == 0) && (cli->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verCliente (cli);
    	move_cursor(8,21,"Deseja alterar o cpf deste cliente (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERANDO CPF :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
    		move_cursor(8,6,"Novo CPF: ");
			scanf("%15[^\n]", cli->cpf);			
			cli->status = 'c';
			
			fseek(fp, menusUm*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fp);
			move_cursor(8,21,"CPF alterado com sucesso, tecle ENTER para voltar ao MENU CLIENTE\n");	
			getchar();
    	} else {
			move_cursor(8,21,"CPF nao alterado, tecle ENTER para voltar ao MENU CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s não foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);

}


void mudaEnderecoCliente (void){
	Cliente* cli;
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
	
	system("MODE con cols=80 lines=24");
	
	fp = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
	move_cursor(30,1,"::: PESQUISAR CLIENTE :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Cliente: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fp)))  {
		if ((strcmp(cli->cpf, procurado) == 0) && (cli->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verCliente (cli);
    	move_cursor(8,21,"Deseja alterar o endereco deste cliente (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERANDO ENDERECO :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
    		move_cursor(8,6,"Novo Endereco: ");
			scanf("%50[^\n]", cli->end);			
			cli->status = 'c';
			
			fseek(fp, menusUm*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fp);
			move_cursor(8,21,"Endereco alterado com sucesso, tecle ENTER para voltar ao MENU CLIENTE\n");	
			getchar();
    	} else {
			move_cursor(8,21,"Endereco nao alterado, tecle ENTER para voltar ao MENU CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s não foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);

}


void mudaTelefoneCliente (void){
	Cliente* cli;
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
	
	system("MODE con cols=80 lines=24");
	
	fp = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
	move_cursor(30,1,"::: PESQUISAR CLIENTE :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Cliente: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fp)))  {
		if ((strcmp(cli->cpf, procurado) == 0) && (cli->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verCliente (cli);
    	move_cursor(8,21,"Deseja alterar o telefone deste cliente (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERANDO TELEFONE :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
    		move_cursor(8,6,"Novo Telefone: ");
			scanf("%20[^\n]", cli->tel);			
			cli->status = 'c';
			
			fseek(fp, menusUm*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fp);
			move_cursor(8,21,"Telefone alterado com sucesso, tecle ENTER para voltar ao MENU CLIENTE\n");	
			getchar();
    	} else {
			move_cursor(8,21,"Telefone nao alterado, tecle ENTER para voltar ao MENU CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s não foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);

}


void mudaCamposCliente (void){
	Cliente* cli;
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
	
	system("MODE con cols=80 lines=24");
	
	fp = fopen("cliente.dat", "r+b");
	cli = (Cliente*) malloc(sizeof(Cliente));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
	move_cursor(30,1,"::: PESQUISAR CLIENTE :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Cliente: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fp)))  {
		if ((strcmp(cli->cpf, procurado) == 0) && (cli->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verCliente (cli);
    	move_cursor(8,21,"Deseja alterar todos os campos deste cliente (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERANDO CAMPOS :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
    		move_cursor(8,6,"Codigo Cliente: ");
			scanf(" %d", &cli->cod);
			move_cursor(8,8,"Nome: ");
			scanf(" %50[^\n]", cli->nome);
			move_cursor(8,10,"Cpf: ");
			scanf(" %15[^\n]", cli->cpf);
			move_cursor(8,12,"Endereco: ");
			scanf(" %50[^\n]", cli->end);
			move_cursor(8,14,"Telefone: ");
			scanf(" %20[^\n]", cli->tel);			
			cli->status = 'c';
			
			fseek(fp, menusUm*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fp);
			move_cursor(8,21,"Campos alterados com sucesso, tecle ENTER para voltar ao MENU CLIENTE\n");	
			getchar();
    	} else {
			move_cursor(8,21,"Campos nao foram alterados, tecle ENTER para voltar ao MENU CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s não foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);

}


void excluirCliente (Cliente* cli) {
	FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	
	system("MODE con cols=80 lines=24");
	
	fp = fopen("cliente.dat", "r+b");
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
	}
  	
	move_cursor(30,1,"::: PESQUISAR CLIENTE :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Cliente: ");
	scanf("%15[^\n]", procurado);
	cli = (Cliente*) malloc(sizeof(Cliente));
  	achou = 0;
	while((!achou) && (fread(cli, sizeof(Cliente), 1, fp)))  {
   		if ((strcmp(cli->cpf, procurado) == 0) && (cli->status == 'c')){
    		achou = 1;
   		}
  	}
	if(achou) {
		verCliente (cli);
		move_cursor(8,20,"Deseja excluir este cliente (S/N)? ");
		scanf("%c", &resp);
		
		resp = toupper(getche());
		
		if(resp == 'S') {
			system("cls");
			move_cursor(30,1,"::: EXCLUINDO CADASTRO :::");
			cli->status = 'n';
			
			fseek(fp, menusUm*sizeof(Cliente), SEEK_CUR);
			fwrite(cli, sizeof(Cliente), 1, fp);
			
			move_cursor(8,21,"Cliente excluido com sucesso, tecle ENTER para voltar ao MENU CLIENTE\n");
		} else {
			move_cursor(8,21," nao excluido, Tecle ENTER para voltar ao MENU CLIENTE\n");
	}
	} else {
		printf("\n\n\n\n\n\n\tO CPF %s não foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);
}

void exibirClientes (Cliente* cli) {
	FILE* fp;
	fp = fopen("cliente.dat", "rb");
  
	if(fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
	}
	system("MODE con cols=80 lines=60");
	move_cursor(30,1,"::: EXIBIR CLIENTES :::");
	printf("\n\n\n");
  
	cli = (Cliente*) malloc(sizeof(Cliente));
  
	while(fread(cli, sizeof(Cliente), 1, fp)) {
		if (cli->status == 'c') {
			verCliente(cli);
			getchar();
		}
	}
	fclose(fp);
	free(cli);
}


void move_cursor(int x, int y, char c[30]) { 
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x,y};
    SetConsoleCursorPosition(hStdout, position);
    printf("%s", c);   
}