//
// Created by Helio on 5/18/2018.
//

#include "alocacoes.h"

int searchMemory (int valorAlocar, int algorithm) {
    int tmp, maisAlto, livre, maisBaixo = MAX_BLOCK_SIZE;
    int i = livre = maisAlto = 0;
    int choice = -1;
    Alocacoes *atual = ListaMemoria.inicio;
    for (; atual != NULL; atual=atual->proximo) {
        tmp = capacidadeUsada(atual);
        livre = atual->valorCapacidade - tmp;
        if (tmp == -1) continue;
        else if ((livre >= valorAlocar) && (atual->numProgramasAlocados < MAX_PROGRAMS_ALOCS)) {
            if (algorithm == ALGO_FIRST_FIT) {
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
        } else if (atual->numProgramasAlocados >= MAX_PROGRAMS_ALOCS) printf("[AVISO] bloco atual alcansou o limite de programas alocados\n");
        i++;
    }
    // Imprimir mensagem de erro caso nao tenha encontrado nenhum local para alocação
    if (choice == -1) printf("Sem espaco para alocacao\n");
    return choice;
}