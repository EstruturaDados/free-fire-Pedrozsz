#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// =============================================================
//                       STRUCTS
// =============================================================

// Item comum às duas estruturas
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Nó para lista encadeada
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// =============================================================
//                VARIÁVEIS GLOBAIS DO VETOR
// =============================================================

Item mochilaVet[MAX_ITENS];
int totalItensVet = 0;

// Contadores de operações
int comparacoesSequencial = 0;
int comparacoesBinaria = 0;

// =============================================================
//         FUNÇÕES — VERSÃO USANDO **VETOR (SEQUENCIAL)**
// =============================================================

// Inserir item no vetor
void inserirItemVetor() {
    if (totalItensVet >= MAX_ITENS) {
        printf("\nA mochila (vetor) está cheia!\n");
        return;
    }

    Item novo;
    printf("\n--- Cadastro de Item (Vetor) ---\n");
    printf("Nome: ");
    scanf("%s", novo.nome);

    printf("Tipo: ");
    scanf("%s", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochilaVet[totalItensVet] = novo;
    totalItensVet++;

    printf("Item inserido com sucesso!\n");
}

// Remover item do vetor
void removerItemVetor() {
    char nomeBusca[30];
    printf("\nDigite o nome do item a remover: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItensVet; i++) {
        if (strcmp(mochilaVet[i].nome, nomeBusca) == 0) {
            for (int j = i; j < totalItensVet - 1; j++)
                mochilaVet[j] = mochilaVet[j + 1];

            totalItensVet--;
            printf("Item removido!\n");
            return;
        }
    }
    printf("Item não encontrado.\n");
}

// Listar itens do vetor
void listarItensVetor() {
    printf("\n--- Mochila (Vetor) ---\n");
    if (totalItensVet == 0) {
        printf("Vazia.\n");
        return;
    }
    for (int i = 0; i < totalItensVet; i++) {
        printf("%d) %s | %s | %d\n",
               i + 1, mochilaVet[i].nome, mochilaVet[i].tipo, mochilaVet[i].quantidade);
    }
}

// Busca sequencial no vetor
void buscarSequencialVetor() {
    char nomeBusca[30];
    comparacoesSequencial = 0;

    printf("\nNome do item: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItensVet; i++) {
        comparacoesSequencial++;

        if (strcmp(mochilaVet[i].nome, nomeBusca) == 0) {
            printf("Item encontrado!\n");
            printf("Comparações: %d\n", comparacoesSequencial);
            return;
        }
    }

    printf("Item não encontrado.\n");
    printf("Comparações: %d\n", comparacoesSequencial);
}

// Ordenação Bubble Sort
void ordenarVetor() {
    for (int i = 0; i < totalItensVet - 1; i++) {
        for (int j = 0; j < totalItensVet - i - 1; j++) {
            if (strcmp(mochilaVet[j].nome, mochilaVet[j + 1].nome) > 0) {
                Item temp = mochilaVet[j];
                mochilaVet[j] = mochilaVet[j + 1];
                mochilaVet[j + 1] = temp;
            }
        }
    }
    printf("\nVetor ordenado por nome.\n");
}

// Busca binária
void buscarBinariaVetor() {
    char nomeBusca[30];
    comparacoesBinaria = 0;

    printf("\nNome do item (busca binária): ");
    scanf("%s", nomeBusca);

    int inicio = 0, fim = totalItensVet - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoesBinaria++;

        int cmp = strcmp(mochilaVet[meio].nome, nomeBusca);

        if (cmp == 0) {
            printf("Item encontrado!\n");
            printf("Comparações (binária): %d\n", comparacoesBinaria);
            return;
        }
        else if (cmp < 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    printf("Item não encontrado.\n");
    printf("Comparações (binária): %d\n", comparacoesBinaria);
}

// =============================================================
//       FUNÇÕES — VERSÃO USANDO **LISTA ENCADEADA**
// =============================================================

No* inicioLista = NULL;

// Inserir
void inserirItemLista() {
    No* novo = (No*)malloc(sizeof(No));

    printf("\n--- Cadastro de Item (Lista) ---\n");
    printf("Nome: ");
    scanf("%s", novo->dados.nome);
    printf("Tipo: ");
    scanf("%s", novo->dados.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    novo->proximo = inicioLista;
    inicioLista = novo;

    printf("Item inserido!\n");
}

// Remover
void removerItemLista() {
    char nomeBusca[30];
    printf("\nNome do item a remover: ");
    scanf("%s", nomeBusca);

    No* atual = inicioLista;
    No* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nomeBusca) == 0) {
            if (anterior == NULL)
                inicioLista = atual->proximo;
            else
                anterior->proximo = atual->proximo;

            free(atual);
            printf("Item removido!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Item não encontrado.\n");
}

// Listar
void listarItensLista() {
    printf("\n--- Mochila (Lista Encadeada) ---\n");

    No* aux = inicioLista;
    if (!aux) {
        printf("Lista vazia.\n");
        return;
    }

    while (aux != NULL) {
        printf("%s | %s | %d\n",
               aux->dados.nome, aux->dados.tipo, aux->dados.quantidade);
        aux = aux->proximo;
    }
}

// Busca sequencial na lista
void buscarItemLista() {
    char nomeBusca[30];
    comparacoesSequencial = 0;

    printf("\nNome do item: ");
    scanf("%s", nomeBusca);

    No* aux = inicioLista;

    while (aux != NULL) {
        comparacoesSequencial++;

        if (strcmp(aux->dados.nome, nomeBusca) == 0) {
            printf("Item encontrado!\n");
            printf("Comparações: %d\n", comparacoesSequencial);
            return;
        }
        aux = aux->proximo;
    }

    printf("Item não encontrado.\n");
    printf("Comparações: %d\n", comparacoesSequencial);
}

// =============================================================
//                      MENU PRINCIPAL
// =============================================================

void menuVetor() {
    int opc;

    do {
        printf("\n=== Mochila (Vetor) ===\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Listar\n");
        printf("4 - Buscar sequencial\n");
        printf("5 - Ordenar\n");
        printf("6 - Buscar binária\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opc);

        switch (opc) {
        case 1: inserirItemVetor(); break;
        case 2: removerItemVetor(); break;
        case 3: listarItensVetor(); break;
        case 4: buscarSequencialVetor(); break;
        case 5: ordenarVetor(); break;
        case 6: buscarBinariaVetor(); break;
        }
    } while (opc != 0);
}

void menuLista() {
    int opc;

    do {
        printf("\n=== Mochila (Lista Encadeada) ===\n");
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Listar\n");
        printf("4 - Buscar sequencial\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opc);

        switch (opc) {
        case 1: inserirItemLista(); break;
        case 2: removerItemLista(); break;
        case 3: listarItensLista(); break;
        case 4: buscarItemLista(); break;
        }
    } while (opc != 0);
}

int main() {
    int opc;

    do {
        printf("\n=== Sistema da Mochila ===\n");
        printf("1 - Usar Vetor\n");
        printf("2 - Usar Lista Encadeada\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opc);

        switch (opc) {
        case 1: menuVetor(); break;
        case 2: menuLista(); break;
        case 0: printf("Saindo...\n"); break;
        default: printf("Opção inválida!\n");
        }
    } while (opc != 0);

    return 0;
}
