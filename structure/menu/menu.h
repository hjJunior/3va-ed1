//
// Created by helio.junior on 18/05/2018.
//

#include <windows.h>
#include <conio.h>
#define menuSize 5

char menu[menuSize][1000] = {
    "Fazer alocamento de memoria",
    "Imprimir alocacoes",
    "Preparar memoria",
    "Remover alocacao",
    "Sair"
};

char confirmarMenu[2][1000] = {
    "Nao",
    "Sim, estou cliente e desejo continuar"
};

char algoritimosMenu[3][1000] = {
        "FIRST-FIT",
        "BEST-FIT",
        "WORST-FIT"
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
int showMenu (char menu[][1000], int l, int size);
void processarMenu (int selected);