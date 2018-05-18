//
// Created by helio.junior on 18/05/2018.
//

#include <windows.h>
#include <conio.h>
#define menuSize 3

char menu[menuSize][1000] = {
    "Preparar memoria",
    "Imprimir alocacoes",
    "Sair"
};


enum {
    KEY_ENTER     = 13,
    ARROW_UP    = 256 + 72,
    ARROW_DOWN  = 256 + 80
};

// Prototipos das funções
int get_code (void);
void marcarColuna (int coluna, int linha, char c);
void irColunaLinha (int coluna, int linha);
int showMenu (char menu[][1000], int l);
void processarMenu (int selected);