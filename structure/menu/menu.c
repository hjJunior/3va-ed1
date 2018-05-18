//
// Created by helio.junior on 18/05/2018.
//

#include "menu.h"

int showMenu (char menu[][1000], int l){
    int i, tecla, linha = -1;
    if (l>=0) linha = l;
    else l = 0;

    // Imprimir o menu
    for(i = 0; i < menuSize; i++) printf("[ ] %s\n", menu[i]);

    tecla = get_code();
    while(tecla != KEY_ENTER){
        marcarColuna(1, linha, ' ');
        switch(tecla){
            case ARROW_UP: if ((linha) > 0+l) linha--; break;
            case ARROW_DOWN: if((linha) < (menuSize-1+l)) linha++; break;
        }
        if(((linha) > 0+l) || ((linha) < (menuSize-1+l))) marcarColuna(1, linha, 'x');
        tecla = get_code();
    }

    irColunaLinha(0,menuSize+1);
    return (linha-l);
}

void irColunaLinha (int coluna, int linha){ SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD) {coluna,linha}); }

int get_code (void){
    int ch = getch();
    if (ch == 0 || ch == 224) ch = 256 + getch();
    return ch;
}

void marcarColuna (int coluna, int linha, char c) {
    irColunaLinha(coluna,linha);
    printf("%c", c);
}

void processarMenu (int selected){
    switch (selected) {
        case 0: printf("\nYou have choiced: %s\n", menu[selected]); break;
        case 1: printf("Nada haver\n"); break;
        default: printf("Default\n"); break;
    }
}