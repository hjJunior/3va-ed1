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
    int i = 0;
    char hr[] = "|---------------";
    printf("%s%s%s|\n", hr, hr, hr);
    printf("| N. Bloco\t| Capacidade \t| Alocada \t|\n");
    printf("%s%s%s|\n", hr, hr, hr);
    for (; atual != NULL; atual=atual->proximo) {
        printf("| %d\t\t| %d\t\t| %d\t\t|\n", i, atual->valorCapacidade, atual->alocado);
        i++;
    }
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
    novo->valorCapacidade = valor;
    novo->alocado = 0;
    novo->anterior = novo->proximo = NULL;
    return novo;
}


void joinMemory (Alocacoes *atual, Alocacoes *proximo, int posicao) {
    int tmp1, tmp2;
//    if (proximo == NULL) continue;
    if ((atual->alocado == 0) && (proximo->alocado == 0)) {
        // Definindo valores temporarios
        tmp1 = atual->valorCapacidade;
        tmp2 = proximo->valorCapacidade;

        printf("Valor atual %d - Valor proximo %d\n", tmp1, tmp2);

        // Remove
        removePosicao(posicao + 1);
        removePosicao(posicao + 2);

        // Imprimir depois de remover
        imprimeAlocacoes();

        // Unifica os dois em um so
        inserePosicao(tmp1 + tmp2, posicao);

        imprimeAlocacoes();
        // Reiniciar
        // if (proximo->proximo != NULL) atual = atual->proximo;
    }
}


void desfragmentar() {
    imprimeAlocacoes();
    Alocacoes *atual = ListaMemoria.inicio;
    Alocacoes *tmp = ListaMemoria.inicio;
    Alocacoes *proximo;
    int posicao = 0;
    int count = 0;
    for (; ((atual != NULL)); atual=atual->proximo) {
        joinMemory (atual, atual->proximo, posicao);
        posicao++;
    }
    imprimeAlocacoes();
    printf("Desfragmentacao realizada com sucesso! (%d programas foram realocados)\n", count);
}