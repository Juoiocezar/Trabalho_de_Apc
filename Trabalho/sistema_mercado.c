#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#define SLEEP(ms) Sleep(ms)
#define CLEAR "cls"
#else
#include <unistd.h>
#define SLEEP(ms) usleep((ms) * 1000)
#define CLEAR "clear"
#endif

struct
{
    long int ID;
    char produto[101];
    float preco;
    float peso;
} items[10];

int main()
{
    int opcao_menu;
    int qt_items_a_cadastrar;
    long int copia_ID;
    int qt_de_items_cadastrados = 0;
    int suporte = 0;
    int respscanf = 0;
    long int busca_produto = 0;
    int auxiliar_busca;
    int espaco_disponivel;
    long int excluir_registro;
    int auxiliar_excluir;
    long int editar_registro;

    do
    {
        system(CLEAR);

        printf("\n╔═══════════════════╗\n");
        SLEEP(75);
        printf("║       MENU        ║\n");
        SLEEP(75);
        printf("╚═══════════════════╝\n");
        SLEEP(75);

        printf("1- Cadastrar registro\n");
        printf("(Cadastros -> %i/10)\n", qt_de_items_cadastrados);
        printf("2- Listar registros\n");
        printf("3- Localizar registro\n");
        printf("4- Excluir registro\n");
        printf("5- Editar registro\n");
        printf("6- Sair\n");
        printf("Escolha uma opção:\n");

        respscanf = scanf("%i", &opcao_menu);
        while (getchar() != '\n');

        if (respscanf != 1 || opcao_menu < 1 || opcao_menu > 6)
        {
            printf("\nOpção inválida!\n");
            SLEEP(1500);
            continue;
        }

        switch (opcao_menu)
        {

        case 1:
        {
            system(CLEAR);
            espaco_disponivel = 10 - qt_de_items_cadastrados;

            printf("\nCADASTRO\n");

            if (qt_de_items_cadastrados >= 10)
            {
                printf("Sistema cheio!\n");
                SLEEP(1500);
                break;
            }

            printf("Você pode cadastrar até %d itens\n", espaco_disponivel);

            do
            {
                printf("Quantos itens deseja cadastrar: ");
                respscanf = scanf("%d", &qt_items_a_cadastrar);
                while (getchar() != '\n');

                if (respscanf != 1 || qt_items_a_cadastrar <= 0 || qt_items_a_cadastrar > espaco_disponivel)
                {
                    printf("Valor inválido!\n");
                    respscanf = 0;
                }

            } while (respscanf == 0);

            for (int i = 0; i < qt_items_a_cadastrar; i++)
            {
                printf("\nProduto %d\n", qt_de_items_cadastrados + 1);

                do
                {
                    printf("ID: ");
                    respscanf = scanf("%ld", &copia_ID);
                    while (getchar() != '\n');
                } while (respscanf != 1 || copia_ID <= 0);

                suporte = 0;
                for (int j = 0; j < qt_de_items_cadastrados; j++)
                {
                    if (items[j].ID == copia_ID)
                        suporte = 1;
                }

                if (suporte)
                {
                    printf("ID duplicado!\n");
                    continue;
                }

                items[qt_de_items_cadastrados].ID = copia_ID;

                printf("Nome: ");
                scanf(" %100[^\n]", items[qt_de_items_cadastrados].produto);
                while (getchar() != '\n');

                do
                {
                    printf("Preço: ");
                    respscanf = scanf("%f", &items[qt_de_items_cadastrados].preco);
                    while (getchar() != '\n');
                } while (respscanf != 1 || items[qt_de_items_cadastrados].preco < 0);

                do
                {
                    printf("Peso (g): ");
                    respscanf = scanf("%f", &items[qt_de_items_cadastrados].peso);
                    while (getchar() != '\n');
                } while (respscanf != 1 || items[qt_de_items_cadastrados].peso < 0);

                qt_de_items_cadastrados++;
            }
            break;
        }

        case 2:
            system(CLEAR);
            printf("\nLISTA\n");

            if (qt_de_items_cadastrados == 0)
            {
                printf("Nenhum produto.\n");
                SLEEP(1000);
                break;
            }

            for (int i = 0; i < qt_de_items_cadastrados; i++)
            {
                printf("\nID: %ld", items[i].ID);
                printf("\nNome: %s", items[i].produto);
                printf("\nPreço: %.2f", items[i].preco);

                if (items[i].peso > 999)
                    printf("\nPeso: %.2f kg\n", items[i].peso / 1000);
                else
                    printf("\nPeso: %.2f g\n", items[i].peso);
            }

            getchar();
            break;

        case 3:
        {
            printf("ID busca: ");
            scanf("%ld", &busca_produto);

            auxiliar_busca = -1;

            for (int i = 0; i < qt_de_items_cadastrados; i++)
                if (items[i].ID == busca_produto)
                    auxiliar_busca = i;

            if (auxiliar_busca == -1)
            {
                printf("Não encontrado\n");
            }
            else
            {
                printf("Encontrado: %s\n", items[auxiliar_busca].produto);
            }

            getchar();
            break;
        }

        case 4:
        {
            printf("ID excluir: ");
            scanf("%ld", &excluir_registro);

            auxiliar_excluir = -1;

            for (int i = 0; i < qt_de_items_cadastrados; i++)
                if (items[i].ID == excluir_registro)
                    auxiliar_excluir = i;

            if (auxiliar_excluir == -1)
            {
                printf("Não encontrado\n");
            }
            else
            {
                for (int j = auxiliar_excluir; j < qt_de_items_cadastrados - 1; j++)
                    items[j] = items[j + 1];

                qt_de_items_cadastrados--;
                printf("Removido!\n");
            }

            getchar();
            break;
        }

        case 5:
        {
            printf("ID editar: ");
            scanf("%ld", &editar_registro);

            int idx = -1;

            for (int i = 0; i < qt_de_items_cadastrados; i++)
                if (items[i].ID == editar_registro)
                    idx = i;

            if (idx == -1)
            {
                printf("Não encontrado\n");
                break;
            }

            printf("Novo nome: ");
            scanf(" %100[^\n]", items[idx].produto);
            while (getchar() != '\n');

            printf("Novo preço: ");
            scanf("%f", &items[idx].preco);

            printf("Novo peso: ");
            scanf("%f", &items[idx].peso);

            printf("Atualizado!\n");
            getchar();
            break;
        }

        case 6:
            printf("Saindo...\n");
            break;
        }

    } while (opcao_menu != 6);

    return 0;
}