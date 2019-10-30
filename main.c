#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <conio.h>
#include <windows.h>


typedef struct data {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct cliente {
    int cod;
    char nome[50];
    char cpf[15];
    char end[50];
    char tel[20];
    char status;
}Cliente;

typedef struct pet {
    int cod;
    char nomeProp[50];
    char cpfProp[15];
    char nome[10];
    char esp[10];
    char datanasc[15];
    char sexo[2];
    char status;
}Pet;

typedef struct servicos {
	char tipo[20];
	char nomeProp[50];
	char cpfProp[15];
	char nomePet[10];
	char esp[10];
	char sexo[2];
	char obs[100];
}Servicos;


void move_cursor (int x, int y, char c[10]);
void menuPrincipal (void);
void login (void);
void menuCliente (void);
Cliente* cadastrarCliente (void);
void salvarCliente (Cliente*);
Cliente* pesquisarCliente (void);
void verCliente (Cliente*);
void menuAlterarCliente (void);
Cliente* altCodCliente (void);
Cliente* altNomeCliente (void);
Cliente* altCpfCliente (void);
Cliente* altEndCliente (void);
Cliente* altTelCliente (void);
Cliente* altCamposCliente (void);
Cliente* excluirCliente (void);
void exibirClientes (Cliente* cli);


void menuPet (void);
Pet* cadastrarPet (void);
void salvarPet (Pet*);
Pet* pesquisarPet (void);
void verPet (Pet*);
void menuAlterarPet (void);
Pet* altNomePropPet (void);
Pet* altCpfPropPet (void);
Pet* altCodPet (void);
Pet* altNomePet (void);
Pet* altEspPet (void);
Pet* altDataNascPet (void);
Pet* altSexoPet (void);
Pet* altCamposPet (void);
Pet* excluirPet (void);
void exibirPets (Pet* pet);

void menuAgendamentos (void);
void menuAgendarServicos (void);

void menuInformacoes (void);


int main (void) {

    login ();
    getchar();
    return 0;
}


void login(){
	system("MODE con cols=80 lines=24");
    system("color 3F");
    char op;
    int posx = 4;
    int posy = 6;
	char c;
	char login[] = "raquel@";
	char senha[] = "12345"; 
	int a = 10;
	int b = 10;
	int i = 0;
	int verifica_senha = 0;
	while(verifica_senha == 0){
  	move_cursor(30,1,"::: LOGIN :::");
    move_cursor(5,6,"Login: ");
    gets(login);
    move_cursor(5,8,"Senha: ");
    while((c = getch()) != 13){ 
		senha[i] = c;
		i++;
		printf("*");  
    }
    senha[i] = '\0';
    i = 0;
    system("cls");
    a = strcmp(login,"raquel@");
    b = strcmp(senha,"12345");
    if(a == 0 && b == 0){
    menuPrincipal();
    verifica_senha = 1;
    }else{
		move_cursor(5,12,"Senha invalida!");
      fflush(stdout);		
	}
    printf("\n");
	} 
}

void menuPrincipal (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    char op;
    int posx = 4;
    int posy = 6;

    do {
        system("cls");
		move_cursor(31,1,"::: SIG PET SHOP :::");
        move_cursor(30,2,"::: MENU PRINCIPAL :::");
	    move_cursor(5,6,"1 - Cliente");
	    move_cursor(5,8,"2 - Pet");
	    move_cursor(5,10,"3 - Agendamentos");
	    move_cursor(5,12,"4 - Informacoes sobre o Sistema");
	    move_cursor(5,14,"Sair");
	    move_cursor(5,18,"Selecione uma opcao e tecle ENTER\n");
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
                if (posy < 14) {
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
                    menuPet ();
                }                                
                if (posy == 10) {
                    menuAgendamentos ();
                }                
                if (posy == 12) {
                    menuInformacoes ();
                }
                if (posy == 14) {
                    exit(EXIT_SUCCESS);
                }
            break;
		}

    }while(1);
    getchar();
}

