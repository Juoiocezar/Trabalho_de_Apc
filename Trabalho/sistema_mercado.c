#include <stdio.h>
#include <windows.h>

struct {
    long int ID;
    char produto[100];
    float preco;
    float peso;
} items[10];

int main() {

SetConsoleOutputCP(CP_UTF8);

    int opcao_menu;
    int qt_items_a_cadastrar;
    long int copia_ID;
    int qt_de_items_cadastrados = 0;
    int suporte = 0;
    int respscanf = 0;
    long int busca_produto = 0;
    int auxiliar_busca = -1;

    do {
        printf("\n========= Menu =========\n");
        printf("1- Cadastrar registro\n");
        printf("(Cadastros -> %i/10)\n", qt_de_items_cadastrados);
        printf("2- Listar registros\n");
        printf("3- Localizar registro\n");
        printf("4- Sair\n");
        printf("Escolha uma dessas opções:\n");
        scanf("%i", &opcao_menu);
        while(getchar() != '\n');
        
        if(opcao_menu < 1 || opcao_menu > 4 ) {
            printf("\n\nDigite uma das opções, entre 1 e 4 Por favor!\n");
        }

        switch(opcao_menu) {

            case 1:

            if(qt_de_items_cadastrados <= 10){

                printf("\n-----Cadastrando produto-----\n");
                printf("\nPodem ser cadastrados mais apenas %d produto\n", 9 - qt_de_items_cadastrados + 1);

            do{
                printf("\nQuantos items deseja cadastrar: ");

                respscanf = scanf("%d", &qt_items_a_cadastrar);
                while(getchar() != '\n');

                if(respscanf != 1){
                    printf("\nDigite um número!!\n");
                }
                if(qt_items_a_cadastrar < 0){
                    respscanf = 0;
                    printf("\nDigite um número maior que 0!!\n");
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
                    printf("\nDigite um número!!\n");
                }
                if(copia_ID < 0){
                    respscanf = 0;
                    printf("\nDigite um número maior que 0!!\n");
                }

                    }while(respscanf == 0);
                    respscanf = 0;
                    
                    for(int j = 0; j < qt_de_items_cadastrados; j++) {
                        if(copia_ID == items[j].ID) {
                            suporte++;
                            continue;
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
                    printf("Qual o preço: ");
                    
                    respscanf = scanf("%f", &items[qt_de_items_cadastrados].preco);
                    while(getchar() != '\n');

                     if(respscanf != 1){
                    printf("\nDigite um número!!\n");
                }
                if(items[qt_de_items_cadastrados].preco < 0){
                    respscanf = 0;
                    printf("\nDigite um número maior que 0!!\n");
                }

                    }while(respscanf == 0);
                    respscanf = 0;

                    do{
                    printf("Qual o peso em gramas: ");
                    
                    respscanf = scanf("%f", &items[qt_de_items_cadastrados].peso);
                     while(getchar() != '\n');

                     if(respscanf != 1){
                    printf("\nDigite um número!!\n");
                }
                if(items[qt_de_items_cadastrados].peso < 0){
                    respscanf = 0;
                    printf("\nDigite um número maior que 0!!\n");
                }

                    }while(respscanf == 0);
                    respscanf = 0;

                    qt_de_items_cadastrados++;
                }
            }else{
                printf("\nO sistema está cheio!!\n");
            }
                break;

            case 2:
            printf("\n-=Lista de registros=-");
                for(int i = 0; i < qt_de_items_cadastrados; i++) {
                    printf("\n================================\n");
                    printf("Produto [%i]\n", i + 1);
                    printf("ID: %li\n", items[i].ID);
                    printf("Nome: %s\n", items[i].produto);
                    printf("Preço: %.2f R$\n", items[i].preco);
                    printf("Peso: ");
                    if(items[i].peso > 999){
                        printf("%.2f Kg\n", items[i].peso / 100);
                    }else{
                        printf("%.2f g\n", items[i].peso);
                    }
                }
                break;

                case 3:

                printf("\n----Localizando registro----\n");

                do{
                    printf("\nQual o ID do produto: ");
                    respscanf = scanf("%ld", &busca_produto);
                    while(getchar() != '\n');


                    if(respscanf != 1){
                     printf("\nDigite um número!!\n");
                    }
                    if(busca_produto < 0){
                        respscanf = 0;
                        printf("\nDigite um número maior que 0!!\n");
                    }

                    }while(respscanf == 0);

                    for(int i = 0; i < 10; i++){
                        if(busca_produto == items[i].ID){
                            auxiliar_busca = i;
                        }
                    }
                    if(auxiliar_busca >= 0){
                    printf("\nProduto encontrado");
                    printf("\n================================\n");
                    printf("ID: %li\n", items[auxiliar_busca].ID);
                    printf("Nome: %s\n", items[auxiliar_busca].produto);
                    printf("Preço: %.2f R$\n", items[auxiliar_busca].preco);
                    printf("Peso: ");
                     if(items[auxiliar_busca].peso > 999){
                        printf("%.2f Kg\n", items[auxiliar_busca].peso / 100);
                    }else{
                        printf("%.2f g\n", items[auxiliar_busca].peso);
                    }
                    auxiliar_busca = -1;    

                    }else{
                        printf("\nProduto não encontrado!\n");
                        printf("Voltando para o Menu Principal!\n");

                    }

                    
                    
                    


                
        }

    } while(opcao_menu != 4);
    
    return 0;
}