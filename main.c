#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Declaração das Estruturas
typedef struct enderecoCadastro{
  char rua[40];
  char bairro[30];
  char numero[6];
  char cep[9];
  char cidade[20];
  char estado[3];
} Endereco;

typedef struct animalCadastro{
  char nomea[40];
  char especie[10];
  char sexo[10];
  char raca[20];
  char idade[10];
} Animal;

typedef struct clienteCadastro{
  char data[11];
  char nome[40];
  char cpf[12];
  char rg[10];
  char telefone[11];
  Endereco end;
  Animal ani;
} Pessoa; 

// Declaração das variáveis
int escolha = 0;
int qtdClientes;
int tamClientes;
Pessoa *clientes;

// Declaração das funções 
void menuPrincipal();
void menuCadastros();
void subMenuCliente();
Pessoa receberDadosCliente();
void inserirCliente();
Endereco receberDadosEndereco();
Animal receberDadosAnimal();
void subMenuServicos();
void subMenuProdutos();

// Inicio do main
int main (){
  setlocale(LC_ALL,"Portuguese");
  menuPrincipal();
  return 0;
}

// Exito ao realizar uma operação
void sucesso(){
  system("cls");
  printf("\tOperação realizada com sucesso!");
}

// Menu principal
void menuPrincipal(){
  do{
    system("cls");
    printf("\t---------------------------------------\n");
    printf("\t|           PET SHOP CONTROL          |\n");
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Cadastros\n");
    printf("\t2 - Agenda\n");
    printf("\t3 - Relatórios\n");
    printf("\t4 - Financeiro\n");
    printf("\t5 - Informações sobre o Sistema\n");
    printf("\t0 - Sair\n\n");
    printf("\tPor favor, digite a opção desejada >>> ");
    fflush(stdin);
    scanf("%d", &escolha);
    switch (escolha){
      case 1:
        menuCadastros();
        break;
      case 2:
        
        break;
      case 3:
        break;
      case 4:
        
        break;
      case 5:
        
        break;
      case 0:
        exit(1);
      default:
        printf("\tOpção inválida!\n\n");
        fflush(stdin);
    }system("pause");
  }while (escolha != 0);
}

// Menu cadastros
void menuCadastros(){
  do{
    system("cls");
    system("color A9");
    printf("\t---------------------------------------\n");
    printf("\t|  PET SHOP CONTROL - CADASTROS       |\n");
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Cliente\n");
    printf("\t2 - Serviço\n");
    printf("\t3 - Produto\n");
    printf("\t4 - Menu Principal\n");
    printf("\t0 - Sair");
    printf("\n\n");
    printf("\tPor favor, digite a opção desejada >>> ");
    fflush(stdin);
    scanf("%d", &escolha);
    switch (escolha){
      case 1:
        subMenuCliente();
        break;
      case 2:
      subMenuServicos();
        break;
      case 3:
        subMenuProdutos();
        break;
      case 4:
        menuPrincipal();
        break;
      case 0:
        exit(1);
      default:
        printf("\tOpção inválida!\n\n");
        fflush(stdin);
    }system("pause");
  }while (escolha != 0);
}

//Submenu cadastro de cliente
void subMenuCliente(){
  do{
    system("cls");
    system("color F4");
    printf("\t---------------------------------------\n");
    printf("\t|      PET SHOP CONTROL - CLIENTE     |\n");
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Novo Cliente\n");
    printf("\t2 - Pesquisar Cadastro\n");
    printf("\t3 - Listar Cadastros\n");
    printf("\t4 - Alterar Cadastro\n");
    printf("\t5 - Excluir Cadastro\n");
    printf("\t6 - Menu Principal\n");
    printf("\t0 - Sair");
    printf("\n\n");
    printf("\tPor favor, digite a opção desejada >>> ");
    fflush(stdin);
    scanf("%d", &escolha);
    switch (escolha){
      case 1:
        inserirCliente(receberDadosCliente());
        fflush(stdin);
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
        printf("\tOpção inválida!\n\n");
        fflush(stdin);
    }system("pause");
  }while (escolha != 0);
}

