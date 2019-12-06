#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "pet.h"


int menuPrincipal (void); 
void menuPet (void);
Pet* inserePet (void);
void salvaPet (Pet*);
void exibePet (Pet*);
void listaPets (Pet*);
void buscaPet (void);
void alteraPet (void);
void editaNomeResponsavelPet (void);
void editaCPFResponsavelPet (void);
void editaCodigoPet (void);
void editaNomePet (void);
void editaEspeciePet (void);
void editaDataNascimentoPet (void);
void editaSexoPet (void);
void editaObservacoesPet (void);
void excluirPet (void);

int dataCadastroPet(Pet*);


void menuPet (void) {
    Pet* pet;
	int op;
	do { 
		system("cls || clear");
        printf("\n\t------------------------------------\n");
        printf("\t\t\t   PET");
        printf("\n\t------------------------------------\n\n\n");
		puts("\t1. Cadastrar Novo Pet");
        puts("\t2. Exibir Pets");
        puts("\t3. Pesquisar Pet");
        puts("\t4. Alterar Cadastro");
        puts("\t5. Excluir Cadastro");
        puts("\t6. Menu Principal");
		puts("\t0. Sair");
        puts("\t----------------------------------");
		printf("\tSelecine uma opcao >>> ");
		scanf("%d", &op);

            switch (op) {
                case 1:
                    pet = inserePet ();
                    break;
                case 2:
                    listaPets (pet);
                    break;
                case 3:
                    buscaPet ();
                    break;
                case 4:
                    alteraPet ();
                    break;
                case 5:
               		excluirPet ();
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


Pet* inserePet (void) {
	Pet* pet;
	char resp;
	struct tm *info;
	time_t segundos;

    pet = (Pet*) malloc(sizeof(Pet));

    system("cls || clear");
    printf("\n\t------------------------------------\n");
    printf("\t\t\t   NOVO PET");
    printf("\n\t------------------------------------\n\n\n");
	printf("\tNome do Responsavel: ");
	scanf("	%51[^\n]", pet->nomeResponsavel);
	printf("\tCPF do Responsavel: ");
	scanf("	%12[^\n]", pet->cpfResponsavel);
	printf("\tCodigo do Pet: ");
	scanf("	%3[^\n]", pet->codigo);
	printf("\tNome: ");
	scanf("	%10[^\n]", pet->nome);
	printf("\tEspecie: ");
	scanf("	%10[^\n]", pet->especie);
	printf("\tData de Nasciemto: ");
	scanf("	%9[^\n]", pet->datanasc);
	printf("\tSexo [M ou F]: ");
	scanf("	%2[^\n]", pet->sexo);
	printf("\tObservacoes sobre o Pet: ");
	scanf("	%100[^\n]", pet->observacoes);

	printf("\n\n\tDeseja salvar o cadastro? (S ou N) ");
	scanf("%s",&resp);
	
	if (resp == 'S' || resp == 's') {   
		time(&segundos);
		info = localtime(&segundos);
		strftime(pet->data, 31, "%d/%m/%Y as %X", info);
		pet->dia = info->tm_mday;
		pet->mes = info->tm_mon;
		pet->ano = info->tm_year; 

	    salvaPet (pet); 
		printf("\n\tCadastro realizado com sucesso!\n");
    } else {
        printf("\n\tCadastro cancelado!\n");
    }
    return pet;
    getchar();
	getchar();
}


void salvaPet (Pet* pet) {
    FILE* arqp; 
	pet->status = 'a';

	arqp = fopen("pet.txt", "at"); 
	
	if (arqp == NULL) {
        printf("\n\n\n");
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...\n");
		exit (1);
	
	}

	fwrite(pet, sizeof(Pet), 1, arqp);
	fclose(arqp);
}


void exibePet (Pet* pet) {

	if ((pet == NULL)||(pet->status == 'd')) {
		printf("\tPet nao Cadastrado!\n");
	} else {
		printf("\n\tPet cadastrado em: %s \n", pet->data);
		printf("\n\tNome do Respeonsavel Legal: %s", pet->nomeResponsavel);
		printf("\n\tCPF do Respeonsavel Legal: %c%c%c.%c%c%c.%c%c%c-%c%c", pet->cpfResponsavel[0],
		pet->cpfResponsavel[1],pet->cpfResponsavel[2],pet->cpfResponsavel[3],pet->cpfResponsavel[4],
		pet->cpfResponsavel[5],pet->cpfResponsavel[6],pet->cpfResponsavel[7],pet->cpfResponsavel[8],
		pet->cpfResponsavel[9],pet->cpfResponsavel[10]);
		printf("\n\tCodigo Pet: %s", pet->codigo);
		printf("\n\tNome: %s", pet->nome);
		printf("\n\tEspecie: %s",pet->especie);
		printf("\n\tData Nascimento: %c%c/%c%c/%c%c%c%c",pet->datanasc[0],pet->datanasc[1],pet->datanasc[2],
		pet->datanasc[3],pet->datanasc[4],pet->datanasc[5],pet->datanasc[6],pet->datanasc[7]);
		printf("\n\tObservacoes sobre o Pet: %s",pet->observacoes);
	    printf("\n\t------------------------------------------------\n");
	}
}


void listaPets(Pet* pet){
	FILE* arqp;

	arqp = fopen("pet.txt", "rt");
	pet = (Pet*) malloc(sizeof(Pet));

	if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t------------------------------------------------\n");
	printf("\t\t\t   LISTA DE PETS");
	printf("\n\t------------------------------------------------\n\n\n");
	while (fread(pet, sizeof(Pet), 1, arqp)) {
		if (pet->status == 'a') {
			exibePet (pet); 
		}
	}

	fclose(arqp);
	free(pet);
	getchar();
	getchar();
}


void buscaPet (void) {
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
	printf("\n\t-----------------------------------\n");
	printf("\t\t\t   PESQUISA PET");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF Responsavel Legal pelo Pet: ");
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


void alteraPet (void){
	int op;
	do{ 
		system("cls||clear");
		printf("\n\t-----------------------------------\n");
		printf("\t\t\t   ALTERAR DADOS DO PET");
		printf("\n\t-----------------------------------\n\n\n");
		puts("\t1. Nome do Responsavel Legal");
        puts("\t2. CPF do Responsavel Legal");
		puts("\t3. Codigo do Pet");
        puts("\t4. Nome");
        puts("\t5. Especie");
        puts("\t6. Data de Nascimento");
        puts("\t7. Sexo");
		puts("\t8. Observacoes sobre o Pet");
        puts("\t9. Menu Cliente");
		puts("\t0. Sair");
		puts("\t-------------------------------------");
		printf("\tSelecine uma opcao >>> ");
		scanf("%d", &op);

		switch(op){
			case 1:
				editaNomeResponsavelPet();
				break;
			case 2:
                editaCPFResponsavelPet();
				break;
			case 3:
				editaCodigoPet();
				break;
			case 4:
                editaNomePet();
				break;
			case 5:
				editaEspeciePet();
				break;
			case 6:
				editaDataNascimentoPet();
				break;
			case 7:
				editaSexoPet();
				break;
			case 8:
				editaObservacoesPet();
				break;
			case 9:
				menuPet();
			case 0:
				exit(0);
				break;
			default:
				puts("\tOpcao invalida. Tente novamente!\n");
            break;

		}

	}while(op != 0);
    getchar();
}


void editaNomeResponsavelPet (void) {
    FILE* arqp;
    Pet* pet;
    char busca[12];
	char resp;
    int achou;

	arqp = fopen("pet.txt", "r+t");
	pet = (Pet*) malloc(sizeof(Pet));
	
    if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t  PESQUISA RESPONSAVEL PELO PET");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Resposnsavel Legal pelo Pet: ");
	scanf(" %12[^\n]", busca);

    achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')) {
    		achou = 1;
   		}
  	}
	
	if(achou){
		exibePet (pet);
		printf("\tDeseja realmente editar o nome do responsavel legal pelo pet? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t\t   ALTERANDO NOME");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo Nome: ");
			scanf(" %51[^\n]",pet->nomeResponsavel);
			pet->status = 'a';
			fseek(arqp, -1*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, arqp);
			printf("\n\tNome alterado com sucesso!\n");
		} else {
			printf("\n\tO nome do responsavel legal permanece inalterado!\n");
		}
		
  	} else {
		printf("\n\n\tCPF nao cadastrado\n");
	}
	fclose(arqp);
	free(pet);
	getchar();
	getchar();
}


