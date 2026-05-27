#include <stdio.h>

int main() {

int opcao_menu;

while(opcao_menu != 6){
    printf("=========Menu=========\n");
    printf("1- Cadastrar registro\n");
    printf("2- Listar registros\n");
    printf("3- Buscar registro\n");
    printf("4- ar registro\n");
    printf("5- Remover registro\n");
    printf("6- Sair\n");
    printf("Escolha uma dessa opcoes :");
    scanf("%i", &opcao_menu);
}
    

    return 0;
}