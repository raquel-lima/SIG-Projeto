typedef struct agendamento {
	int dia;
	int mes;
	int ano;
	char data[31];
	char cpfCliente[12];
	char nomeDoPet[10];
	char codigo[3];
	char tipoServico[20];
	char horarioServico[10];
	char dataProgramada[15];
	float valorServico;
    char status;
}Agendamento;


void menuAgendamento (void);
void agendaServico (void);
void buscaInfomacoesAgendamento (void);
void salvaAgendamento (Agendamento*);
void exibeAgendamento (Agendamento*);
void listaAgendamentos(void);
void buscaAgendamento(void);
void alteraAgendamento (void);
void editaCodigoAgendamento (void);
int dataCadastroAgendamento (Agendamento*);
void editaCodigoAgendamento (void);
void editaServicoAgendamento (void);
void editaHorarioAgendamento (void);
void editaDataAgendamento (void);
void excluirAgendamento (void);
int dataSistema(void);