void editaCPFResponsavelPet (void) {
    FILE* arqp;
    Pet* pet;
    char busca[12];
	char resp;
    int achou;

	arqp = fopen("pet.txt", "r+t");
	pet = (Pet*) malloc(sizeof(Pet));
	
    if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t  PESQUISA RESPONSAVEL PELO PET");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Resposnsavel Legal pelo Pet: ");
	scanf(" %12[^\n]", busca);
 
    achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')) {
    		achou = 1;
   		}
  	}

	if (achou) {
		exibePet (pet);
		printf("\tDeseja realmente editar o cpf do responsavel legal pelo pet? (S ou N) ");
		scanf("%s",&resp);
	
		if (resp == 'S' || resp == 's') {   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t\t   ALTERANDO CPF");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo CPF: ");
			scanf(" %12[^\n]",pet->cpfResponsavel);
			pet->status = 'a';
			fseek(arqp, -1*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, arqp);
			printf("\n\tCPF alterado com sucesso!\n");

		} else {
			printf("\n\tO cpf do responsavel legal permanece inalterado!\n");
		}
		
  	} else {
		printf("\n\n\tCPF nao cadastrado\n");
	}

	fclose(arqp);
	free(pet);
	getchar();
	getchar();
}


void editaCodigoPet (void) {
    FILE* arqp;
    Pet* pet;
    char busca[12];
	char resp;
    int achou;

	arqp = fopen("pet.txt", "r+t");
	pet = (Pet*) malloc(sizeof(Pet));
	
    if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t  PESQUISA RESPONSAVEL PELO PET");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Resposnsavel Legal pelo Pet: ");
	scanf(" %12[^\n]", busca);
  
    achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')){
    		achou = 1;
   		}
  	}

	if (achou) {
		exibePet (pet);
		printf("\tDeseja realmente editar o codigo do pet? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t\t   ALTERANDO CODIGO");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo Codigo: ");
			scanf(" %3[^\n]",pet->codigo);
			pet->status = 'a';
			fseek(arqp, -1*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, arqp);
			printf("\n\tCodigo alterado com sucesso!\n");

		} else {
			printf("\n\tO codigo do responsavel legal permanece inalterado!\n");
		}
		
  	}else{
		printf("\n\n\tCPF nao cadastrado\n");
	}
	fclose(arqp);
	free(pet);
	getchar();
	getchar();
}


