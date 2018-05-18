//
// Created by helio.junior on 18/05/2018.
//
typedef struct alocacoes Alocacoes;
struct alocacoes {
    int valor;
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
