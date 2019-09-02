#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

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
int escolha = 0,qtdClientes,tamClientes;
Cliente *clientes;

// Declaração das funções 
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
  setlocale(LC_ALL,"Portuguese");
  menuPrincipal();
  return 0;
}

// Exito ao realizar uma operação
void sucesso(){
  printf("\tOperação realizada com sucesso!\n\n\n\n");
}

// Menu principal
void menuPrincipal(){
  do{
  	system("cls");
  	system("color F0");
    puts("\t---------------------------------------");
    puts("\t            PET SHOP CONTROL           ");
    puts("\t---------------------------------------");
    printf("\n\n\n");
    puts("\t1 - Cadastros");
    puts("\t2 - Agenda");
    puts("\t3 - Financeiro");
    puts("\t4 - Informações sobre o Sistema");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a opção desejada >>> ");
    fflush(stdin);
    scanf("%d", &escolha);
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
        printf("\tOpção inválida!\n\n\n");
        fflush(stdin);
    }getchar();
  }while (escolha != 0);
}

// Menu cadastros
void menuCadastros(){
  do{
  	system("cls");
  	system("color F0");
    puts("\t---------------------------------------");
    puts("\t   PET SHOP CONTROL - CADASTROS        ");
    puts("\t---------------------------------------");
    printf("\n\n\n");
    puts("\t1 - Cliente");
    puts("\t2 - Serviço");
    puts("\t3 - Produto");
    puts("\t4 - Voltar");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a opção desejada >>> ");
    fflush(stdin);
    scanf("%d", &escolha);
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
        printf("\tOpção inválida!\n\n\n");
        fflush(stdin);
    }getchar();
  }while (escolha != 0);
}

// Menu Agenda 
void menuAgenda(){
  do{
  	system("cls");
  	system("color F0");
  	puts("\t---------------------------------------");
    puts("\t       PET SHOP CONTROL - AGENDA       ");
    puts("\t---------------------------------------");
    printf("\n\n\n");
    puts("\t1 - Novo Agendamento");
    puts("\t2 - Pesquisar Agendamento");
    puts("\t3 - Listar Agendamentos");
    puts("\t4 - Alterar Agendamento");
    puts("\t5 - Excluir Agendamento");
    puts("\t6 - Voltar");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a opção desejada >>> ");
    fflush(stdin);
    scanf("%d", &escolha);
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
        printf("\tOpção inválida!\n\n\n");
        fflush(stdin);
    }getchar();
  }while (escolha != 0);
}

// Menu Financeiro
void menuFinanca(){
	do{
  	system("cls");
  	system("color F0");
    puts("\t---------------------------------------");
    puts("\t     PET SHOP CONTROL - FINANCEIRO     ");
    puts("\t---------------------------------------");
    printf("\n\n\n");
    puts("\t1 - Relatóio Diário");
    puts("\t2 - Relatório Semanal");
    puts("\t3 - Relatório Mensal");
    puts("\t4 - Relatório Semestral");
    puts("\t5 - Relatóio Anual");
    puts("\t6 - Ver todos");
    puts("\t7 - Voltar");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a opção desejada >>> ");
    fflush(stdin);
    scanf("%d", &escolha);
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
        printf("\tOpção inválida!\n\n\n");
        fflush(stdin);
    }getchar();
  }while (escolha != 0);
}

// Memu Sistema
void menuSistema(){
  	system("cls");
  	system("color F0");
    puts("\t---------------------------------------");
    puts("\t        INFORMAÇÕES DO SISTEMA         ");
    puts("\t---------------------------------------");
    printf("\n\n\n");
    puts("\t VERSÃO: 1.0 ");
	puts("\t DESENVOLVIDO POR RAQUEL LIMA FERNANDES");
	puts("\t PARA PROJETO DA DISCIPLINA DE PROGRAMAÇÃO");
	puts("\t PROFESSOR FLÁVIUS GORGONIO");
	printf("\t UFRN/CERES CAMPUS CAICÓ, BS1 2019.2 \n\n");
	puts("\t DATA DE TÉRMINO PARTE 01: 30/8/2019");
	printf("\t CÓDIGO DISPONÍVEL EM: https://github.com/raquel-lima/SIG-Projeto \n\n\n");
    puts("\t 1 - Voltar");
    printf("\t 0 - Sair\n\n");
    printf("\tPor favor, digite a opção desejada >>> ");
    fflush(stdin);
    scanf("%d", &escolha);
    switch (escolha){
      case 1:
        menuPrincipal();
        break;
      case 0:
        exit(1);
      default:
        printf("\tOpção inválida!\n\n\n");
        fflush(stdin);
    }getchar();
}