void menuCliente () {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    char op;
    int posx = 4;
    int posy = 6;
    Cliente* cli;
    
    do {
        system("cls");
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
                    cli = cadastrarCliente ();
                    salvarCliente (cli);
	            }         
				if (posy == 8) {
                    cli = pesquisarCliente ();
                    verCliente (cli);
                }                
                if (posy == 10) {
                	menuAlterarCliente ();
                }                
                if (posy == 12) {
                    cli = excluirCliente ();
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


Cliente* cadastrarCliente (void) {
	Cliente* cli;
    char resp;
    int posx = 4;
    int posy = 6;
    cli = (Cliente*) malloc(sizeof(Cliente));

    system("MODE con cols=80 lines=24");
    system("color 3F");
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
	return cli;
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


Cliente* pesquisarCliente (void) {
    FILE* fp;
    char procurado[15];
    int achou;
    Cliente* cli;

    fp = fopen("cliente.dat", "rb");
    cli = (Cliente*) malloc(sizeof(Cliente));

    if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
    system("MODE con cols=80 lines=24");
    system("color 3F");
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
    return cli;
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
    system("MODE con cols=80 lines=24");
    system("color 3F");
    char op;
    int posx = 4;
    int posy = 6;
    Cliente* cli;

    do {
		system("cls");
        move_cursor(30,1,"::: MENU ALTERAR CLIENTE :::");
	    move_cursor(5,6,"1 - Codigo Cliente");
	    move_cursor(5,8,"2 - Nome");
	    move_cursor(5,10,"3 - CPF");
	    move_cursor(5,12,"4 - Endereco");
	    move_cursor(5,14,"5 - Telefone");
	    move_cursor(5,16,"6 - Todos os Campos");
	    move_cursor(5,18,"Menu Cliente");
	    move_cursor(38,18,"Sair");
	    move_cursor(5,21,"Selecione a opcao a ser alterada e tecle ENTER\n");
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
					cli = altCodCliente ();
	            }         
				if (posy == 8) {
					cli = altNomeCliente ();
                }                
                if (posy == 10) {
                	cli = altCpfCliente ();
                }             
                if (posy == 12) {
                	cli = altEndCliente ();
                }                
                if (posy == 14) {
					cli = altTelCliente (); 
                }
                if (posy == 16) {
					cli = altCamposCliente ();
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

Cliente* altCodCliente (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 7, posy = 6;
	Cliente* cli;

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
			move_cursor(8,10,"Codigo alterado com sucesso\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");	
    	} else {
			move_cursor(8,10,"Codigo nao alterado\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);
    getchar();
    getchar();
    return cli;
}


Cliente* altNomeCliente (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Cliente* cli;
	
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
			move_cursor(8,10,"Nome alterado com sucesso\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");	
    	} else {
			move_cursor(8,10,"Nome nao alterado\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);
    getchar();
    getchar();
    return cli;
}


Cliente* altCpfCliente (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Cliente* cli;
	
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
			move_cursor(8,10,"CPF alterado com sucesso\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");	
    	} else {
			move_cursor(8,10,"CPF nao alterado\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);
    getchar();
    getchar();
    return cli;
}


Cliente* altEndCliente (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
	Cliente* cli;

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
			move_cursor(8,10,"Endereco alterado com sucesso\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");	
    	} else {
			move_cursor(8,10,"Endereco nao alterado\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);
    getchar();
    getchar();
    return cli;
}


Cliente* altTelCliente (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Cliente* cli;
	
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
			move_cursor(8,10,"Telefone alterado com sucesso\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");	
    	} else {
			move_cursor(8,10,"Telefone nao alterado\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);
    getchar();
    getchar();
    return cli;
}


Cliente* altCamposCliente (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Cliente* cli;
	
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
			move_cursor(8,18,"Campos alterados com sucesso\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");	
    	} else {
			move_cursor(8,18,"Campos nao alterados\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);
    getchar();
    getchar();
    return cli;
}


Cliente* excluirCliente (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    Cliente* cli;
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	
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
			
			move_cursor(8,10,"Cliente excluido com sucesso\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");	
    	} else {
			move_cursor(8,10,"Cliente nao excluido\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(cli);
    getchar();
    getchar();
    return cli;
}


void exibirClientes (Cliente* cli) {
    system("MODE con cols=80 lines=24");
	system("color 3F");
    FILE* fp;
	fp = fopen("cliente.dat", "rb");
  
	if(fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
	}
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


void menuPet (void) {
    system("MODE con cols=80 lines=24");
	system("color 3F");
    char op;
    int posx = 4;
    int posy = 6;
    Pet* pet;

    do {
        system("cls");
        move_cursor(30,1,"::: MENU PET :::");
	    move_cursor(5,6,"1 - Cadastrar");
	    move_cursor(5,8,"2 - Pesquisar");
	    move_cursor(5,10,"3 - Alterar");
	    move_cursor(5,12,"4 - Excluir");
	    move_cursor(5,14,"5 - Exibir Todos");
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
                    pet = cadastrarPet ();
                    salvarPet (pet);
	            }         
				if (posy == 8) {
                    pet = pesquisarPet ();
                    verPet (pet);
                }                
                if (posy == 10) {
                	menuAlterarPet ();
                }                
                if (posy == 12) {
                    pet = excluirPet ();
                }                
                if (posy == 14) {
                    exibirPets (pet);
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


Pet* cadastrarPet (void) {
	Pet* pet;
    char resp;
    int posx = 4;
    int posy = 6;
    pet = (Pet*) malloc(sizeof(Pet));

    system("MODE con cols=80 lines=24");
    system("color 3F");
    move_cursor(30,1,"::: CADASTRO DE PET :::");
    move_cursor(5,4,"Codigo Pet: ");
	scanf(" %d", &pet->cod);
    move_cursor(5,6,"Nome do Proprietario: ");
	scanf(" %50[^\n]", pet->nomeProp);
	move_cursor(5,8,"CPF do Proprietario: ");
    scanf(" %15[^\n]", pet->cpfProp);
	move_cursor(5,10,"Nome: ");
	scanf(" %10[^\n]", pet->nome);
	move_cursor(5,12,"Especie: ");
	scanf(" %10[^\n]", pet->esp);
	move_cursor(5,14,"Data de Nascimento: ");
	scanf(" %40[^\n]", pet->datanasc);
	move_cursor(5,16,"Sexo: ");
	scanf(" %20[^\n]", pet->sexo);
	move_cursor(posx, posy, " ");
	move_cursor(5,18,"Deseja salvar o cadastro (S/N)? ");
	scanf("%c", &resp);
	
	resp = toupper(getche());
	
	if (resp == 'S') {
		pet->status = 'c';
		salvarPet (pet);
		move_cursor(5,21,"Cadastro salvo, tecle ENTER para voltar ao MENU PET\n");			
	} else {
		move_cursor(5,21,"Cadastro cancelado, tecle ENTER para voltar ao MENU PET\n");
	}
	getchar();
	return pet;
}

void salvarPet (Pet* pet) {
	FILE* fp; 
	fp = fopen("pet.dat", "ab"); 
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit (EXIT_FAILURE);
	
	}
	fwrite(pet, sizeof(Pet), 1, fp);
	fclose(fp); 
		
}


Pet* pesquisarPet (void) {
    FILE* fp;
    char procurado[15];
    int achou;
    Pet* pet;

    fp = fopen("pet.dat", "rb");
    pet = (Pet*) malloc(sizeof(Pet));

    if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
    system("MODE con cols=80 lines=24");
    system("color 3F");
    move_cursor(30,1,"::: PESQUISAR PET :::");
	printf("\n\n\n");
	move_cursor(8,5,"Digite o CPF do Propietario: ");
	scanf("%15[^\n]", procurado);

    achou = 0;
	while((!achou) && (fread(pet, sizeof(Pet), 1, fp)))  {
   		if ((strcmp(pet->cpfProp, procurado) == 0) && (pet->status == 'c')){
    		achou = 1;
   		}
  	}
	fclose(fp);
	if (achou){
		verPet (pet);
        getchar();
		move_cursor(8,21,"Tecle ENTER para voltar ao MENU PET\n");
  	}else{
		move_cursor(8,21,"Pet nao cadastrado, tecle ENTER para voltar ao MENU PET\n");
	}
	getchar();
    return pet;
}


void verPet (Pet* pet) {
	printf("\n");
    printf("\n\tNome do Proprietario: %s\n", pet->nomeProp);
    printf("\n\tCodigo Pet: %d\n", pet->cod);
	printf("\n\tNome: %s\n", pet->nome);
	printf("\n\tEspecie: %s\n", pet->esp);
	printf("\n\tData de Nascimento: %s\n", pet->datanasc);
	printf("\n\tSexo: %s\n", pet->sexo);
    printf("\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
}


void menuAlterarPet (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    char op;
    int posx = 4;
    int posy = 4;
    Pet* pet;

    do {
		system("cls");
        move_cursor(30,1,"::: MENU ALTERAR PET :::");
        move_cursor(5,4,"1 - Nome do Proprietario");
	    move_cursor(5,6,"2 - CPF do Proprientario");
	    move_cursor(5,8,"3 - Codigo Cliente");
	    move_cursor(5,10,"4 - Nome");
	    move_cursor(5,12,"5 - Especie");
	    move_cursor(5,14,"6 - Data de Nascimento");
	    move_cursor(5,16,"7 - Sexo");
	    move_cursor(5,18,"8 - Todos os Campos");
	    move_cursor(5,20,"Menu Pet");
	    move_cursor(38,20,"Sair");
	    move_cursor(5,22,"Selecione uma opcao a ser alterada e tecle ENTER\n");
        move_cursor(posx, posy, ">");
        
        op = toupper(getch());
		
		switch(op){
			case 'H':
                if (posy > 4) {
                    move_cursor(posx, posy, " ");
                    posy-=2;
                    move_cursor(posx, posy, ">");            
                }
            break;
			case 'P':
                if (posy < 20) {
                    move_cursor(posx, posy, " ");
                    posy+=2;
                    move_cursor(posx, posy, ">"); 
                }
            break;
			case 'M':  
                if ((posx < 38) && (posy == 20)){
                move_cursor(posx, posy, " ");
                posx+=33;
                move_cursor(posx, posy, ">");             
                }  
            break; 
			case 'K':          
				if ((posx > 5) && (posy == 20)){
                    move_cursor(posx, posy, " ");
                    posx-=33;
                    move_cursor(posx, posy, ">");              
                }
            break;
			case 13:
				if (posy == 4) {
					pet = altNomePropPet ();
	            }         
				if (posy == 6) {
					pet = altCpfPropPet ();
                }                
                if (posy == 8) {
                	pet = altCodPet ();
                }             
                if (posy == 10) {
                	pet = altNomePet (); 
                }                
                if (posy == 12) {
					pet = altEspPet ();
                }
                if (posy == 14) {
					pet = altDataNascPet ();
                }
                if (posy == 16) {
                    pet = altSexoPet ();
                }
                if (posy == 18) {
					pet = altCamposPet ();
                }
                if ((posx == 4) && (posy == 20)) {
                    menuPet ();
                }
                if ((posx == 37) && (posy == 20)) {
                    exit(EXIT_SUCCESS);
                }
            break;
		}
		
	}while(1);	
	getchar();

}


Pet* altCodPet (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Pet* pet;
	
	fp = fopen("pet.dat", "r+b");
	pet = (Pet*) malloc(sizeof(Pet));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
    move_cursor(30,1,"::: PESQUISAR PET :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Propietario do Pet: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(pet, sizeof(Pet), 1, fp)))  {
		if ((strcmp(pet->cpfProp, procurado) == 0) && (pet->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verPet (pet);
    	move_cursor(8,21,"Deseja alterar o codigo deste Pet (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERAR CODIGO DO PET :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
    		move_cursor(5,4,"Codigo Pet: ");
            scanf(" %d", &pet->cod);		
			pet->status = 'c';
			
			fseek(fp, menusUm*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, fp);
			move_cursor(8,18,"Codigo alterado com sucesso\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");	
    	} else {
			move_cursor(8,18,"Codigo nao alterado\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(pet);
    getchar();
    getchar();
    return pet;
}


Pet* altNomePropPet (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Pet* pet;
	
	fp = fopen("pet.dat", "r+b");
	pet = (Pet*) malloc(sizeof(Pet));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
    move_cursor(30,1,"::: PESQUISAR PET :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Propietario do Pet: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(pet, sizeof(Pet), 1, fp)))  {
		if ((strcmp(pet->cpfProp, procurado) == 0) && (pet->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verPet (pet);
    	move_cursor(8,21,"Deseja alterar o nome do propietario deste Pet (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERAR NOME DO PROPIETARIO :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
            move_cursor(5,6,"Nome do Proprietario: ");
            scanf(" %50[^\n]", pet->nomeProp);	
			pet->status = 'c';
			
			fseek(fp, menusUm*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, fp);
			move_cursor(8,18,"Nome do propietario alterado com sucesso\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");	
    	} else {
			move_cursor(8,18,"Nome do propietario nao alterado\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(pet);
    getchar();
    getchar();
    return pet;
}


Pet* altCpfPropPet (void) {
system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Pet* pet;
	
	fp = fopen("pet.dat", "r+b");
	pet = (Pet*) malloc(sizeof(Pet));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
    move_cursor(30,1,"::: PESQUISAR PET :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Propietario do Pet: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(pet, sizeof(Pet), 1, fp)))  {
		if ((strcmp(pet->cpfProp, procurado) == 0) && (pet->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verPet (pet);
    	move_cursor(8,21,"Deseja alterar o CPF deste Pet (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERAR CPF DO PROPIETARIO :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
            move_cursor(5,8,"CPF do Proprietario: ");
            scanf(" %15[^\n]", pet->cpfProp);		
			pet->status = 'c';
			
			fseek(fp, menusUm*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, fp);
			move_cursor(8,18,"CPF do propietario alterado com sucesso\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");	
    	} else {
			move_cursor(8,18,"CPF do propietario nao alterado\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(pet);
    getchar();
    getchar();
    return pet;
}


Pet* altNomePet (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Pet* pet;
	
	fp = fopen("pet.dat", "r+b");
	pet = (Pet*) malloc(sizeof(Pet));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
    move_cursor(30,1,"::: PESQUISAR PET :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Propietario do Pet: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(pet, sizeof(Pet), 1, fp)))  {
		if ((strcmp(pet->cpfProp, procurado) == 0) && (pet->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verPet (pet);
    	move_cursor(8,21,"Deseja alterar o nome deste Pet (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERAR NOME :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
            move_cursor(5,10,"Nome: ");
            scanf(" %10[^\n]", pet->nome);		
			pet->status = 'c';
			
			fseek(fp, menusUm*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, fp);
			move_cursor(8,18,"Nome alterado com sucesso\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");	
    	} else {
			move_cursor(8,18,"Nome nao alterado\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(pet);
    getchar();
    getchar();
    return pet;
}


Pet* altEspPet (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Pet* pet;
	
	fp = fopen("pet.dat", "r+b");
	pet = (Pet*) malloc(sizeof(Pet));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
    move_cursor(30,1,"::: PESQUISAR PET :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Propietario do Pet: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(pet, sizeof(Pet), 1, fp)))  {
		if ((strcmp(pet->cpfProp, procurado) == 0) && (pet->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verPet (pet);
    	move_cursor(8,21,"Deseja alterar a especie deste Pet (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERAR ESPECIE :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
            scanf(" %10[^\n]", pet->nome);
            move_cursor(5,12,"Especie: ");
            scanf(" %10[^\n]", pet->esp);		
			pet->status = 'c';
			
			fseek(fp, menusUm*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, fp);
			move_cursor(8,18,"especie alterada com sucesso\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");	
    	} else {
			move_cursor(8,18,"Especie nao alterada\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(pet);
    getchar();
    getchar();
    return pet;
}


Pet* altDataNascPet (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Pet* pet;
	
	fp = fopen("pet.dat", "r+b");
	pet = (Pet*) malloc(sizeof(Pet));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
    move_cursor(30,1,"::: PESQUISAR PET :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Propietario do Pet: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(pet, sizeof(Pet), 1, fp)))  {
		if ((strcmp(pet->cpfProp, procurado) == 0) && (pet->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verPet (pet);
    	move_cursor(8,21,"Deseja alterar a data de nascimento deste Pet (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERAR DATA DE NASCIMENTO :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
            move_cursor(5,14,"Data de Nascimento: ");
            scanf(" %40[^\n]", pet->datanasc);		
			pet->status = 'c';
			
			fseek(fp, menusUm*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, fp);
			move_cursor(8,18,"data de Nascimento alterada com sucesso\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");	
    	} else {
			move_cursor(8,18,"Data de Nasciemento nao alterada\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(pet);
    getchar();
    getchar();
    return pet;
}


Pet* altSexoPet (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Pet* pet;
	
	fp = fopen("pet.dat", "r+b");
	pet = (Pet*) malloc(sizeof(Pet));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
    move_cursor(30,1,"::: PESQUISAR PET :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Propietario do Pet: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(pet, sizeof(Pet), 1, fp)))  {
		if ((strcmp(pet->cpfProp, procurado) == 0) && (pet->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verPet (pet);
    	move_cursor(8,21,"Deseja alterar o sexo deste Pet (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERAR SEXO :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
            move_cursor(5,16,"Sexo: ");
            scanf(" %20[^\n]", pet->sexo);			
			pet->status = 'c';
			
			fseek(fp, menusUm*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, fp);
			move_cursor(8,18,"Sexo alterado com sucesso\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");	
    	} else {
			move_cursor(8,18,"Sexo nao alterados\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(pet);
    getchar();
    getchar();
    return pet;
}


Pet* altCamposPet (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	int posx = 4, posy = 6;
    Pet* pet;
	
	fp = fopen("pet.dat", "r+b");
	pet = (Pet*) malloc(sizeof(Pet));
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
  	}
    move_cursor(30,1,"::: PESQUISAR PET :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Propietario do Pet: ");
	scanf("%15[^\n]", procurado);
	
	achou = 0;
	while((!achou) && (fread(pet, sizeof(Pet), 1, fp)))  {
		if ((strcmp(pet->cpfProp, procurado) == 0) && (pet->status == 'c')){
    		achou = 1;
		}
	}
	if(achou) {
    	verPet (pet);
    	move_cursor(8,21,"Deseja alterar todos os campos deste Pet (S/N)? ");
    	scanf("%c", &resp);
    	
    	resp = toupper(getche());
        	
    	if (resp == 'S') {
    		system("cls");
			move_cursor(30,1,"::: ALTERANDO CAMPOS :::");
			printf("\n\n\n");
			move_cursor(posx, posy, " ");
    		move_cursor(5,4,"Codigo Pet: ");
            scanf(" %d", &pet->cod);
            move_cursor(5,6,"Nome do Proprietario: ");
            scanf(" %50[^\n]", pet->nomeProp);
            move_cursor(5,8,"CPF do Proprietario: ");
            scanf(" %15[^\n]", pet->cpfProp);
            move_cursor(5,10,"Nome: ");
            scanf(" %10[^\n]", pet->nome);
            move_cursor(5,12,"Especie: ");
            scanf(" %10[^\n]", pet->esp);
            move_cursor(5,14,"Data de Nascimento: ");
            scanf(" %40[^\n]", pet->datanasc);
            move_cursor(5,16,"Sexo: ");	
            scanf(" %20[^\n]", pet->sexo);		
			pet->status = 'c';
			
			fseek(fp, menusUm*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, fp);
			move_cursor(8,18,"Campos alterados com sucesso\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");	
    	} else {
			move_cursor(8,18,"Campos nao alterados\n");
            move_cursor(8,20,"tecle ENTER para voltar ao MENU ALTERAR PET\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(pet);
    getchar();
    getchar();
    return pet;
}


Pet* excluirPet (void) {
    system("MODE con cols=80 lines=24");
    system("color 3F");
    Pet* pet;
    FILE* fp;
	int achou;
	int menusUm = -1;
	char resp;
	char procurado[15];
	
	fp = fopen("pet.dat", "r+b");
	
	if (fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
	}
  	
	move_cursor(30,1,"::: PESQUISAR PET :::");
	printf("\n\n\n");
	move_cursor(8,6,"Digite o CPF do Propietario do Pet: ");
	scanf("%15[^\n]", procurado);
	pet = (Pet*) malloc(sizeof(Pet));
  	achou = 0;
	while((!achou) && (fread(pet, sizeof(Pet), 1, fp)))  {
   		if ((strcmp(pet->cpfProp, procurado) == 0) && (pet->status == 'c')){
    		achou = 1;
   		}
  	}
	if(achou) {
		verPet (pet);
		move_cursor(8,20,"Deseja excluir este pet (S/N)? ");
		scanf("%c", &resp);
		
		resp = toupper(getche());
		
		if(resp == 'S') {
			system("cls");
			move_cursor(30,1,"::: EXCLUINDO CADASTRO :::");
			pet->status = 'n';
			
			fseek(fp, menusUm*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, fp);
			
			move_cursor(8,10,"Pet excluido com sucesso\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");	
    	} else {
			move_cursor(8,10,"Pet nao excluido\n");
            move_cursor(8,12,"tecle ENTER para voltar ao MENU ALTERAR CLIENTE\n");
		}
    } else {
		printf("\n\n\n\n\n\n\tO CPF %s nao foi encontrado...\n", procurado);
	}
	fclose(fp);
	free(pet);
    getchar();
    getchar();
    return pet;
}

void exibirPets (Pet* pet) {
    system("MODE con cols=80 lines=24");
	system("color 3F");
    FILE* fp;
	fp = fopen("pet.dat", "rb");
  
	if(fp == NULL) {
		printf("\n\n\tErro na abertura do arquivo!\n");
		printf("\n\n\tEncerrando o programa...");
		exit(EXIT_FAILURE);
	}
	move_cursor(30,1,"::: EXIBIR PETS :::");
	printf("\n\n\n");
  
	pet = (Pet*) malloc(sizeof(Pet));
  
	while(fread(pet, sizeof(Pet), 1, fp)) {
		if (pet->status == 'c') {
			verPet(pet);
		}
	}
	fclose(fp);
	free(pet);
    getchar();
}




void menuAgendamentos (void) {
    system("MODE con cols=80 lines=24");
	system("color 3F");
    char op;
    int posx = 4;
    int posy = 6;

    do {
        system("cls");
        move_cursor(30,1,"::: MENU AGENDAMENTOS :::");
		move_cursor(5,6,"1 - Agendar Servico");
	    move_cursor(5,8,"2 - Pesquisar ");
	    move_cursor(5,10,"3 - Alterar");
	    move_cursor(5,12,"4 - Excluir");
	    move_cursor(5,14,"5 - Listar Todos");
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
                    menuAgendarServicos ();
	            }         
				if (posy == 8) {
                    
                }                
                if (posy == 10) {
                	   
                }                
                if (posy == 12) {
                    
                }                
                if (posy == 14) {
                    
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


void menuAgendarServicos (void) {
    system("MODE con cols=80 lines=24");
	system("color 3F");

    int posx = 4;
    int posy = 5;
	system("cls");
	move_cursor(30,1,"::: AGENDAR SERVICOS :::");
	move_cursor(5,6,"----------------|----------------------------------|-----------------");
	move_cursor(5,5,"PET SHOP");
	move_cursor(5,7,"Banho e Tosa");
	move_cursor(35,5,"CLINICA");
	move_cursor(35,7,"Consulta");
	move_cursor(35,8,"Exames");
	move_cursor(35,9,"Vacinas");
	move_cursor(35,10,"Vermifogos/Antipulgas");
	move_cursor(35,11,"Cirurgias");
	move_cursor(35,12,"Pesagens");
	move_cursor(65,5,"PRODUTOS");
	move_cursor(65,7,"Racao");
	move_cursor(65,8,"Brinquedos");

	getchar();
}


void menuInformacoes (void) {
    system("MODE con cols=80 lines=24");
	system("color 3F");
    char op;
    int posx = 4;
    int posy = 16;

    do {
        system("cls");
        move_cursor(20,1,"::: MENU INFORMACOES SOBRE O SISTEMA :::");
        move_cursor(5,5,"Versao: 2.0.0");
        move_cursor(5,6,"Desenvolvido por Raquel Lima Fernandes");
        move_cursor(5,7,"Para o Projeto da Disciplina de Programacao");
        move_cursor(5,8,"Professor Flavius Gorgonio");
        move_cursor(5,9,"UFRN/CERES Campus Caico, BSI 2019.2");
        move_cursor(5,10,"Data de Terminio parte 02: 29/10/2019");
        move_cursor(5,12,"Codigo Disponivel em: https://github.com/raquel-lima/SIG-Projeto");
	    move_cursor(5,16,"Menu Principal");
        move_cursor(38,16,"Sair");

	    move_cursor(5,20,"Selecione uma opcao e tecle ENTER\n");
        move_cursor(posx, posy, ">");

        op = toupper(getch());

        switch(op){
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

void move_cursor (int x, int y, char c[30]) { 
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x,y};
    SetConsoleCursorPosition(hStdout, position);
    printf("%s", c);   
}

