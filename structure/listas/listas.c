//
// Created by helio.junior on 18/05/2018.
//

#include "listas.h"

void criaLista () { inicio = fim = NULL; }

void imprimeLista () {
    Lista *atual = inicio;
    for (; atual != NULL; atual=atual->proximo) printf("%d\n",atual->valor);
}

void inserePosicao (int valor, int posicao) {
    // Criando variaveis
    Lista *novo = aloca(valor), *atual;
    int i = 0;
    if ((posicao > tamanhoLista) || (posicao < 0)) printf("Posicao invalida!\n");
    else {
        atual = inicio;
        if (tamanhoLista == 0) inicio = fim = novo;
        else if (tamanhoLista == posicao) {
            novo->anterior = fim;
            fim->proximo = novo;
        }
        else {
            for (i = 0; i < posicao; ++i) atual = atual->proximo;
            novo->proximo = atual;
            novo->anterior = atual->anterior;
            if (atual->anterior == NULL) inicio = novo;
            else atual->anterior->proximo = novo;
            atual->anterior = novo;
        }
        tamanhoLista++;
    }
}

void removePosicao (int posicao) {
    Lista *atual;
    int i = 0;
    if ((posicao > tamanhoLista) || (posicao < 0)) printf("Posicao invalida!\n");
    else {
        atual = inicio;
        if (posicao == 1) { // Caso seja o primeiro
            inicio = inicio->proximo;
            inicio->anterior = NULL;
            if (inicio == NULL) fim = NULL;
        } else if (posicao == tamanhoLista) { // Caso seja o ultimo
            fim->anterior->proximo = NULL;
            fim = fim->anterior;
        } else { // qualquer outro lugar
            for (i = 1; i < posicao; ++i) atual = atual->proximo;
            atual->anterior->proximo = atual->proximo;
            atual->anterior->anterior = atual->anterior;
        }
        tamanhoLista--;
    }
}

Lista *aloca (int valor) {
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = valor;
    novo->anterior = novo->proximo = NULL;
    return novo;
}
