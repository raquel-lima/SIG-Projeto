#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Declaração das Estruturas
typedef struct endereco{
  char rua[40],bairro[30],numero[6],cep[9],cidade[20],estado[3];
} Endereco;

typedef struct animal{
  char nomea[40],especie[10],sexo[10],raca[20],idade[10];
} Animal;

typedef struct cliente{
  char data[11],nome[40],cpf[12],rg[10],telefone[11],email[20];
  Endereco end;
  Animal ani;
} Cliente; 

// Declaração das variáveis
int escolha = 0;

// Declaração das funções 
void login();
void menuPrincipal();
void menuCadastros();
void menuAgenda();
void menuFinanca();
void menuSistema();
void submenuCliente();
void submenuServicos();
void submenuProdutos();
Cliente receberCliente();
Endereco receberEndereco();
Animal receberAnimal();




// Inicio do main
int main (){
  login();
  return 0;
}

// Operação realizada com sucesso
void sucesso(){
  printf("\tOpera%c%co realizada com sucesso!\n\n\n\n",135,198);
  setbuf(stdin,NULL);
}

// Login
void login(){
  char c;
  char login[] = "raquel@";
  char senha[] = "12345"; 
  int a = 10;
  int b = 10;
  int i = 0;
  int verifica_senha = 0;
  while(verifica_senha == 0){
    printf("\t---------------------------------------\n");
    printf("\t   PET SHOP CONTROL - CADASTROS        \n");
    printf("\t---------------------------------------\n\n");
    printf("\tLogin: ");
    gets(login);
    printf("\tSenha: ");
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
			printf("\tSenha inv%clida!\n\n\n",160);
      fflush(stdout);		
		}
    printf("\n");
  } 
}


// Menu principal
void menuPrincipal(){
  do{
  	system("cls");
  	
    printf("\t---------------------------------------\n");
    printf("\t            PET SHOP CONTROL           \n");
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Cadastros\n");
    printf("\t2 - Agenda\n");
    printf("\t3 - Financeiro\n");
    printf("\t4 - Informa%c%ces sobre o Sistema\n",135,228);
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a op%c%co desejada >>> ",135,198);
    scanf("%d", &escolha);
    setbuf(stdin,NULL);
    switch (escolha){
      case 1:
        menuCadastros();
        break;
      case 2:
        menuAgenda();
        break;
      case 3:
        menuFinanca();
        break;
      case 4:
        menuSistema();
        break;
      case 0:
        exit(1);
      default:
        printf("\tOp%c%co inv%clida!\n\n\n",135,128,160);
        fflush(stdout);
    }getchar();
  }while (escolha != 0);
}

// Menu cadastros
void menuCadastros(){
  do{
  	system("cls");
  
    printf("\t---------------------------------------\n");
    printf("\t   PET SHOP CONTROL - CADASTROS        \n");
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Cliente\n");
    printf("\t2 - Servi%co\n",135);
    printf("\t3 - Produto\n");
    printf("\t4 - Voltar\n");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a op%c%co desejada >>> ",135,198);
    scanf("%d", &escolha);
    setbuf(stdin,NULL);
    switch (escolha){
      case 1:
        submenuCliente();
        break;
      case 2:
        submenuServicos();
        break;
      case 3:
        submenuProdutos();
        break;
      case 4:
        menuPrincipal();
        break;
      case 0:
        exit(1);
      default:
        printf("\tOp%c%co inv%clida!\n\n\n",135,128,160);
        fflush(stdout);
    }getchar();
  }while (escolha != 0);
}

// Menu Agenda 
void menuAgenda(){
  do{
  	system("cls");
  	
  	printf("\t---------------------------------------\n");
    printf("\t       PET SHOP CONTROL - AGENDA       \n");
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Novo Agendamento\n");
    printf("\t2 - Pesquisar Agendamento\n");
    printf("\t3 - Listar Agendamentos\n");
    printf("\t4 - Alterar Agendamento\n");
    printf("\t5 - Excluir Agendamento\n");
    printf("\t6 - Voltar\n");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a op%c%co desejada >>> ",135,198);
    scanf("%d", &escolha);
    setbuf(stdin,NULL);
    switch (escolha){
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        menuPrincipal();
        break;
      case 0:
        exit(1);
      default:
        printf("\tOp%c%co inv%clida!\n\n\n",135,128,160);
        fflush(stdout);
    }getchar();
  }while (escolha != 0);
}

