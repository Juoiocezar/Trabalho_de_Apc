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
    int respscanf = 0;

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

            do{
                printf("\nQuantos items deseja cadastrar: ");

                respscanf = scanf("%d", &qt_items_a_cadastrar);
                while(getchar() != '\n');

                if(respscanf != 1){
                    printf("\nDigite um numero!!\n");
                }
                if(qt_items_a_cadastrar < 0){
                    respscanf = 0;
                    printf("\nDigite um numero maior que 0!!\n");
                }
                    
            
            }while(respscanf == 0);
            respscanf = 0;
                
                for(int i = 0; i < qt_items_a_cadastrar; i++) {
                    
                    suporte = 0; 

                    
                    printf("\n----- Cadastrando produto [%i] ----- \n", qt_de_items_cadastrados + 1);
                        
                    do{

                    printf("Qual o ID: ");
                    respscanf = scanf("%ld", &copia_ID);
                    while(getchar() != '\n');

                    if(respscanf != 1){
                    printf("\nDigite um numero!!\n");
                }
                if(copia_ID < 0){
                    respscanf = 0;
                    printf("\nDigite um numero maior que 0!!\n");
                }

                    }while(respscanf == 0);
                    respscanf = 0;
                    
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

                    do{
                    printf("Qual o preco: ");
                    
                    respscanf = scanf("%f", &items[qt_de_items_cadastrados].preco);
                    while(getchar() != '\n');

                     if(respscanf != 1){
                    printf("\nDigite um numero!!\n");
                }
                if(items[qt_de_items_cadastrados].preco < 0){
                    respscanf = 0;
                    printf("\nDigite um numero maior que 0!!\n");
                }

                    }while(respscanf == 0);
                    respscanf = 0;

                    do{
                    printf("Qual o peso: ");
                    
                    respscanf = scanf("%f", &items[qt_de_items_cadastrados].peso);
                     while(getchar() != '\n');

                     if(respscanf != 1){
                    printf("\nDigite um numero!!\n");
                }
                if(items[qt_de_items_cadastrados].peso < 0){
                    respscanf = 0;
                    printf("\nDigite um numero maior que 0!!\n");
                }

                    }while(respscanf == 0);
                    respscanf = 0;

                    qt_de_items_cadastrados++;
                }
                break;

            case 2:
            printf("\n-=Lista de registros=-");
                for(int i = 0; i < qt_de_items_cadastrados; i++) {
                    printf("\n================================\n");
                    printf("Produto [%i]\n", i + 1);
                    printf("ID: %li\n", items[i].ID);
                    printf("Nome: %s\n", items[i].produto);
                    printf("Preco: %.2f R$\n", items[i].preco);
                    printf("Peso: ");
                    if(items[i].peso > 999){
                        printf("%.2f Kg\n", items[i].peso / 100);
                    }else{
                        printf("%.2f g\n", items[i].peso);
                    }
                }
                break;
        }

    } while(opcao_menu != 3);
    
    return 0;
}