#include <stdio.h>

struct {
    long int ID;
    char produto[100];
    float preco;
    float peso;
} items[10];

int main() {

    int opcao_menu;
    int qt_items_a_cadastrar;
    long int copia_ID;
    int qt_de_items_cadastrados = 0;
    int suporte = 0;

    do {
        printf("\n========= Menu =========\n");
        printf("1- Cadastrar registro\n");
        printf("(Cadastros -> %i/10)\n", qt_de_items_cadastrados);
        printf("2- Listar registros\n");
        printf("3- Sair\n");
        printf("Escolha uma dessas opcoes:\n");
        scanf("%i", &opcao_menu);
        while(getchar() != '\n');
        
        if(opcao_menu < 1 || opcao_menu > 3) {
            printf("\n\nDigite uma das opcoes, entre 1 e 3 Por favor!\n");
        }

        switch(opcao_menu) {

            case 1:
                printf("\nQuantos items deseja cadastrar: ");
                scanf("%i", &qt_items_a_cadastrar);
                while(getchar() != '\n');
                
                for(int i = 0; i < qt_items_a_cadastrar; i++) {
                    
                    suporte = 0; 

                    
                    printf("\n----- Cadastrando produto [%i] ----- \n", qt_de_items_cadastrados + 1);
                        
                    printf("Qual o ID: ");
                    scanf("%li", &copia_ID);
                    while(getchar() != '\n');

                    
                    for(int j = 0; j < qt_de_items_cadastrados; j++) {
                        if(copia_ID == items[j].ID) {
                            suporte++;
                            break;
                        }
                    }

                    if(suporte > 0) {
                        printf("\nEste ID ja foi cadastrado!!\n");
                        printf("Cancelando este e voltando para o menu.\n");
                        break;
                    } else {
                        
                        items[qt_de_items_cadastrados].ID = copia_ID;
                    }
                    
                    printf("Qual o nome do produto: ");
                    
                    scanf("%[^\n]", items[qt_de_items_cadastrados].produto);
                    while(getchar() != '\n');

                    printf("Qual o preco: ");
                    
                    scanf("%f", &items[qt_de_items_cadastrados].preco);

                    printf("Qual o peso: ");
                    
                    scanf("%f", &items[qt_de_items_cadastrados].peso);

                    qt_de_items_cadastrados++;
                }
                break;

            case 2:
                for(int i = 0; i < qt_de_items_cadastrados; i++) {
                    printf("\n================================\n");
                    printf("Produto [%i]\n", i + 1);
                    printf("ID: %li\n", items[i].ID);
                    printf("Nome: %s\n", items[i].produto);
                    printf("Preco: %.2f\n", items[i].preco);
                    printf("Peso: %.2f\n", items[i].peso);
                }
                break;
        }

    } while(opcao_menu != 3);
    
    return 0;
}