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
void exibeAgendamento (Agendamento*);
void listaAgendamentos(void);
void buscaAgendamento(void);
void alteraAgendamento (void);
void editaCodigoAgendamento (void);
void editaServicoAgendamento (void);
void editaHorarioAgendamento (void);
void excluirAgendamento (void);
void editaDataAgendamento (void);
int dataCadastroAgendamento (Agendamento*);
int dataSistema(void);


void menuAgendamento (void) {
    int op;
    do {
        system("cls || clear");
        printf("\n\t------------------------------------\n");
        printf("\tAGENDAMENTO                             ");
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
                listaAgendamentos();
                break;
            case 3:
                buscaAgendamento();
                break;
            case 4:
                alteraAgendamento();
                break;
            case 5:
                excluirAgendamento();
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
        printf("\tAGENDAR SERVICO                         ");
        printf("\n\t------------------------------------\n\n\n");
        printf("\t  PET SHOP        |    CLINICA\n");
        puts("\t1. Banho          |    4. Vacina");
        puts("\t2. Tosa           |    5. Exame");
        puts("\t3. Pesagem        |    6. Consulta");
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
                buscaInfomacoesAgendamento ();
                break;
            case 3:
                buscaInfomacoesAgendamento ();
                break;
            case 4:
                buscaInfomacoesAgendamento ();
                break;
            case 5:
                buscaInfomacoesAgendamento ();
                break;
            case 6:
                buscaInfomacoesAgendamento ();
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
    Agendamento* age;
    char busca[12];
    int achou;
    struct tm *info;
    time_t segundos;

	arqp = fopen("pet.txt", "rt");
	pet = (Pet*) malloc(sizeof(Pet));

    age = (Agendamento*) malloc(sizeof(Agendamento));

    if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t------------------------------------------\n");
	printf("\tAGENDAMENTO DE SERVICO                        ");
	printf("\n\t------------------------------------------\n\n\n");

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
        exibePet(pet);
        strcpy(age->nomeDoPet, pet->nome);
        strcpy(age->cpfCliente, pet->cpfResponsavel);
        printf("\n\tID Agendamento: ");
        scanf(" %3[^\n]",age->codigo);
        printf("\n\tServico: ");
        scanf(" %20[^\n]",age->tipoServico);
        printf("\n\tValor a  apagar R$: ");
        scanf(" %f",&age->valorServico);
        printf("\n\tHoraio: ");
        scanf(" %10[^\n]",age->horarioServico);
        printf("\n\tData: ");
        scanf(" %15[^\n]",age->dataProgramada);

        time(&segundos);
        info = localtime(&segundos);
        strftime(age->data, 31, "%d/%m/%Y as %X", info);
        age->dia = info->tm_mday;
        age->mes = info->tm_mon;
        age->ano = info->tm_year; 
        salvaAgendamento(age);
        printf("\n\tAgendamento realizado com sucesso!\n");

  	} else {
		printf("\n\n\tPet nao cadastrado\n");
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



void exibeAgendamento (Agendamento* age) {

    if ((age == NULL)||(age->status == 'd')) {
        printf("\tSem agendamentos programados!\n");
    } else {
        printf("\n\tServico agendado em: %s \n", age->data);
        printf("\n\tNome Pet: %s", age->nomeDoPet);
        printf("\n\tCPF do Responsavel pelo Pet: %c%c%c.%c%c%c.%c%c%c-%c%c", age->cpfCliente[0],
        age->cpfCliente[1],age->cpfCliente[2],age->cpfCliente[3],age->cpfCliente[4],
        age->cpfCliente[5],age->cpfCliente[6],age->cpfCliente[7],age->cpfCliente[8],
        age->cpfCliente[9],age->cpfCliente[10]);
        printf("\n\tCodigo Agendamento: %s", age->codigo);
        printf("\n\tServico Agendado: %s", age->tipoServico);
        printf("\n\tHoraio Programado: %c%ch%c%cmin", age->horarioServico[0],
        age->horarioServico[1],age->horarioServico[2],age->horarioServico[3]);
        printf("\n\tData Programada: %c%c/%c%c/%c%c%c%c", age->dataProgramada[0],
        age->dataProgramada[1],age->dataProgramada[2],age->dataProgramada[3],
        age->dataProgramada[4],age->dataProgramada[5],age->dataProgramada[6],
        age->dataProgramada[7]);
        printf("\n\tValor a pagar pelo Servico R$ %2.f ",age->valorServico);
        printf("\n\t------------------------------------------------\n");
    }
}


void listaAgendamentos(void){
    FILE* arqa;
    Agendamento* age;
    arqa = fopen("age.txt", "rt");
    age = (Agendamento*) malloc(sizeof(Agendamento));

    if (arqa == NULL) {
        printf("\tErro na abertura do arquivo...\n");
        printf("\tEncerrando o programa...");
        exit(1);
    }
    system("cls||clear");
    printf("\n\t------------------------------------------------\n");
    printf("\tLISTA DE AGENDAMENTOS                               ");
    printf("\n\t------------------------------------------------\n\n\n");
    while (fread(age, sizeof(Agendamento), 1, arqa)) {
        if (age->status == 'a') {
            exibeAgendamento (age); 
        }
    }

    fclose(arqa);
    free(age);
    getchar();
    getchar();
}



void buscaAgendamento(void){
    FILE* arqa;
    Agendamento* age;
    char busca[3];
    int achou;

    arqa = fopen("age.txt", "rb");
    age = (Agendamento*) malloc(sizeof(Agendamento));

    if (arqa == NULL) {
        printf("\tErro na abertura do arquivo...\n");
        printf("\tEncerrando o programa...");
        exit(1);
    }
    system("cls || clear");
    printf("\n\t------------------------------------\n");
    printf("\tPESQUISA AGENDAMENTO                    ");
    printf("\n\t------------------------------------\n\n\n");
    printf("\tDigite o Codigo do Agendamento: ");
    scanf(" %3[^\n]", busca);
    achou = 0;
    while((!achou) && (fread(age, sizeof(Agendamento), 1, arqa))){
        if ((strcmp(age->codigo, busca) == 0) && (age->status == 'a')){
            achou = 1;
        }
    }
    fclose(arqa);
    if (achou) {
        exibeAgendamento(age);

    } else {
        printf("\n\n\tAgendamento nao cadastrado\n");
    }

    free(age);
    getchar();
    getchar();
}


void alteraAgendamento (void) {
    int op;
    do { 
        system("cls||clear");
        printf("\n\t-----------------------------------\n");
        printf("\tALTERAR DADOS DO AGENDAMENTO           ");
        printf("\n\t-----------------------------------\n\n\n");
        puts("\t1. Codigo do Agendamento");
        puts("\t2. Tipo de Servico");
        puts("\t3. Horario Programado");
        puts("\t4. Data Programada");
        puts("\t5. Menu Agendamento");
        puts("\t0. Sair");
        puts("\t-------------------------------------");
        printf("\tSelecine uma opcao >>> ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                editaCodigoAgendamento ();
                break;
            case 2:
                editaServicoAgendamento ();
                break;
            case 3:
                editaHorarioAgendamento ();
                break;
            case 4:
                editaDataAgendamento ();
                break;
            case 5:
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



void editaCodigoAgendamento (void) {
    FILE* arqa;
    Agendamento* age;
    char busca[3];
    char resp;
    int achou;

    arqa = fopen("age.txt", "r+t");
    age = (Agendamento*) malloc(sizeof(Agendamento));
    
    if (arqa == NULL) {
        printf("\tErro na abertura do arquivo...\n");
        printf("\tEncerrando o programa...");
        exit(1);
    }
    system("cls||clear");
    printf("\n\t-----------------------------------\n");
    printf("\tPESQUISA AGENDAMENTO                 ");
    printf("\n\t-----------------------------------\n\n\n");
    printf("\tDigite o Codigo do Agendamento: ");
    scanf(" %3[^\n]", busca);
  
    achou = 0;
    while ((!achou) && (fread(age, sizeof(Agendamento), 1, arqa))) {
        if ((strcmp(age->codigo, busca) == 0) && (age->status == 'a')){
            achou = 1;
        }
    }

    if (achou) {
        exibeAgendamento (age);
        printf("\tDeseja realmente editar o codigo do agendamento? (S ou N) ");
        scanf("%s",&resp);
    
        if(resp == 'S' || resp == 's'){   
            system("cls||clear");
            printf("\n\t-----------------------------------\n");
            printf("\tALTERANDO CODIGO                       ");
            printf("\n\t-----------------------------------\n\n\n");
            printf("\n\tNovo Codigo: ");
            scanf(" %3[^\n]",age->codigo);
            age->status = 'a';
            fseek(arqa, -1*sizeof(Agendamento), SEEK_CUR);
            fwrite(age, sizeof(Agendamento), 1, arqa);
            printf("\n\tCodigo alterado com sucesso!\n");

        } else {
            printf("\n\tO codigo do agendamento permanece inalterado!\n");
        }
        
    }else{
        printf("\n\n\tServico nao agendado\n");
    }
    fclose(arqa);
    free(age);
    getchar();
    getchar();
}



void editaServicoAgendamento (void) {
    FILE* arqa;
    Agendamento* age;
    char busca[3];
    char resp;
    int achou;

    arqa = fopen("age.txt", "r+t");
    age = (Agendamento*) malloc(sizeof(Agendamento));
    
    if (arqa == NULL) {
        printf("\tErro na abertura do arquivo...\n");
        printf("\tEncerrando o programa...");
        exit(1);
    }
    system("cls||clear");
    printf("\n\t-----------------------------------\n");
    printf("\tPESQUISA AGENDAMENTO                 ");
    printf("\n\t-----------------------------------\n\n\n");
    printf("\tDigite o codigo do agendamento: ");
    scanf(" %3[^\n]", busca);
  
    achou = 0;
    while ((!achou) && (fread(age, sizeof(Agendamento), 1, arqa))) {
        if ((strcmp(age->codigo, busca) == 0) && (age->status == 'a')){
            achou = 1;
        }
    }

    if (achou) {
        exibeAgendamento (age);
        printf("\tDeseja realmente editar o tipo de servico agendado? (S ou N) ");
        scanf("%s",&resp);
    
        if(resp == 'S' || resp == 's'){   
            system("cls||clear");
            printf("\n\t-----------------------------------\n");
            printf("\tALTERANDO SERVICO                      ");
            printf("\n\t-----------------------------------\n\n\n");
            printf("\n\tNovo Servico: ");
            scanf(" %20[^\n]",age->tipoServico);
            printf("\n\tValor a pagar R$: ");
            scanf(" %f",&age->valorServico);
            age->status = 'a';
            fseek(arqa, -1*sizeof(Agendamento), SEEK_CUR);
            fwrite(age, sizeof(Agendamento), 1, arqa);
            printf("\n\tServico alterado com sucesso!\n");

        } else {
            printf("\n\tO servico agendado permanece inalterado!\n");
        }
        
    }else{
        printf("\n\n\tServico nao agendado\n");
    }
    fclose(arqa);
    free(age);
    getchar();
    getchar();
}



void editaHorarioAgendamento (void) {
    FILE* arqa;
    Agendamento* age;
    char busca[3];
    char resp;
    int achou;

    arqa = fopen("age.txt", "r+t");
    age = (Agendamento*) malloc(sizeof(Agendamento));
    
    if (arqa == NULL) {
        printf("\tErro na abertura do arquivo...\n");
        printf("\tEncerrando o programa...");
        exit(1);
    }
    system("cls||clear");
    printf("\n\t-----------------------------------\n");
    printf("\tPESQUISA AGENDAMENTO                 ");
    printf("\n\t-----------------------------------\n\n\n");
    printf("\tDigite o codigo do agendamento: ");
    scanf(" %3[^\n]", busca);
  
    achou = 0;
    while ((!achou) && (fread(age, sizeof(Agendamento), 1, arqa))) {
        if ((strcmp(age->codigo, busca) == 0) && (age->status == 'a')){
            achou = 1;
        }
    }

    if (achou) {
        exibeAgendamento (age);
        printf("\tDeseja realmente editar o horario agendado? (S ou N) ");
        scanf("%s",&resp);
    
        if(resp == 'S' || resp == 's'){   
            system("cls||clear");
            printf("\n\t-----------------------------------\n");
            printf("\tALTERANDO HORARIO                      ");
            printf("\n\t-----------------------------------\n\n\n");
            printf("\n\tNovo Horario: ");
            scanf(" %10[^\n]",age->horarioServico);
            age->status = 'a';
            fseek(arqa, -1*sizeof(Agendamento), SEEK_CUR);
            fwrite(age, sizeof(Agendamento), 1, arqa);
            printf("\n\tHorario alterado com sucesso!\n");

        } else {
            printf("\n\tO horario agendado permanece inalterado!\n");
        }
        
    }else{
        printf("\n\n\tServico nao agendado\n");
    }
    fclose(arqa);
    free(age);
    getchar();
    getchar();
}


void editaDataAgendamento (void) {
    FILE* arqa;
    Agendamento* age;
    char busca[3];
    char resp;
    int achou;

    arqa = fopen("age.txt", "r+t");
    age = (Agendamento*) malloc(sizeof(Agendamento));
    
    if (arqa == NULL) {
        printf("\tErro na abertura do arquivo...\n");
        printf("\tEncerrando o programa...");
        exit(1);
    }
    system("cls||clear");
    printf("\n\t-----------------------------------\n");
    printf("\tPESQUISA AGENDAMENTO                 ");
    printf("\n\t-----------------------------------\n\n\n");
    printf("\tDigite o codigo do agendamento: ");
    scanf(" %3[^\n]", busca);
  
    achou = 0;
    while ((!achou) && (fread(age, sizeof(Agendamento), 1, arqa))) {
        if ((strcmp(age->cpfCliente, busca) == 0) && (age->status == 'a')){
            achou = 1;
        }
    }

    if (achou) {
        exibeAgendamento (age);
        printf("\tDeseja realmente editar a data agendada? (S ou N) ");
        scanf("%s",&resp);
    
        if(resp == 'S' || resp == 's'){   
            system("cls||clear");
            printf("\n\t-----------------------------------\n");
            printf("\tALTERANDO DATA                         ");
            printf("\n\t-----------------------------------\n\n\n");
            printf("\n\tNova Data: ");
            scanf(" %15[^\n]",age->dataProgramada);
            age->status = 'a';
            fseek(arqa, -1*sizeof(Agendamento), SEEK_CUR);
            fwrite(age, sizeof(Agendamento), 1, arqa);
            printf("\n\tData alterada com sucesso!\n");

        } else {
            printf("\n\tA data agendado permanece inalterado!\n");
        }
        
    }else{
        printf("\n\n\tServico nao agendado\n");
    }
    fclose(arqa);
    free(age);
    getchar();
    getchar();
}


void excluirAgendamento (void) {
    FILE* arqa;
    Agendamento* age;
    char busca[3];
    char resp;
    int achou;

    arqa = fopen("age.txt", "r+t");
    age = (Agendamento*) malloc(sizeof(Agendamento));

    if (arqa == NULL) {
        printf("\tErro na abertura do arquivo...\n");
        printf("\tEncerrando o programa...");
        exit(1);
    }
    system("cls || clear");
    printf("\n\t-----------------------------------\n");
    printf("\tPESQUISA AGENDAMENTO                   ");
    printf("\n\t-----------------------------------\n\n\n");
    printf("\tDigite o codigo do agendamento: ");
    scanf(" %3[^\n]", busca);

    achou = 0;
    while ((!achou) && (fread(age, sizeof(Agendamento), 1, arqa))) {
        if ((strcmp(age->codigo, busca) == 0) && (age->status == 'a')) {
            achou = 1;
        }
    }

    if (achou) {
        exibeAgendamento (age);
        printf("\tDeseja excluir deste agendamento? (S ou N) ");
        scanf("%s",&resp);
    
        if(resp == 'S' || resp == 's'){   
            age->status = 'd';
            fseek(arqa, -1*sizeof(Agendamento), SEEK_CUR);
            fwrite(age, sizeof(Agendamento), 1, arqa);
            printf("\n\tAgendamento excluido com sucesso!\n");

        } else {
            printf("\n\tAgendamento permanece cadastrado!\n");
        }
        
    } else {
        printf("\n\n\tAgendamento nao cadastrado\n");
    }
    fclose(arqa);
    free(age);
    getchar();
    getchar();
}



int dataCadastroAgendamento (Agendamento* age) {
    struct tm t;
    t.tm_mday = age->dia;
    t.tm_mon = age->mes;
    t.tm_year = age->ano;
    t.tm_hour = 0;
    t.tm_min= 0;
    t.tm_sec = 1;
    t.tm_isdst = -1;
    int retorno = mktime(&t);

    return retorno/86400;
}
