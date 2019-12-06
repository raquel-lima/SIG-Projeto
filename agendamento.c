<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "pet.h"
#include "agendamento.h"



int menuPrincipal (void);
void menuAgendamento (void);
void agendaServico (void);
void buscaInfomacoesAgendamento (void);
void salvaAgendamento (Agendamento*);


void menuAgendamento (void) {
    int op;

    do {
        system("cls || clear");
        printf("\n\t------------------------------------\n");
        printf("\t\t   AGENDAMENTO");
        printf("\n\t------------------------------------\n\n\n");
        puts("\t1. Agendar Servico");
        puts("\t2. Listar Agendamentos");
        puts("\t3. Pesquisar Agendamento");
        puts("\t4. Alterar Agendamento");
        puts("\t5. Excluir Agendamento");
        puts("\t6. Menu Principal");
        puts("\t0. Sair");
        puts("\t--------------------------------------");
		printf("\tSelecine uma opcao >>> ");
		scanf("%d", &op);

        switch(op){
            case 1:
                agendaServico ();
                break;
            case 2:
                //listaAgendamentos(age);
                break;
            case 3:
                //buscaAgendamento(age);
                break;
            case 4:
                //alteraAgendamento(age);
                break;
            case 5:
                //excluiAgendamento(age);
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
    getchar();
}


void agendaServico (void) {
    int op;
    do {
        system("cls || clear");
        printf("\n\t------------------------------------\n");
        printf("\t\t   AGENDAR SERVICO");
        printf("\n\t------------------------------------\n\n\n");
        printf("\t  PET SHOP        |     CLINICA\n");
        puts("\t1. Banho          |   4. Vacina");
        puts("\t2. Tosa           |   5. Exame");
        puts("\t3. Pesagem        |   6. Consulta");
        puts("");
        puts("\t7. Menu Agendamento");
        puts("\t0. Sair");
        puts("\t--------------------------------------");
		printf("\tSelecine uma opcao >>> ");
		scanf("%d", &op);

        switch(op){
            case 1:
                buscaInfomacoesAgendamento ();
                break;
            case 2:
                //listaAgendamentos(age);
                break;
            case 3:
                //buscaAgendamento(age);
                break;
            case 4:
                //alteraAgendamento(age);
                break;
            case 5:
                //excluiAgendamento(age);
                break;
            case 6:
                break;
            case 7:
                menuAgendamento ();
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


void buscaInfomacoesAgendamento (void) {
    FILE* arqp;
    Pet* pet;
    char busca[12];
    int achou;

	arqp = fopen("pet.txt", "rt");
	pet = (Pet*) malloc(sizeof(Pet));

    if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t------------------------------------------\n");
	printf("\t\t\t   SERVICO BANHO");
	printf("\n\t------------------------------------------\n");
	puts("\tFuncionario encarregado: Mercia dos Santos");
	puts("\tValor do Servico R$ 15,00");
	printf("\n\n");
	printf("\tDigite o CPF do Responsavel pelo Pet: ");
	scanf(" %12[^\n]", busca);

	achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')) {
    		achou = 1;
   		}
  	}

	fclose(arqp);
	if (achou) {
		exibePet (pet);
  	} else {
		printf("\n\n\tCliente nao cadastrado\n");
	}
	free(pet);
	getchar();
	getchar();
}


void salvaAgendamento (Agendamento* age) {
    FILE* arqa; 
	age->status = 'a';

	arqa = fopen("age.txt", "at"); 
	
	if (arqa == NULL) {
        printf("\n\n\n");
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...\n");
		exit (1);
	
	}

	fwrite(age, sizeof(Agendamento), 1, arqa);
	fclose(arqa);
}


=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "pet.h"
#include "agendamento.h"



int menuPrincipal (void);
void menuAgendamento (void);
void agendaServico (void);
void buscaInfomacoesAgendamento (void);
void salvaAgendamento (Agendamento*);


void menuAgendamento (void) {
    int op;

    do {
        system("cls || clear");
        printf("\n\t------------------------------------\n");
        printf("\t\t   AGENDAMENTO");
        printf("\n\t------------------------------------\n\n\n");
        puts("\t1. Agendar Servico");
        puts("\t2. Listar Agendamentos");
        puts("\t3. Pesquisar Agendamento");
        puts("\t4. Alterar Agendamento");
        puts("\t5. Excluir Agendamento");
        puts("\t6. Menu Principal");
        puts("\t0. Sair");
        puts("\t--------------------------------------");
		printf("\tSelecine uma opcao >>> ");
		scanf("%d", &op);

        switch(op){
            case 1:
                agendaServico ();
                break;
            case 2:
                //listaAgendamentos(age);
                break;
            case 3:
                //buscaAgendamento(age);
                break;
            case 4:
                //alteraAgendamento(age);
                break;
            case 5:
                //excluiAgendamento(age);
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
    getchar();
}


void agendaServico (void) {
    int op;
    do {
        system("cls || clear");
        printf("\n\t------------------------------------\n");
        printf("\t\t   AGENDAR SERVICO");
        printf("\n\t------------------------------------\n\n\n");
        printf("\t  PET SHOP        |     CLINICA\n");
        puts("\t1. Banho          |   4. Vacina");
        puts("\t2. Tosa           |   5. Exame");
        puts("\t3. Pesagem        |   6. Consulta");
        puts("");
        puts("\t7. Menu Agendamento");
        puts("\t0. Sair");
        puts("\t--------------------------------------");
		printf("\tSelecine uma opcao >>> ");
		scanf("%d", &op);

        switch(op){
            case 1:
                buscaInfomacoesAgendamento ();
                break;
            case 2:
                //listaAgendamentos(age);
                break;
            case 3:
                //buscaAgendamento(age);
                break;
            case 4:
                //alteraAgendamento(age);
                break;
            case 5:
                //excluiAgendamento(age);
                break;
            case 6:
                break;
            case 7:
                menuAgendamento ();
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


void buscaInfomacoesAgendamento (void) {
    FILE* arqp;
    Pet* pet;
    char busca[12];
    int achou;

	arqp = fopen("pet.txt", "rt");
	pet = (Pet*) malloc(sizeof(Pet));

    if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t------------------------------------------\n");
	printf("\t\t\t   SERVICO BANHO");
	printf("\n\t------------------------------------------\n");
	puts("\tFuncionario encarregado: Mercia dos Santos");
	puts("\tValor do Servico R$ 15,00");
	printf("\n\n");
	printf("\tDigite o CPF do Responsavel pelo Pet: ");
	scanf(" %12[^\n]", busca);

	achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')) {
    		achou = 1;
   		}
  	}

	fclose(arqp);
	if (achou) {
		exibePet (pet);
  	} else {
		printf("\n\n\tCliente nao cadastrado\n");
	}
	free(pet);
	getchar();
	getchar();
}


void salvaAgendamento (Agendamento* age) {
    FILE* arqa; 
	age->status = 'a';

	arqa = fopen("age.txt", "at"); 
	
	if (arqa == NULL) {
        printf("\n\n\n");
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...\n");
		exit (1);
	
	}

	fwrite(age, sizeof(Agendamento), 1, arqa);
	fclose(arqa);
}


>>>>>>> b5d60e3a370ffbb0b59cecef7751b9c05403dbb3
