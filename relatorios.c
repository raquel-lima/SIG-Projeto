#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"


int menuPrincipal (void);
void menuRelatorios (void);


void menuRelatorios (void) {
	int op;

    do{
		
		system("cls||clear");
		printf("\n");
        printf("\n\t-----------------------------------\n");
        printf("\t            RELATORIOS             ");
        printf("\n\t-----------------------------------\n\n\n");
        puts("\t1. Cliente");
        puts("\t2. Pet");
        puts("\t3. Agendamento");
        puts("\t4. Menu Principal");
        puts("\t0. Sair");
        puts("\t----------------------------------");
        printf("\tDigite uma opcao >>> ");
        scanf("%d", &op);
        
        switch(op){
            case 1:
				//relatorioCliente();
                break;
            case 2:
				//relatorioPet();
                break;
            case 3:
				//relatorioAgendamento();
                break;
            case 4:
				menuPrincipal ();
                break;
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