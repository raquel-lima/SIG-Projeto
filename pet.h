<<<<<<< HEAD
typedef struct pet {
	int dia;
	int mes;
	int ano;
	char data[31];
	char nomeResponsavel[51];
	char cpfResponsavel[12];
	char codigo[3];
	char nome[10];
	char especie[10];
	char datanasc[9];
	char sexo[2];
	char observacoes[100];
    char status;
}Pet;


void menuPet (void);
Pet* inserePet (void);
void salvaPet (Pet*);
void exibePet (Pet*);
void listaPets (Pet*);
void buscaPet (void);
void alteraPet (void);
void editaNomeResponsavelPet (void);
void editaCPFResponsavelPet (void);
void editaCodigoPet (void);
void editaNomePet (void);
void editaEspeciePet (void);
void editaDataNascimentoPet (void);
void editaSexoPet (void);
void editaObservacoesPet (void);
void excluirPet (void);

=======
typedef struct pet {
	int dia;
	int mes;
	int ano;
	char data[31];
	char nomeResponsavel[51];
	char cpfResponsavel[12];
	char codigo[3];
	char nome[10];
	char especie[10];
	char datanasc[9];
	char sexo[2];
	char observacoes[100];
    char status;
}Pet;


void menuPet (void);
Pet* inserePet (void);
void salvaPet (Pet*);
void exibePet (Pet*);
void listaPets (Pet*);
void buscaPet (void);
void alteraPet (void);
void editaNomeResponsavelPet (void);
void editaCPFResponsavelPet (void);
void editaCodigoPet (void);
void editaNomePet (void);
void editaEspeciePet (void);
void editaDataNascimentoPet (void);
void editaSexoPet (void);
void editaObservacoesPet (void);
void excluirPet (void);

>>>>>>> b5d60e3a370ffbb0b59cecef7751b9c05403dbb3
int dataCadastroPet(Pet*);