// Menu Financeiro
void menuFinanca(){
	do{
  	system("cls");
  	
    printf("\t---------------------------------------\n");
    printf("\t     PET SHOP CONTROL - FINANCEIRO     \n");
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Relat%cio Di%crio\n",162,160);
    printf("\t2 - Relat%cio Semanal\n",162);
    printf("\t3 - Relat%cio Mensal\n",162);
    printf("\t4 - Relat%cio Semestral\n",162);
    printf("\t5 - Relat%cio Anual\n",162);
    printf("\t6 - Ver todos\n");
    printf("\t7 - Voltar\n");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a op%c%co desejada >>> ",135,198);
    scanf("%d", &escolha);
    setbuf(stdin,NULL);
    switch (escolha){
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        menuPrincipal();
        break;
      case 0:
        exit(1);
      default:
        printf("\tOp%c%co inv%clida!\n\n\n",135,128,160);
        fflush(stdout);
    }getchar();
  }while (escolha != 0);
}

// Memu Sistema
void menuSistema(){
  	system("cls");
  
    printf("\t---------------------------------------\n");
    printf("\t        INFORMA%c%cES DO SISTEMA         \n",128,229);
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t VERS%cO: 1.0 \n",199);
	  printf("\t DESENVOLVIDO POR RAQUEL LIMA FERNANDES\n");
	  printf("\t PARA PROJETO DA DISCIPLINA DE PROGRAMA%c%cO\n",128,199);
	  printf("\t PROFESSOR FL%cVIUS GORG%cNIO\n",181,226);
	  printf("\t UFRN/CERES CAMPUS CAIC%c, BS1 2019.2 \n\n",224);
	  printf("\t DATA DE T%cRMINO PARTE 01: 30/8/2019\n",144);
	  printf("\t C%cDIGO DISPON%cVEL EM: https://github.com/raquel-lima/SIG-Projeto \n\n\n",224,214);
    printf("\t 1 - Voltar\n");
    printf("\t 0 - Sair\n\n");
    printf("\tPor favor, digite a op%c%co desejada >>> ",135,198);
    scanf("%d", &escolha);
    setbuf(stdin,NULL);
    switch (escolha){
      case 1:
        menuPrincipal();
        break;
      case 0:
        exit(1);
      default:
        printf("\tOp%c%co inv%clida!\n\n\n",135,128,160);
        fflush(stdout);
    }getchar();
}

// Submenu cliente
void submenuCliente(){
  do{
    system("cls");
   
    printf("\t---------------------------------------\n");
    printf("\t       PET SHOP CONTROL - CLIENTE      \n");
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Novo Cliente\n");
    printf("\t2 - Pesquisar Cliente\n");
    printf("\t3 - Listar Cliente\n");
    printf("\t4 - Alterar Cliente\n");
    printf("\t5 - Excluir Cliente\n");
    printf("\t6 - Voltar\n");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a op%c%co desejada >>> ",135,198);
    scanf("%d", &escolha);
    setbuf(stdin,NULL);
    switch (escolha){
      case 1:
      	receberCliente();
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        menuCadastros();
        break;
      case 0:
        exit(1);
      default:
        printf("\tOp%c%co inv%clida!\n\n\n",135,128,160);
        fflush(stdout);
    }getchar();
  }while (escolha != 0);
}

//submenu serviços
void submenuServicos(){
  do{
  	system("cls");
  
    printf("\t---------------------------------------\n");
    printf("\t               SERVI%cOS                \n",128);
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Cl%cnica\n",161);
    printf("\t2 - Produto\n");
    printf("\t3 - Pet Shop\n");
    printf("\t4 - Voltar\n");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a op%c%co desejada >>> ",135,198);
    scanf("%d", &escolha);
    setbuf(stdin,NULL);
    switch (escolha){
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
      	menuCadastros();
        break;
      case 0:
        exit(EXIT_SUCCESS);
      default:
        printf("\tOp%c%co inv%clida!\n\n\n",135,128,160);
        fflush(stdout);
    }
  }while (escolha != 0);
}