void editaNomePet (void) {
    FILE* arqp;
    Pet* pet;
    char busca[12];
	char resp;
    int achou;

	arqp = fopen("pet.txt", "r+t");
	pet = (Pet*) malloc(sizeof(Pet));

    if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t  PESQUISA RESPONSAVEL PELO PET");
	printf("\t\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Resposnsavel Legal pelo Pet: ");
	scanf(" %12[^\n]", busca);

    achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')) {
    		achou = 1;
   		}
  	}

	if(achou){
		exibePet (pet);
		printf("\tDeseja realmente editar o nome do pet? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t\t   ALTERANDO NOME");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo Nome: ");
			scanf(" %10[^\n]",pet->nome);
			pet->status = 'a';
			fseek(arqp, -1*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, arqp);
			printf("\n\tNome alterado com sucesso!\n");
		} else {
			printf("\n\tO nome do responsavel legal permanece inalterado!\n");
		}
		
  	} else {
		printf("\n\n\tCPF nao cadastrado\n");
	}
	fclose(arqp);
	free(pet);
	getchar();
	getchar();
}


void editaEspeciePet (void) {
    FILE* arqp;
    Pet* pet;
    char busca[12];
	char resp;
    int achou;

	arqp = fopen("pet.txt", "r+t");
	pet = (Pet*) malloc(sizeof(Pet));

    if(arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t  PESQUISA RESPONSAVEL PELO PET");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Resposnsavel Legal pelo Pet: ");
	scanf(" %12[^\n]", busca);

    achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')) {
    		achou = 1;
   		}
  	}

	if (achou) {
		exibePet (pet);
		printf("\tDeseja realmente editar a especie do pet? (S ou N) ");
		scanf("%s",&resp);
	
		if (resp == 'S' || resp == 's') {   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t\t   ALTERANDO ESPECIE");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNova Especie: ");
			scanf(" %10[^\n]",pet->especie);
			pet->status = 'a';
			fseek(arqp, -1*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, arqp);
			printf("\n\tEspecie alterado com sucesso!\n");
		} else {
			printf("\n\tA Especie permanece inalterado!\n");
		}
		
  	} else {
		printf("\n\n\tCPF nao cadastrado\n");
	}

	fclose(arqp);
	free(pet);
	getchar();
	getchar();
}


