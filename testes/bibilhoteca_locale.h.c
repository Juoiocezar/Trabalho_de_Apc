#include <stdio.h>
#include <locale.h>

int main() {
char nome[101];

printf("Entre com o seu nome: ");
fgets(nome, 101, stdin);

printf("\n\n%s", nome);


    return 0;
}