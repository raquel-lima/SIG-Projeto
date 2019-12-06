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
void salvaAgendamento (Agendamento*);