// Submenu produtos
void submenuProdutos(){
  do{
  	system("cls");
  
    printf("\t---------------------------------------\n");
    printf("\t       PET SHOP CONTROL - PRODUTOS     \n");
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Novo Produto\n");
    printf("\t2 - Pesquisar Produtos\n");
    printf("\t3 - Listar Produtos\n");
    printf("\t4 - Alterar Produto\n");
    printf("\t5 - Excluir Produto\n");
    printf("\t6 - Voltar\n");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a op%c%co desejada >>> ",135,198);
    scanf("%d", &escolha);
    setbuf(stdin,NULL);
    switch (escolha){
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        menuCadastros();
        break;
      case 0:
        exit(1);
      default:
        printf("\tOp%c%co inv%clida!\n\n\n",135,128,160);
        fflush(stdout);
    }getchar();
  }while (escolha != 0);
}

// Recebendo dados cadastro: cliente, endereço, animal
Cliente receberCliente(){
	Cliente cli;
	system("cls");
  
  printf("\t---------------------------------------\n");
  printf("\t            CADASTRO CLIENTE           \n");
  printf("\t---------------------------------------\n");
  printf("\n\n\n");
  printf("\tData: ");
  scanf("%[^\n]s",&cli.data);
  setbuf(stdin,NULL);
  printf("\tNome: ");
  scanf("%[^\n]s",&cli.nome);
  setbuf(stdin,NULL);
  printf("\tCPF: ");
  scanf("%[^\n]s",&cli.cpf);
  setbuf(stdin,NULL);
  printf("\tRG: ");
  scanf("%[^\n]s",&cli.rg);
  setbuf(stdin,NULL);
  printf("\tTelefone: ");
  scanf("%[^\n]s",&cli.telefone);
  setbuf(stdin,NULL);
  printf("\tEmail: ");
  scanf("%[^\n]s",&cli.email);
  setbuf(stdin,NULL);
  
  cli.end = receberEndereco();
  cli.ani = receberAnimal();
  
  sucesso();
  getchar();
  return cli;	
}

Endereco receberEndereco(){
	Endereco end;

  printf("\tRua: ");
  scanf("%[^\n]s",&end.rua);
  setbuf(stdin,NULL);
  printf("\tBairro: ");
  scanf("%[^\n]s",&end.bairro);
  setbuf(stdin,NULL);
  printf("\tN%cmero: ",163);
  scanf("%[^\n]s",&end.numero);
  setbuf(stdin,NULL);
  printf("\tCEP: ");
  scanf("%[^\n]s",&end.cep);
  setbuf(stdin,NULL);
  printf("\tCidade: ");
  scanf("%[^\n]s",&end.cidade);
  setbuf(stdin,NULL);
  printf("\tEstado: ");
  scanf("%[^\n]s",&end.estado);
  setbuf(stdin,NULL);
  
  return end;	
}

Animal receberAnimal(){
	Animal ani;
	
	system("cls");
  
  printf("\t---------------------------------------\n");
  printf("\t             CADASTRO ANIMAL           \n");
  printf("\t---------------------------------------\n");
  printf("\n\n\n");
  printf("\tNome: ");
  scanf("%[^\n]s",&ani.nomea);
  setbuf(stdin,NULL);
  printf("\tEsp%ccie: ",130);
  scanf("%[^\n]s",&ani.especie);
  setbuf(stdin,NULL);
  printf("\tSexo: ");
  scanf("%[^\n]s",&ani.sexo);
  setbuf(stdin,NULL);
  printf("\tRa%ca: ",135);
  scanf("%[^\n]s",&ani.raca);
  setbuf(stdin,NULL);
  printf("\tIdade: ");
  scanf("%[^\n]s",&ani.idade);
  setbuf(stdin,NULL);
  
  return ani;	
}

