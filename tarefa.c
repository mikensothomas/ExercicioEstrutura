#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct {
    char nome[50];
} Tarefa;

void adicionar_tarefa(Tarefa lista[], int num_tarefas) {
    if (num_tarefas < TAM) {
        printf("Digite o nome da nova tarefa: ");
        scanf("%s", lista[num_tarefas].nome);
        printf("Tarefa adicionada com sucesso!\n");
    } else {
        printf("A lista de tarefas está cheia!\n");
    }
}

void listar_tarefas(Tarefa lista[], int num_tarefas) {
    printf("\nLista de Tarefas:\n");
    for (int i = 0; i < num_tarefas; i++) {
        printf("%d. %s\n", i + 1, lista[i].nome);
    }
}

void remover_tarefa(Tarefa lista[], int *num_tarefas) {
    if (*num_tarefas > 0) {
        int indice;
        printf("Digite o número da tarefa a ser removida: ");
        scanf("%d", &indice);

        if (indice >= 1 && indice <= *num_tarefas) {
            for (int i = indice - 1; i < *num_tarefas - 1; i++) {
                lista[i] = lista[i + 1];
            }
            (*num_tarefas)--;
            printf("Tarefa removida com sucesso!\n");
        } else {
            printf("Índice inválido!\n");
        }
    } else {
        printf("Não há tarefas para remover!\n");
    }
}

int main() {
    Tarefa listaTarefas[TAM];
    int num_tarefas = 0;
    int opcao;

    do {
        printf("FAÇA UMA ESCOLHA NO MENU\n\n");
        printf("\t1 - Adicionar uma nova tarefa\n\t2 - Listar todas as tarefa\n\t3 - Remover tarefa\n\t4 - Enserrar programa\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_tarefa(listaTarefas, num_tarefas);
                num_tarefas++;
                break;
            case 2:
                listar_tarefas(listaTarefas, num_tarefas);
                break;
            case 3:
                remover_tarefa(listaTarefas, &num_tarefas);
                break;
            case 4:
                printf("Programa encerrado.\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao);

    return 0;
}