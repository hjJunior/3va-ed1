//
// Created by Helio on 5/18/2018.
//

#include "acoes.h"

void menu_preparar () {
    int totalSlots = 0, tamanhoSlots = 0, i = 0;
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
    printf("\n\n\t1. Quantos blocos voce deseja criar?\n\t=> ");
    scanf_s("%d", &totalSlots);

    // Pergunta 2
    /*
    printf("\n\n\t2. Qual tamanho de cada bloco?\n\t=> ");
    scanf_s("%d", &tamanhoSlots);
    printf("\t%s\n", s);
    */

    criaAlocacoes();

    for (i = 0; i < totalSlots; i++) {
        printf("\n\n\t%d. Qual tamanho do bloco %d\n\t=> ", (i+2), (totalSlots-(i)));
        scanf_s("%d", &tamanhoSlots);
        while (tamanhoSlots > MAX_BLOCK_SIZE) {
            printf("\tO valor deve ser menor ou igual a %d\n\t=> ", MAX_BLOCK_SIZE);
            scanf_s("%d", &tamanhoSlots);
        }
        inserePosicao(tamanhoSlots, 0);
    }
    printf("\tOs espacos para alocacoes na memoria foram criados!\n");
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
    printf("Mais gente, %d\n", pos);

    // Mostrar o antes
    printf("%s\n", s);
    printf("\tALOCACOES DE MEMORIA ANTES\n");
    printf("%s\n\n\n", s);
    imprimeAlocacoes();

    pushAlocamento (valor, (pos+1));

    // Mostrar depois de realizar a operação
    printf("\n\n\n%s\n", s);
    printf("\tALOCACOES DE MEMORIA AGORA\n");
    printf("%s\n\n\n\n", s);
    imprimeAlocacoes();
}

void menu_remover () {
    int bloco, posicao;
    limparTela();

    printf("Informe a posicao do bloco que deseja remover\n");
    scanf_s("%d", &bloco);

    printf("Informe a posicao do programa que deseja remover\n");
    scanf_s("%d", &posicao);

    removeAlocamento (bloco, posicao);
}

void limparTela () {
    #ifdef linux
        system("clear");
    #endif
    #ifdef _WIN32
        system("cls");
    #endif
}