#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 3

void insertionSort(int matriz[LINHAS][COLUNAS]) {
    for (int i = 1; i < LINHAS * COLUNAS; i++) {
        int key = matriz[i / COLUNAS][i % COLUNAS];
        int j = i - 1;

        while (j >= 0 && matriz[j / COLUNAS][j % COLUNAS] > key) {
            matriz[(j + 1) / COLUNAS][(j + 1) % COLUNAS] = matriz[j / COLUNAS][j % COLUNAS];
            j--;
        }
        matriz[(j + 1) / COLUNAS][(j + 1) % COLUNAS] = key;
    }
}

int main() {
    int matriz[LINHAS][COLUNAS];

    printf("Matriz original:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = rand() % 100; 
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    insertionSort(matriz);

    printf("\nMatriz ordenada:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
