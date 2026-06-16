#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

struct {
    long int ID;
    char produto[101];
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
    int espaco_disponivel;            
    long int excluir_registro;
    int auxiliar_excluir;

    do {
        system("cls");
        printf("\n╔═══════════════════╗\n");
        Sleep(75);
        printf("║       MENU        ║\n");
        Sleep(75);
        printf("╚═══════════════════╝\n");
        Sleep(75);
        printf("1- Cadastrar registro\n");
        Sleep(75);
        printf("(Cadastros -> %i/10)\n", qt_de_items_cadastrados);
        Sleep(75);
        printf("2- Listar registros\n");
        Sleep(75);
        printf("3- Localizar registro\n");
        Sleep(75);
        printf("4- Excluir registro\n");
        Sleep(75);
        printf("5- Sair\n");
        printf("Escolha uma dessas opções:\n");
        Sleep(75);
        
        respscanf = scanf("%i", &opcao_menu);
        while(getchar() != '\n');
        
        if(respscanf != 1 || opcao_menu < 1 || opcao_menu > 5 ) {
            printf("\n\nDigite uma das opções, entre 1 e 5 Por favor!\n"); 
            Sleep(2000); 
            continue; 
        }

        switch(opcao_menu) {

            case 1:
            system("cls");
                espaco_disponivel = 10 - qt_de_items_cadastrados;

                printf("\n╔═════════════════════════╗\n");
                Sleep(75);
                printf("║    MENU DE CADASTRO     ║\n");
                Sleep(75);
                printf("╚═════════════════════════╝\n");
                Sleep(75);
                
                if(qt_de_items_cadastrados < 10) { 

                    printf("\nPodem ser cadastrados mais apenas %d produto(s)\n", espaco_disponivel);
                    Sleep(1500);

                    do {
                        printf("\nQuantos itens deseja cadastrar: ");
                        respscanf = scanf("%d", &qt_items_a_cadastrar);
                        while(getchar() != '\n');

                        if(respscanf != 1){
                            printf("\nDigite um número!!\n");
                            Sleep(2000);
                        }
                        else if(qt_items_a_cadastrar <= 0){ 
                            respscanf = 0;
                            printf("\nDigite um número maior que 0!!\n");
                            Sleep(2000);
                        }
                        else if(qt_items_a_cadastrar > espaco_disponivel){
                            respscanf = 0;
                            printf("\nNão é possivel cadastrar essa quantidade de itens!!\n");
                            printf("Você só pode cadastrar mais %i produtos\n", espaco_disponivel); 
                            Sleep(2000);
                        }
                    } while(respscanf == 0);
                    
                    respscanf = 0;
                        
                    for(int i = 0; i < qt_items_a_cadastrar; i++) {
                        
                        suporte = 0; 
                        
                        printf("\n----- Cadastrando produto [%i] ----- \n", qt_de_items_cadastrados + 1);
                        Sleep(75);
                            
                        do {
                            printf("Qual o ID: ");
                            respscanf = scanf("%ld", &copia_ID);
                            while(getchar() != '\n');

                            if(respscanf != 1){
                                printf("\nDigite um número!!\n");
                                Sleep(1500); 
                            }
                            else if(copia_ID < 0){
                                respscanf = 0;
                                printf("\nDigite um número maior que 0!!\n");
                                Sleep(1500); 
                            }
                        } while(respscanf == 0);
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
                            Sleep(2000); 
                            break;
                        } else {
                            items[qt_de_items_cadastrados].ID = copia_ID;
                        }
                        
                        printf("Qual o nome do produto: ");
                        scanf("%[^\n]", items[qt_de_items_cadastrados].produto);
                        while(getchar() != '\n');

                        do {
                            printf("Qual o preço: ");
                            respscanf = scanf("%f", &items[qt_de_items_cadastrados].preco);
                            while(getchar() != '\n');

                            if(respscanf != 1){
                                printf("\nDigite um número!!\n");
                                Sleep(1500); 
                            }
                            else if(items[qt_de_items_cadastrados].preco < 0){
                                respscanf = 0;
                                printf("\nDigite um número maior que 0!!\n");
                                Sleep(1500); 
                            }
                        } while(respscanf == 0);
                        respscanf = 0;

                        do {
                            printf("Qual o peso em gramas: ");
                            respscanf = scanf("%f", &items[qt_de_items_cadastrados].peso);
                            while(getchar() != '\n');

                            if(respscanf != 1){
                                printf("\nDigite um número!!\n");
                                Sleep(1500); 
                            }
                            else if(items[qt_de_items_cadastrados].peso < 0){
                                respscanf = 0;
                                printf("\nDigite um número maior que 0!!\n");
                                Sleep(1500); 
                            }
                        } while(respscanf == 0);
                        respscanf = 0;

                        qt_de_items_cadastrados++;
                    }
                

                } else {
                    printf("\nO sistema está cheio!!\n");
                    Sleep(2000); 
                }
                break;

            case 2:
            system("cls");
                printf("\n╔═════════════════════════╗\n");
                Sleep(75);
                printf("║   LISTA DE REGISTROS    ║\n");
                Sleep(75);
                printf("╚═════════════════════════╝\n");
                Sleep(75);

                if(qt_de_items_cadastrados == 0) {
                    printf("\nNenhum produto cadastrado ainda.\n\n");
                    Sleep(1500); 
                }
                for(int i = 0; i < qt_de_items_cadastrados; i++) {
                    printf("\n================================\n");
                    Sleep(75);
                    printf("Produto [%i]\n", i + 1);
                    Sleep(75);
                    printf("ID: %li\n", items[i].ID);
                    Sleep(75);
                    printf("Nome: %s\n", items[i].produto);
                    Sleep(75);
                    printf("Preço: %.2f R$\n", items[i].preco);
                    Sleep(75);
                    printf("Peso: ");
                    Sleep(75);
                    if(items[i].peso > 999){
                        printf("%.2f Kg\n", items[i].peso / 1000.0); 
                    } else {
                        printf("%.2f g\n", items[i].peso);
                    }
                    Sleep(75);
                }
                printf("\nPressione ENTER para voltar ao menu principal...");
                getchar();
                break;

            case 3:
            system("cls");
                printf("\n╔═════════════════════════╗\n");
                Sleep(75);
                printf("║   LOCALIZAR REGISTRO    ║\n");
                Sleep(75);
                printf("╚═════════════════════════╝\n");
                Sleep(75);

                if(qt_de_items_cadastrados == 0) {
                    printf("\nNenhum produto cadastrado no sistema.\n\n");
                    Sleep(1500); 
                    break;
                }

                do {
                    printf("\nQual o ID do produto: ");
                    respscanf = scanf("%ld", &busca_produto);
                    while(getchar() != '\n');

                    if(respscanf != 1){
                        printf("\nDigite um número!!\n");
                        Sleep(1500); 
                    }
                    else if(busca_produto < 0){
                        respscanf = 0;
                        printf("\nDigite um número maior que 0!!\n");
                        Sleep(1500); 
                    }
                } while(respscanf == 0);

                auxiliar_busca = -1; 
                for(int i = 0; i < qt_de_items_cadastrados; i++){
                    if(busca_produto == items[i].ID){
                        auxiliar_busca = i;
                        break;
                    }
                }
                
                if(auxiliar_busca >= 0){
                    printf("\nProduto encontrado");
                    Sleep(75);
                    printf("\n================================\n");
                    Sleep(75);
                    printf("ID: %li\n", items[auxiliar_busca].ID);
                    Sleep(75);
                    printf("Nome: %s\n", items[auxiliar_busca].produto);
                    Sleep(75);
                    printf("Preço: %.2f R$\n", items[auxiliar_busca].preco);
                    Sleep(75);
                    printf("Peso: ");
                    Sleep(75);
                    if(items[auxiliar_busca].peso > 999){
                        printf("%.2f Kg\n", items[auxiliar_busca].peso / 1000.0); 
                    } else {
                        printf("%.2f g\n", items[auxiliar_busca].peso);
                    }
                    Sleep(75);

                printf("\nPressione ENTER para voltar ao menu principal...");
                getchar();

                } else {
                    printf("\nProduto não encontrado!\n");
                    printf("Voltando para o Menu Principal!\n");
                    Sleep(2000); 

                printf("\nPressione ENTER para voltar ao menu principal...");
                getchar();
                }
                
                break;

            case 4:
            system("cls");
                printf("\n╔═════════════════════════╗\n");
                Sleep(75);
                printf("║   EXCLUIR REGISTRO      ║\n");
                Sleep(75);
                printf("╚═════════════════════════╝\n");
                Sleep(75);

                if(qt_de_items_cadastrados == 0) {
                    printf("\nNenhum produto cadastrado no sistema.\n\n");
                    Sleep(1500); 
                    break;
                }

                do {
                    printf("\nQual o ID do produto: ");
                    respscanf = scanf("%ld", &excluir_registro);
                    while(getchar() != '\n');

                    if(respscanf != 1){
                        printf("\nDigite um número!!\n");
                        Sleep(1500); 
                    }
                    else if(excluir_registro < 0){
                        respscanf = 0;
                        printf("\nDigite um número maior que 0!!\n");
                        Sleep(1500); 
                    }
                } while(respscanf == 0);

                auxiliar_excluir = -1; 
                for(int i = 0; i < qt_de_items_cadastrados; i++){
                    if(excluir_registro == items[i].ID){
                        auxiliar_excluir = i;
                        break; 
                    }
                }
                
                
                if(auxiliar_excluir >= 0) {
                    
                    for(int j = auxiliar_excluir; j < qt_de_items_cadastrados - 1; j++) {
                        items[j] = items[j + 1];
                    }
                    
                    qt_de_items_cadastrados--; 
                    printf("\nRegistro excluido com sucesso!!\n");
                    Sleep(1500);
                printf("\nPressione ENTER para voltar ao menu principal...");
                getchar();

                } else {
                    printf("\nProduto não encontrado!\n");
                    printf("Voltando para o Menu Principal!\n");
                    Sleep(2000);
                printf("\nPressione ENTER para voltar ao menu principal...");
                getchar();
                }
                break;

            case 5:
            system("cls");
                printf("\nS "); Sleep(200);
                printf("A "); Sleep(200);
                printf("I "); Sleep(200);
                printf("N "); Sleep(200);
                printf("D "); Sleep(200);
                printf("O..."); Sleep(1000);
                break;
        }
    } while(opcao_menu != 5); 

    return 0;
}