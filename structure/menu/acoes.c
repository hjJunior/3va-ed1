//
// Created by Helio on 5/18/2018.
//

#include "acoes.h"

void menu_preparar () {
    int tamanhoSlots = 0;
    char s[] = "==============================================";
    limparTela();
    if ((ListaMemoria.inicio != NULL) || (ListaMemoria.tamanhoAlocacoes >= 1)) {
        printf("memoria ja configurada, se processeguir ira perder todas as alocacaoes\n");
        if (showMenu(confirmarMenu, 1, 2) == 0) return;
    }
    limparTela();

    printf("\t%s\n", s);
    printf("\t\tVAMOS A CONFIGURACAO DA MEMORIA\n");
    printf("\t%s\n", s);
    // Pergunta 1
    printf("\n\n\t1. Qual tamanho total da memoria?\n\t=> ");
    scanf_s("%d", &tamanhoSlots);

    criaAlocacoes();
    inserePosicao(tamanhoSlots, 0);
    printf("\tA memoria foi criada!\n");
}

void menu_imprimir () {
    limparTela();
    if ((ListaMemoria.inicio == NULL) || (ListaMemoria.tamanhoAlocacoes == 0)) {
        printf("memoria nao configurada, que tal configurar agora?\n");
        if (showMenu(confirmarMenu, 1, 2) == 1) menu_preparar();
        else {
            printf("A operacao foi cancelada\n");
            return;
        }
    }
    limparTela();
    imprimeAlocacoes();
}

void menu_push () {
    int algo, valor, pos;

    limparTela();
    if ((ListaMemoria.inicio == NULL) || (ListaMemoria.tamanhoAlocacoes == 0)) {
        printf("memoria nao configurada, que tal configurar agora?\n");
        if (showMenu(confirmarMenu, 1, 2) == 1) menu_preparar();
        else {
            printf("A operacao foi cancelada\n");
            return;
        }
    }
    limparTela();

    char s[] = "===================================================";
    limparTela();
    printf("%s\n", s);
    printf("\tSIMULACAO DE ALOCAMENTO NA MEMORIA\n");
    printf("%s\n", s);

    // Pergunta 1
    printf("\n\n1. Qual valor deseja alocar?\n=> ");
    scanf_s("%d", &valor);
    // Pergunta 2
    printf("\n\n2. Qual algoritimo de insercao deseja utilizar?\n\n");
    algo = showMenu(algoritimosMenu, 11, 3);
    irColunaLinha(0, 11+3);

    // Obter a posição onde possa ser inserido usando o algoritimo escolhido
    pos = searchMemory(valor, algo);
    if (pos == -1) return;
    // printf("Mais gente, %d\n", pos);

    // Mostrar o antes
    printf("%s\n", s);
    printf("\tALOCACOES DE MEMORIA ANTES\n");
    printf("%s\n\n\n", s);
    imprimeAlocacoes();

    pushProgram (valor, (pos+1));

    // Mostrar depois de realizar a operação
    printf("\n\n\n%s\n", s);
    printf("\tALOCACOES DE MEMORIA AGORA\n");
    printf("%s\n\n\n\n", s);
    imprimeAlocacoes();
}

void menu_remover () {
    int posicao;
    limparTela();

    printf("Informe a posicao do programa que deseja remover\n");
    scanf_s("%d", &posicao);

    removeProgram (posicao);
}

void menu_desfragmentar () {
    limparTela();

    printf("Iniciando desfragmentacao\n");
    desfragmentar();
}
void menu_testIt () {
    int pos;
    // Criar alocações
    criaAlocacoes();
    inserePosicao(50, 0);

    // Insere as alocações de programas
    pos = searchMemory(10, 1);
    if (pos == -1) return;
    pushProgram (10, (pos+1));

    pos = searchMemory(10, 1);
    if (pos == -1) return;
    pushProgram (10, (pos+1));

    // Remover os programas
    removeProgram (1);
    removeProgram (2);

    // Executar modo de desgragmentacao
    menu_desfragmentar();

}

void limparTela () {
    #ifdef linux
        system("clear");
    #endif
    #ifdef _WIN32
        system("cls");
    #endif
}