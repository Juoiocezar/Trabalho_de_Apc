#include <stdio.h>

struct  {

    int ID;
    char produto[100];
    float preco;
    float peso;

}items[10];

int main() {

int opcao_menu;

do{
    printf("\n=========Menu=========\n");
    printf("1- Cadastrar registro\n");
    printf("2- Listar registros\n");
    printf("3- Buscar registro\n");
    printf("4- ar registro\n");
    printf("5- Remover registro\n");
    printf("6- Sair\n");
    printf("Escolha uma dessa opcoes :\n");
    scanf("%i", &opcao_menu);
    
    if(opcao_menu < 1 || opcao_menu > 6) {
        printf("\n\nDigite uma das opcoes, entre 1 e 6 Por favor!\n");


        switch(opcao_menu){

            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            default:
            

        }

} 
}while(opcao_menu != 6);
    

    return 0;
}