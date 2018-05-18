//
// Created by helio.junior on 18/05/2018.
//

#include "listas.h"

void criaAlocacoes () {
    ListaMemoria = NULL;
    ListaMemoria->tamanhoAlocacoes = 0;
    ListaMemoria->inicio = ListaMemoria->fim = NULL;
}

void imprimeAlocacoes () {
    Alocacoes *atual = memoryList->inicio;
    for (; atual != NULL; atual=atual->proximo) printf("%d\n",atual->valor);
}

void inserePosicao (int valor, int posicao) {
    // Criando variaveis
    Alocacoes *novo = aloca(valor), *atual;
    int i = 0;
    if ((posicao > memoryList->tamanhoAlocacoes) || (posicao < 0)) printf("Posicao invalida!\n");
    else {
        atual = memoryList->inicio;
        if (memoryList->tamanhoAlocacoes == 0) memoryList->inicio = memoryList->fim = novo;
        else if (memoryList->tamanhoAlocacoes == posicao) {
            novo->anterior = memoryList->fim;
            memoryList->fim->proximo = novo;
        }
        else {
            for (i = 0; i < posicao; ++i) atual = atual->proximo;
            novo->proximo = atual;
            novo->anterior = atual->anterior;
            if (atual->anterior == NULL) memoryList->inicio = novo;
            else atual->anterior->proximo = novo;
            atual->anterior = novo;
        }
        memoryList->tamanhoAlocacoes++;
    }
}

void removePosicao (int posicao) {
    Alocacoes *atual;
    int i = 0;
    if ((posicao > memoryList->tamanhoAlocacoes) || (posicao < 0)) printf("Posicao invalida!\n");
    else {
        atual = memoryList->inicio;
        if (posicao == 1) { // Caso seja o primeiro
            memoryList->inicio = memoryList->inicio->proximo;
            memoryList->inicio->anterior = NULL;
            if (memoryList->inicio == NULL) memoryList->fim = NULL;
        } else if (posicao == memoryList->tamanhoAlocacoes) { // Caso seja o ultimo
            memoryList->fim->anterior->proximo = NULL;
            memoryList->fim = memoryList->fim->anterior;
        } else { // qualquer outro lugar
            for (i = 1; i < posicao; ++i) atual = atual->proximo;
            atual->anterior->proximo = atual->proximo;
            atual->anterior->anterior = atual->anterior;
        }
        memoryList->tamanhoAlocacoes--;
    }
}

Alocacoes *aloca (int valor) {
    Alocacoes *novo = (Alocacoes*)malloc(sizeof(Alocacoes));
    novo->valor = valor;
    novo->anterior = novo->proximo = NULL;
    return novo;
}
