//
// Created by helio.junior on 18/05/2018.
//
#include "index.h"
#include "listas/listas.c"
#include "alocacoes/alocacoes.c"
#include "menu/menu.c"

void initMenu () {
    char welcome[] = "SIMULADOR DE ALOCACAO DE MEMORIA";
    printf("%s\n", welcome);
    int code = showMenu(menu, 1, menuSize);
    processarMenu(code);
    // Recursividade
    if (code != (menuSize - 1)) {
        printf("=> Precione enter para voltar ao menu\n");
        _getch();
        limparTela();
        initMenu();
    }
}