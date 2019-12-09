typedef struct cliente {
	int dia;
	int mes;
	int ano;
	char data[31];
	char nome[51];
	char cpf[12];
	char endereco[51];
	char telefone[12];
    char status;
}Cliente;

void menuCliente (void);
Cliente* insereCliente (void);
void salvaCliente (Cliente*);
void exibeCliente (Cliente*);
void listaClientes (Cliente*);
void buscaCliente (void);
void alteraCliente (void);
void editaCodigoCliente (void);
void editaNomeCliente (void);
void editaCPFCliente (void);
void editaEnderecoCliente (void);
void editaTelefoneCliente (void);
void editaDadosCliente (void);
void excluirCliente (void);
int dataCadastroCliente (Cliente*);