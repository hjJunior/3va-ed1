#include "structure/index.c"

int main() {
    printf("Hello, World! 2018\n");
    int code = showMenu(menu, 1);
    processarMenu(code);

    while (code != (menuSize - 1)) {
        _getch();
        system("cls");
        // Mostrar o menu novamente
        code = showMenu(menu, 0);
        processarMenu(code);
    }
    _getch();
    return 0;
}