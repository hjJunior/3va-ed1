//
// Created by helio.junior on 18/05/2018.
//

#define MAX_BLOCK_SIZE 9999
#define MAX_PROGRAMS_ALOCS MAX_BLOCK_SIZE

typedef struct alocacoes Alocacoes;
struct alocacoes {
    int valorAlocado[MAX_PROGRAMS_ALOCS];
    int valorCapacidade;
    int numProgramasAlocados;
    Alocacoes *proximo;
    Alocacoes *anterior;
};

typedef struct memoria MemoriaList;
struct memoria {
    int tamanhoAlocacoes;
    Alocacoes *inicio;
    Alocacoes *fim;
};
MemoriaList ListaMemoria;

// Prototipos de funções
void criaAlocacoes();
void imprimeAlocacoes();
void inserePosicao(int valor, int posicao);
void removePosicao(int posicao);
Alocacoes* aloca (int valor);
int capacidadeUsada (Alocacoes* alocacao);
void pushAlocamento (int programSize, int posicao);
void removeAlocamento (int bloco, int posicao);