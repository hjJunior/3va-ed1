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
    char hr[] = "|---------------";
    printf("%s%s%s%s|\n", hr, hr, hr, hr);
    printf("| Cap. Bloco\t| Cap. Usada \t| Cap. Livre \t| N. Programs \t|\n");
    printf("%s%s%s%s|\n", hr, hr, hr, hr);
    for (; atual != NULL; atual=atual->proximo) printf("| %d\t\t| %d\t\t| %d\t\t| %d\t\t|\n",atual->valorCapacidade, capacidadeUsada(atual), (atual->valorCapacidade - capacidadeUsada(atual)), atual->numProgramasAlocados);
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
    novo->numProgramasAlocados = 0;
    novo->anterior = novo->proximo = NULL;
    return novo;
}

int capacidadeUsada (Alocacoes* alocacao) {
    int i = 0, soma = 0;
    if (alocacao == NULL) return -1;
    else for (i = 0; i < (int) alocacao->numProgramasAlocados; i++) {
        soma = soma + alocacao->valorAlocado[i];
    }
    return soma;
}

void pushAlocamento (int programSize, int posicao) {
    int i, usado;
    Alocacoes *atual = ListaMemoria.inicio;
    for (i = 0; i < (posicao-1); i++) atual = atual->proximo;
    usado = capacidadeUsada(atual);
    if ((usado != -1) && ((atual->valorCapacidade - usado) >= programSize)) {
        atual->valorAlocado[atual->numProgramasAlocados] = programSize;
        atual->numProgramasAlocados = atual->numProgramasAlocados + 1;
    } else printf("Memoria insuficiente para alocar %d\n", programSize);
}