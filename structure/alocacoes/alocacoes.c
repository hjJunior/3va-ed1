//
// Created by Helio on 5/18/2018.
//

#include "alocacoes.h"

int searchMemory (int valorAlocar, int algorithm) {
    int tmp, choiceValue, livre;
    int i = livre = choiceValue = 0;
    int choice = -1;
    Alocacoes *atual = ListaMemoria.inicio;
    for (; atual != NULL; atual=atual->proximo) {
        tmp = capacidadeUsada(atual);
        livre = atual->valorCapacidade - tmp;
        if (tmp == -1) continue;
        else if (livre >= valorAlocar) {
            if (algorithm == ALGO_FIRST_FIT) {
                choice = i;
                break;
            } else if (algorithm == ALGO_BEST_FIT) {
                if (choiceValue <= valorAlocar) {
                    choiceValue = valorAlocar;
                    choice = i;
                }
            } else if (algorithm == ALGO_WORST_FIT) {
                if (choiceValue >= valorAlocar) {
                    choiceValue = valorAlocar;
                    choice = i;
                }
            }
        } else printf("Sem espaço na memoria para aplicacao\n");
        i++;
    }
    return choice;
}