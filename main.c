#include "structure/index.c"

int main() {
    printf("Hello, World! 2018\n");
    // processarMenu(showMenu(menu, 1));
    criaAlocacoes();
    inserePosicao(10, 0);
    inserePosicao(11, 0);
    inserePosicao(12, 0);
    inserePosicao(13, 0);
    inserePosicao(14, 0);
    inserePosicao(15, 0);
    inserePosicao(30, 0);
    removePosicao(7);
    imprimeAlocacoes();
    printf("Tamanho lista %d\n", ListaMemoria.tamanhoAlocacoes);
    return 0;
}