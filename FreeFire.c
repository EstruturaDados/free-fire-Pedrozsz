#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10


// STRUCT QUE REPRESENTA UM ITEM DO INVENTÁRIO
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor que armazena até 10 itens
Item mochila[MAX_ITENS];
int totalItens = 0;


// FUNÇÃO: Inserir um item na mochila
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\n--- Cadastro de Item ---\n");
    printf("Nome do item: ");
    scanf("%s", novo.nome);

    printf("Tipo do item (arma, munição, cura, etc): ");
    scanf("%s", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("\nItem cadastrado com sucesso!\n");
}


// FUNÇÃO: Remover item pelo nome
void removerItem() {
    char nomeBusca[30];
    printf("\nDigite o nome do item a remover: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            // Shift para esquerda para remover o item
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            totalItens--;
            printf("\nItem removido com sucesso!\n");
            return;
        }
    }

    printf("\nItem não encontrado na mochila.\n");
}


// FUNÇÃO: Listar todos os itens
void listarItens() {
    printf("\n--- Itens da Mochila ---\n");

    if (totalItens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    for (int i = 0; i < totalItens; i++) {
        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}


// FUNÇÃO: Buscar item pelo nome (busca sequencial)
void buscarItem() {
    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\nTipo: %s\nQuantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("\nItem não encontrado.\n");
}


// FUNÇÃO PRINCIPAL: Menu do sistema
int main() {
    int opcao;

    do {
        printf("\n===== Sistema da Mochila de Loot =====\n");
        printf("1 - Cadastrar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            inserirItem();
            listarItens();
            break;
        case 2:
            removerItem();
            listarItens();
            break;
        case 3:
            listarItens();
            break;
        case 4:
            buscarItem();
            break;
        case 5:
            printf("\nSaindo do sistema...\n");
            break;
        default:
            printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