//Capturando dados do cliente
Pessoa receberDadosCliente(){
  Pessoa p;
  printf("\t---------------------------------------\n");
  printf("\t|           CADASTRO CLIENTE          |\n");
  printf("\t---------------------------------------\n");
  printf("\n\n\n");
  printf("Data: ");
  fgets(p.data,10,stdin);
  printf("Nome: "); 
  fgets(p.nome,40,stdin);
  printf("CPF: "); 
  fgets(p.cpf,11,stdin);
  printf("RG: ");
  fgets(p.rg,10,stdin);
  printf("Telefone: "); 
  fgets(p.telefone,11,stdin);

  p.end = receberDadosEndereco();
  p.ani = receberDadosAnimal();

  sucesso();
  getchar();
  return p;
}

// Capturando endereço
Endereco receberDadosEndereco(){
  Endereco e;
  printf("Rua: "); 
  fgets(e.rua,40,stdin);  
  printf("Bairro: "); 
  fgets(e.bairro,30,stdin);
  printf("Número: "); 
  fgets(e.numero,6,stdin);
  printf("CEP: "); 
  fgets(e.cep,8,stdin);
  printf("Cidade: ");
  fgets(e.cidade,20,stdin);
  printf("Estado: \n"); 
  fgets(e.estado,3,stdin);

  getchar();
  return e;
}

// Capturando dados do animal
Animal receberDadosAnimal(){
  Animal a;
  printf("\t---------------------------------------\n");
  printf("\t|            CADASTRO ANIMAL          |\n");
  printf("\t---------------------------------------\n");
  printf("\n\n\n");
  printf("Nome: "); 
  fgets(a.nomea,40,stdin);
  printf("Espécie: ");
  fgets(a.especie,40,stdin);
  printf("Sexo: "); 
  fgets(a.sexo,40,stdin);
  printf("Raça: "); 
  fgets(a.raca,40,stdin);
  printf("Idade: "); 
  fgets(a.idade,40,stdin);

  getchar();
  return a;
}
// Inserindo os dados do cliente
void inserirCliente(Pessoa p){

  if(qtdClientes == tamClientes){
    tamClientes *= 1.5;
    clientes = realloc(clientes, tamClientes*sizeof(Pessoa));
  }
  clientes[qtdClientes] = p;
  qtdClientes++;
}

void subMenuServicos(){
  do{
    system("cls");
    system("color F4");
    printf("\t---------------------------------------\n");
    printf("\t|      PET SHOP CONTROL - SERVIÇOS    |\n");
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Novo Serviço\n");
    printf("\t2 - Pesquisar Serviço\n");
    printf("\t3 - Listar Serviços\n");
    printf("\t4 - Alterar Serviço\n");
    printf("\t5 - Excluir Serviço\n");
    printf("\t6 - Menu Principal\n");
    printf("\t0 - Sair");
    printf("\n\n");
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
        printf("\tOpção inválida!\n\n");
        fflush(stdin);
    }system("pause");
  }while (escolha != 0);
}

void subMenuProdutos(){
  do{
    system("cls");
    system("color F4");
    printf("\t---------------------------------------\n");
    printf("\t|      PET SHOP CONTROL - PRODUTOS    |\n");
    printf("\t---------------------------------------\n");
    printf("\n\n\n");
    printf("\t1 - Novo Produto\n");
    printf("\t2 - Pesquisar Produtos\n");
    printf("\t3 - Listar Produtos\n");
    printf("\t4 - Alterar Produto\n");
    printf("\t5 - Excluir Produto\n");
    printf("\t6 - Menu Principal\n");
    printf("\t0 - Sair");
    printf("\n\n");
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
        printf("\tOpção inválida!\n\n");
        fflush(stdin);
    }system("pause");
  }while (escolha != 0);
}