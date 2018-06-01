//
// Created by helio.junior on 18/05/2018.
//

#define MAX_BLOCK_SIZE 9999
#define MAX_PROGRAMS_ALOCS MAX_BLOCK_SIZE

typedef struct alocacoes Alocacoes;
struct alocacoes {
    int valorCapacidade;
    int alocado;
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
void desfragmentar();
void joinMemory (Alocacoes *atual, Alocacoes *proximo, int posicao);
Alocacoes* aloca (int valor);
