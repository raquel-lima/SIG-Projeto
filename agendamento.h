<<<<<<< HEAD
typedef struct agendamento {
	int dia;
	int mes;
	int ano;
	char data[31];
	char cpfCliente[12];
	char nomeCliente[51];
	char horaioServico[10];
	char tipoServico[100];
	char nomeRelatorio[100];
	float valor;
    char status;
}Agendamento;


void menuAgendamento (void);
void agendaServico (void);
void buscaInfomacoesAgendamento (void);
=======
typedef struct agendamento {
	int dia;
	int mes;
	int ano;
	char data[31];
	char cpfCliente[12];
	char nomeCliente[51];
	char horaioServico[10];
	char tipoServico[100];
	char nomeRelatorio[100];
	float valor;
    char status;
}Agendamento;


void menuAgendamento (void);
void agendaServico (void);
void buscaInfomacoesAgendamento (void);
>>>>>>> b5d60e3a370ffbb0b59cecef7751b9c05403dbb3
void salvaAgendamento (Agendamento*);