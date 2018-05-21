//
// Created by helio.junior on 18/05/2018.
//

#include "menu.h"
#include "acoes.c"

int showMenu (char menu[][1000], int l, int size){
    int i, tecla, linha = -1;
    if (l>=0) linha = l;
    else l = 0;

    // Imprimir o menu
    for(i = 0; i < size; i++) printf("[ ] %s\n", menu[i]);

    marcarColuna(1, linha, 'x');

    tecla = get_code();
    while(tecla != KEY_ENTER){
        marcarColuna(1, linha, ' ');
        switch(tecla){
            case ARROW_UP: if ((linha) > 0+l) linha--; break;
            case ARROW_DOWN: if((linha) < (size-1+l)) linha++; break;
        }
        if(((linha) > 0+l) || ((linha) < (size-1+l))) marcarColuna(1, linha, 'x');
        tecla = get_code();
    }
    irColunaLinha(0,size+1);
    return (linha-l);
}

void irColunaLinha (int coluna, int linha){ SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD) {coluna,linha}); }

int get_code (void){
    int ch = _getch();
    if (ch == 0 || ch == 224) ch = 256 + _getch();
    return ch;
}

void marcarColuna (int coluna, int linha, char c) {
    irColunaLinha(coluna,linha);
    printf("%c", c);
}

void processarMenu (int selected){
    switch (selected) {
        case 0: menu_push(); break;
        case 1: menu_imprimir(); break;
        case 2: menu_preparar(); break;
        default: printf("Precione qualquer tecla para sair\n"); break;
    }
}