<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"


int menuPrincipal (void);
void menuSobre (void);



void menuSobre (void) {
    int op;
    do{
       system("cls||clear");
		printf("\n\t------------------------------------------------\n");
		printf("\t   INFORMACOES SOBRE O SISTEMA");
		printf("\n\t------------------------------------------------\n\n\n");
        puts("\tVersao: 3.0.0");
        puts("\tDesenvolvido por: Raquel Lima Fernandes");
        puts("\tE-mail: raquel.discente@gmail.com");
        puts("\tDCT1106P Programacao: Professor Flavius Gorgonio");
        puts("\tUFRN/CERES Campus Caico, BSI 2019.2");
        puts("\tData de Terminio parte 03: 01/11/2019");
        puts("\tCodigo Disponivel em: https://github.com/raquel-lima/SIG-Projeto");
        printf("\n\n");
        puts("\t1. Menu Principal");
        puts("\t0. Encerrar Programa");
        puts("\t------------------------------------------------------");
        printf("\tDigite uma opcao >>> ");
        scanf("%d", &op);

        switch(op){
            case 1:
                menuPrincipal ();
                break;
            case 0:
                exit(0);
                break;
            default:
                puts("\tOpcao invalida. Tente novamente!\n");
            	break;
        }

    } while(op != 0);
    getchar();
}
=======
#include <stdio.h>
#include <stdlib.h>
#include "sobre.h"


int menuPrincipal (void);
void menuSobre (void);



void menuSobre (void) {
    int op;
    do{
       system("cls||clear");
		printf("\n\t------------------------------------------------\n");
		printf("\t   INFORMACOES SOBRE O SISTEMA");
		printf("\n\t------------------------------------------------\n\n\n");
        puts("\tVersao: 3.0.0");
        puts("\tDesenvolvido por: Raquel Lima Fernandes");
        puts("\tE-mail: raquel.discente@gmail.com");
        puts("\tDCT1106P Programacao: Professor Flavius Gorgonio");
        puts("\tUFRN/CERES Campus Caico, BSI 2019.2");
        puts("\tData de Terminio parte 03: 01/11/2019");
        puts("\tCodigo Disponivel em: https://github.com/raquel-lima/SIG-Projeto");
        printf("\n\n");
        puts("\t1. Menu Principal");
        puts("\t0. Encerrar Programa");
        puts("\t------------------------------------------------------");
        printf("\tDigite uma opcao >>> ");
        scanf("%d", &op);

        switch(op){
            case 1:
                menuPrincipal ();
                break;
            case 0:
                exit(0);
                break;
            default:
                puts("\tOpcao invalida. Tente novamente!\n");
            	break;
        }

    } while(op != 0);
    getchar();
}
>>>>>>> b5d60e3a370ffbb0b59cecef7751b9c05403dbb3