void editaDataNascimentoPet (void) {
    FILE* arqp;
    Pet* pet;
    char busca[12];
	char resp;
    int achou;

	arqp = fopen("pet.txt", "r+t");
	pet = (Pet*) malloc(sizeof(Pet));

    if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t  PESQUISA RESPONSAVEL PELO PET");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Resposnsavel Legal pelo Pet: ");
	scanf(" %12[^\n]", busca);
    
    achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')) {
    		achou = 1;
   		}
  	}

	if (achou) {
		exibePet (pet);
		printf("\tDeseja realmente editar a data de nascimento do pet? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t  ALTERANDO DATA DE NASCIMENTO");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNova Data de Nasciemento: ");
			scanf(" %9[^\n]",pet->datanasc);
			pet->status = 'a';
			fseek(arqp, -1*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, arqp);
			printf("\n\tData de nascimento alterada com sucesso!\n");
		} else {
			printf("\n\tA Data de nascimento permanece inalterada!\n");
		}
		
  	} else {
		printf("\n\n\tCPF nao cadastrado\n");
	}
	fclose(arqp);
	free(pet);
	getchar();
	getchar();
}


void editaSexoPet (void) {
    FILE* arqp;
    Pet* pet;
    char busca[12];
	char resp;
    int achou;

	arqp = fopen("pet.txt", "r+t");
	pet = (Pet*) malloc(sizeof(Pet));

    if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t  PESQUISA RESPONSAVEL PELO PET");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Resposnsavel Legal pelo Pet: ");
	scanf(" %12[^\n]", busca);

    achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')) {
    		achou = 1;
   		}
  	}

	if (achou) {
		exibePet (pet);
		printf("\tDeseja realmente editar o campo sexo do pet? (S ou N) ");
		scanf("%s",&resp);
	
		if (resp == 'S' || resp == 's') {   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t      ALTERANDO O SEXO DO PET");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo Sexo: ");
			scanf(" %2[^\n]",pet->sexo);
			pet->status = 'a';
			fseek(arqp, -1*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, arqp);
			printf("\n\tCampo sexo alterado com sucesso!\n");

		} else {
			printf("\n\tO campo sexo permanece inalterado!\n");
		}
		
  	} else {
		printf("\n\n\tCPF nao cadastrado\n");
	}
	fclose(arqp);
	free(pet);
	getchar();
	getchar();
}



