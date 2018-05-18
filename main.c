#include "structure/index.c"

int main() {
    printf("Hello, World! 2018\n");
    processarMenu(showMenu(menu, 1));
    criaAlocacoes();
    inserePosicao(20, 0);
    imprimeAlocacoes();
    _getch();
    return 0;
}