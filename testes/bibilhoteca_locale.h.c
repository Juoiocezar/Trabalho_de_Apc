#include <stdio.h>
#include <windows.h> // Adicione esta biblioteca

int main() {
    // Configura o terminal do Windows para aceitar UTF-8 (código 65001)
    SetConsoleOutputCP(CP_UTF8);

    printf("Olá, mundo! Acentuação funcionando.\n");

    return 0;
}