void editaObservacoesPet (void) {
    FILE* arqp;
    Pet* pet;
    char busca[12];
	char resp;
    int achou;

	arqp = fopen("pet.txt", "r+t");
	pet = (Pet*) malloc(sizeof(Pet));

    if(arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t  PESQUISA RESPONSAVEL PELO PET");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Resposnsavel Legal pelo Pet: ");
	scanf(" %12[^\n]", busca);

    achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')) {
    		achou = 1;
   		}
  	}

	if(achou){
		exibePet (pet);
		printf("\tDeseja realmente editar as observacoes do pet? (S ou N) ");
		scanf("%s",&resp);
	
		if (resp == 'S' || resp == 's') {   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t  ALTERANDO AS OBSERVACOES DO PET");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo Observacao: ");
			scanf(" %100[^\n]",pet->observacoes);
			pet->status = 'a';
			fseek(arqp, -1*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, arqp);
			printf("\n\tObservacoes alteradas com sucesso!\n");
		} else {
			printf("\n\tAs observacoes permanecem inalteradas!\n");
		}
		
  	} else {
		printf("\n\n\tCPF nao cadastrado\n");
	}
	fclose(arqp);
	free(pet);
	getchar();
	getchar();
}


void editaTodosPet (void) {
    FILE* arqp;
    Pet* pet;
    char busca[12];
	char resp;
    int achou;

	arqp = fopen("pet.txt", "r+t");
	pet = (Pet*) malloc(sizeof(Pet));

    if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls||clear");
	printf("\n\t-----------------------------------\n");
	printf("\t  PESQUISA RESPONSAVEL PELO PET");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Resposnsavel Legal pelo Pet: ");
	scanf(" %12[^\n]", busca);

    achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')) {
    		achou = 1;
   		}
  	}

	if (achou) {
		exibePet (pet);
		printf("\tDeseja realmente editar todos os campos do pet? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			system("cls||clear");
			printf("\n\t-----------------------------------\n");
			printf("\t  ALTERANDO TODOS OS CAMPOS DO PET");
			printf("\n\t-----------------------------------\n\n\n");
			printf("\n\tNovo Observacao: ");
			scanf(" %100[^\n]",pet->observacoes);
			pet->status = 'a';
			fseek(arqp, -1*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, arqp);
			printf("\n\tCampos alterados com sucesso!\n");

		} else {
			printf("\n\tOs campos permanecem inalterados!\n");
		}
		
  	} else {
		printf("\n\n\tCPF nao cadastrado\n");
	}
	fclose(arqp);
	free(pet);
	getchar();
	getchar();
}


void excluirPet (void) {
	FILE* arqp;
	Pet* pet;
    char busca[12];
	char resp;
    int achou;

	arqp = fopen("pet.txt", "r+t");
	pet = (Pet*) malloc(sizeof(Pet));

    if (arqp == NULL) {
		printf("\tErro na abertura do arquivo...\n");
		printf("\tEncerrando o programa...");
		exit(1);
  	}
	system("cls || clear");
	printf("\n\t-----------------------------------\n");
	printf("\t   PESQUISA RESPONSAVEL PELO PET");
	printf("\n\t-----------------------------------\n\n\n");
	printf("\tDigite o CPF do Resposnsavel legal pelo Pet: ");
	scanf(" %12[^\n]", busca);

    achou = 0;
	while ((!achou) && (fread(pet, sizeof(Pet), 1, arqp))) {
   		if ((strcmp(pet->cpfResponsavel, busca) == 0) && (pet->status == 'a')) {
    		achou = 1;
   		}
  	}

	if (achou) {
		exibePet (pet);
		printf("\tDeseja excluir deste pet? (S ou N) ");
		scanf("%s",&resp);
	
		if(resp == 'S' || resp == 's'){   
			pet->status = 'd';
			fseek(arqp, -1*sizeof(Pet), SEEK_CUR);
			fwrite(pet, sizeof(Pet), 1, arqp);
			printf("\n\tPet excluido com sucesso!\n");

		} else {
			printf("\n\tO pet permanece cadastrado!\n");
		}
		
  	} else {
		printf("\n\n\tCliente nao cadastrado\n");
	}
	fclose(arqp);
	free(pet);
	getchar();
	getchar();
}


int dataCadastroPet(Pet* pet){
	struct tm t;
	t.tm_mday = pet->dia;
	t.tm_mon = pet->mes;
	t.tm_year = pet->ano;
	t.tm_hour = 0;
	t.tm_min= 0;
	t.tm_sec = 1;
	t.tm_isdst = -1;
	int retorno = mktime(&t);

	return retorno/86400;
}


