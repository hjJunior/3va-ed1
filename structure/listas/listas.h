//
// Created by helio.junior on 18/05/2018.
//

typedef struct elemento Lista;
struct elemento {
    int valor;
    Lista *proximo;
    Lista *anterior;
};

Lista *inicio, *fim;
int tamanhoLista = 0;

// Prototipos de funções
void criaLista();
void imprimeLista();
void inserePosicao(int valor, int posicao);
void removePosicao(int posicao);
Lista* aloca (int valor);