// Submenu cliente
void submenuCliente(){
  do{
    system("cls");
    system("color F0");
    puts("\t---------------------------------------");
    puts("\t       PET SHOP CONTROL - CLIENTE      ");
    puts("\t---------------------------------------");
    printf("\n\n\n");
    puts("\t1 - Novo Cliente");
    puts("\t2 - Pesquisar Cliente");
    puts("\t3 - Listar Cliente");
    puts("\t4 - Alterar Cliente");
    puts("\t5 - Excluir Cliente");
    puts("\t6 - Voltar");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a opção desejada >>> ");
    fflush(stdin);
    scanf("%d", &escolha);
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
        printf("\tOpção inválida!\n\n\n");
        fflush(stdin);
    }getchar();
  }while (escolha != 0);
}

//submenu serviços
void submenuServicos(){
  do{
  	system("cls");
  	system("color F0");
    puts("\t---------------------------------------");
    puts("\t               SERVIÇOS                ");
    puts("\t---------------------------------------");
    printf("\n\n\n");
    puts("\t1 - Clínica");
    puts("\t2 - Produto");
    puts("\t3 - Pet Shop");
    puts("\t4 - Voltar");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a opção desejada >>> ");
    fflush(stdin);
    scanf("%d", &escolha);
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
        printf("\tOpção inválida!\n\n\n");
        fflush(stdin);
    }
  }while (escolha != 0);
}

// Submenu produtos
void submenuProdutos(){
  do{
  	system("cls");
  	system("color F0");
    puts("\t---------------------------------------");
    puts("\t       PET SHOP CONTROL - PRODUTOS     ");
    puts("\t---------------------------------------");
    printf("\n\n\n");
    puts("\t1 - Novo Produto");
    puts("\t2 - Pesquisar Produtos");
    puts("\t3 - Listar Produtos");
    puts("\t4 - Alterar Produto");
    puts("\t5 - Excluir Produto");
    puts("\t6 - Voltar");
    puts("\t0 - Sair\n\n");
    printf("\tPor favor, digite a opção desejada >>> ");
    fflush(stdin);
    scanf("%d", &escolha);
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
        printf("\tOpção inválida!\n\n\n");
        fflush(stdin);
    }getchar();
  }while (escolha != 0);
}

// Recebendo dados cadastro: cliente, endereço, animal
Cliente receberCliente(){
	Cliente cli;
	system("cls");
  	system("color F0");
    puts("\t---------------------------------------");
    puts("\t            CADASTRO CLIENTE           ");
    puts("\t---------------------------------------");
    printf("\n\n\n");
    printf("\tData: ");
    fflush(stdin);
    scanf("%[^\n]s",&cli.data);
    printf("\tNome: ");
    fflush(stdin);
    scanf("%[^\n]s",&cli.nome);
    printf("\tCPF: ");
    fflush(stdin);
    scanf("%[^\n]s",&cli.cpf);
    printf("\tRG: ");
    fflush(stdin);
    scanf("%[^\n]s",&cli.rg);
    printf("\tTelefone: ");
    fflush(stdin);
    scanf("%[^\n]s",&cli.telefone);
    printf("\tEmail: ");
    fflush(stdin);
    scanf("%[^\n]s",&cli.email);
    
    cli.end = receberEndereco();
    cli.ani = receberAnimal();
    
    sucesso();
    getch();
    return cli;	
}

Endereco receberEndereco(){
	Endereco end;

    printf("\tRua: ");
    fflush(stdin);
    scanf("%[^\n]s",&end.rua);
    printf("\tBairro: ");
    fflush(stdin);
    scanf("%[^\n]s",&end.bairro);
    printf("\tNº: ");
    fflush(stdin);
    scanf("%[^\n]s",&end.numero);
    printf("\tCEP: ");
    fflush(stdin);
    scanf("%[^\n]s",&end.cep);
    printf("\tCidade: ");
    fflush(stdin);
    scanf("%[^\n]s",&end.cidade);
    printf("\tEstado: ");
    fflush(stdin);
    scanf("%[^\n]s",&end.estado);
    
    return end;	
}

Animal receberAnimal(){
	Animal ani;
	
	system("cls");
  	system("color F0");
    puts("\t---------------------------------------");
    puts("\t             CADASTRO ANIMAL           ");
    puts("\t---------------------------------------");
    printf("\n\n\n");
    printf("\tNome: ");
    fflush(stdin);
    scanf("%[^\n]s",&ani.nomea);
    printf("\tEspécie: ");
    fflush(stdin);
    scanf("%[^\n]s",&ani.especie);
    printf("\tSexo: ");
    fflush(stdin);
    scanf("%[^\n]s",&ani.sexo);
    printf("\tRaça: ");
    fflush(stdin);
    scanf("%[^\n]s",&ani.raca);
    printf("\tIdade: ");
    fflush(stdin);
    scanf("%[^\n]s",&ani.idade);
    
    return ani;	
}

