#include <stdio.h>

struct mercado{

    char ID_do_produto[20];
    char nome_do_produto[100];
    float preco_do_produto;
    float peso_do_produto;

}items[100];

int main() {

    int opcao;
    int quantidade_de_items;
    char loc_ID[20];

do{
printf("\nMenu-Principal\n");
printf("1- Registrar\n");
printf("2- localizar produto\n");
printf("3- Listar registros\n");
printf("4 - sair\n");
printf("Digite o numero de uma dessas opcoes: \n");
scanf("%i", &opcao);

if(opcao < 1 || opcao > 4){
printf("\nDigite um numero dentro das opcoes, entre 1 e 4!!\n");
}

switch (opcao) {
    case 1:

        printf("\nQual a quantidade de items deseja registrar: ");
        scanf("%d", &quantidade_de_items);
        
        for(int i = 0; i < quantidade_de_items; i++){

            printf("\n--=Produto %i\n", i);
            printf("\nQual ID do produto: ");
            scanf("%s", &items[i].ID_do_produto);

            printf("\nQual o nume do produto: ");
            scanf("%s", &items[i].nome_do_produto);

            printf("\nQual o preço do preoduto: ");
            scanf("%f", &items[i].preco_do_produto);

            printf("\nQual o peso do produto: ");
            scanf("%f", &items[i].peso_do_produto);
        }
    break;

    case 2:

    printf("\nQual o id do produto: ");
    scanf("%s", &loc_ID);

    for(int i = 0; i < 100; i++){

        if(loc_ID == items[i].ID_do_produto){
            printf("\nProduto encontrado\n");
            printf("\nID: %s", items[i].ID_do_produto);
            printf("\nNome: %s", items[i].nome_do_produto);
            printf("\npreço: %f", items[i].preco_do_produto);
            printf("\npeso: %f", items[i].peso_do_produto);
        }
        
    } 
    break;

    case 3:
    for(int i = 0; i < 100; i++){
        printf("\nID: %s", items[i].ID_do_produto);
        printf("\nNome: %s", items[i].nome_do_produto);
        printf("\npreço: %f", items[i].preco_do_produto);
        printf("\npeso: %f", items[i].peso_do_produto);
    }

}


}while(opcao != 4);
    
    return 0;
}