#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "cliente.h"
#include "pet.h"
#include "agendamento.h"
#include "relatorios.h"
#include "sobre.h"
#include "validacoes.h"



int menuPrincipal (void);
void login (void);


int main (void) {
    login ();
    return 0;
}


void login (void){
    char c;
    char usuario[] = "raquel@";
    char senha[] = "12345"; 
    int a;
    int b;
    int i = 0;
    int verificaSenha = 0;
    while(verificaSenha == 0){
        system("cls||clear");
        printf("\n\t------------------------------------------\n");
        printf("\t  SISTEMA DE GERENCIAMENTO DE PET SHOP");
        printf("\n\t------------------------------------------\n\n\n");
        printf("\tUsurario: ");
        gets(usuario);
        printf("\n\tSenha: ");

        while((c = getch()) != 13){ 
            senha[i] = c;
            i++;
            printf("*");  
        }
    senha[i] = '\0';
    i = 0;
    a = strcmp(usuario,"raquel@");
    b = strcmp(senha,"12345");
        if(a == 0 && b == 0){
            menuPrincipal();
            verificaSenha = 1;
        }else{
            printf("\n\n\n\n\n\tSenha invalida. Tente novamente!\n");
        }
    } 
}


int menuPrincipal () {
    int op;
    do {
        system("cls || clear");
        printf("\n\t------------------------------------\n");
        printf("\t\t   MENU PRINCIPAL");
        printf("\n\t------------------------------------\n\n\n");
        puts("\t1. Cliente");
        puts("\t2. Pet");
        puts("\t3. Agendamento");
        puts("\t4. Relatorios");
        puts("\t5. Informacoes sobre Sistema");
        puts("\t0. Sair");
        puts("\t----------------------------------");
        printf("\tDigite uma opcao >>> ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            menuCliente ();
            break;
        case 2:
            menuPet ();
            break;
        case 3:
            menuAgendamento ();
            break;
        case 4:
            menuRelatorios ();
            break;
        case 5:
            menuSobre ();
            break;
        case 0:
            exit(0);
            break;    
        default:
            puts("\tOpcao invalida. Tente novamente!\n");
            break;
        }
        
    } while (op != 0);

    return op;
}




