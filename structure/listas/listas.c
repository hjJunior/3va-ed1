//
// Created by helio.junior on 18/05/2018.
//

#include "listas.h"

void criaAlocacoes () {
    ListaMemoria.tamanhoAlocacoes = 0;
    ListaMemoria.inicio = ListaMemoria.fim = NULL;
}

void imprimeAlocacoes () {
    Alocacoes *atual = ListaMemoria.inicio;
    for (; atual != NULL; atual=atual->proximo) printf("%d\n",atual->valor);
}

void inserePosicao (int valor, int posicao) {
    // Criando variaveis
    Alocacoes *novo = aloca(valor), *atual;
    int i = 0;
    if ((posicao > ListaMemoria.tamanhoAlocacoes) || (posicao < 0)) printf("Posicao invalida!\n");
    else {
        atual = ListaMemoria.inicio;
        if (ListaMemoria.tamanhoAlocacoes == 0) ListaMemoria.inicio = ListaMemoria.fim = novo;
        else if (ListaMemoria.tamanhoAlocacoes == posicao) {
            novo->anterior = ListaMemoria.fim;
            ListaMemoria.fim->proximo = novo;
        }
        else {
            for (i = 0; i < posicao; ++i) atual = atual->proximo;
            novo->proximo = atual;
            novo->anterior = atual->anterior;
            if (atual->anterior == NULL) ListaMemoria.inicio = novo;
            else atual->anterior->proximo = novo;
            atual->anterior = novo;
        }
        ListaMemoria.tamanhoAlocacoes++;
    }
}

void removePosicao (int posicao) {
    Alocacoes *atual;
    int i = 0;
    if ((posicao > ListaMemoria.tamanhoAlocacoes) || (posicao < 0)) printf("Posicao invalida!\n");
    else {
        atual = ListaMemoria.inicio;
        if (posicao == 1) { // Caso seja o primeiro
            ListaMemoria.inicio = ListaMemoria.inicio->proximo;
            ListaMemoria.inicio->anterior = NULL;
            if (ListaMemoria.inicio == NULL) ListaMemoria.fim = NULL;
        } else if (posicao == ListaMemoria.tamanhoAlocacoes) { // Caso seja o ultimo
            ListaMemoria.fim->anterior->proximo = NULL;
            ListaMemoria.fim = ListaMemoria.fim->anterior;
        } else { // qualquer outro lugar
            for (i = 1; i < posicao; ++i) atual = atual->proximo;
            atual->anterior->proximo = atual->proximo;
            atual->anterior->anterior = atual->anterior;
        }
        ListaMemoria.tamanhoAlocacoes--;
    }
}

Alocacoes *aloca (int valor) {
    Alocacoes *novo = (Alocacoes*)malloc(sizeof(Alocacoes));
    novo->valor = valor;
    novo->anterior = novo->proximo = NULL;
    return novo;
}
