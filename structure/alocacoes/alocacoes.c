//
// Created by Helio on 5/18/2018.
//

#include "alocacoes.h"

int searchMemory (int valorAlocar, int algorithm) {
    int maisAlto, livre, maisBaixo = MAX_BLOCK_SIZE;
    int i = livre = maisAlto = 0;
    int choice = -1;
    Alocacoes *atual = ListaMemoria.inicio;
    for (; atual != NULL; atual=atual->proximo) {
        livre = atual->valorCapacidade;
        if (livre >= valorAlocar) {
            if (atual->alocado == 1) continue;
            else if (algorithm == ALGO_FIRST_FIT) {
                choice = i;
                break;
            } else if (algorithm == ALGO_BEST_FIT) {
                if (maisBaixo >= livre) {
                    maisBaixo = livre;
                    choice = i;
                }
            } else if (algorithm == ALGO_WORST_FIT) {
                if (maisAlto <= livre) {
                    maisAlto = livre;
                    choice = i;
                }
            }
        }
        i++;
    }
    // Imprimir mensagem de erro caso nao tenha encontrado nenhum local para alocação
    if (choice == -1) printf("Sem espaco para alocacao, tente realizar a desfragmentacao do disco\n");
    return choice;
}

void pushProgram (int programSize, int algorithm) {
    int p = searchMemory(programSize, algorithm);
    int i;
    int tmp;
    if (p != - 1) {
        Alocacoes *atual = ListaMemoria.inicio;
        for (i = 0; i < p; i++) atual=atual->proximo;
        tmp = atual->valorCapacidade;
        atual->alocado = 1;
        atual->valorCapacidade = programSize;
        if (tmp > programSize) inserePosicao(tmp - programSize, 0);
    }
}

void removeProgram (int position) {
    Alocacoes *atual = ListaMemoria.inicio;
    int i;
    for (i = 0; i < position; i++) atual=atual->proximo;
    if (atual->alocado == 1) {
        atual->alocado = 0;
        printf("Programa removido!\n");
    }
    else printf("Nenhum programa alocado neste endereco\n");
}