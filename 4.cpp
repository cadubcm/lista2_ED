#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 3

void troca(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int indexLinear(int row, int col) {
    return row * COLUNAS + col;
}

void quickSort(int matriz[LINHAS][COLUNAS], int left, int right) {
    if (left >= right) return;

    int pivot = matriz[right / COLUNAS][right % COLUNAS];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (matriz[j / COLUNAS][j % COLUNAS] < pivot) {
            i++;
            troca(&matriz[i / COLUNAS][i % COLUNAS], &matriz[j / COLUNAS][j % COLUNAS]);
        }
    }
    troca(&matriz[(i + 1) / COLUNAS][(i + 1) % COLUNAS], &matriz[right / COLUNAS][right % COLUNAS]);

    int pi = i + 1;
    quickSort(matriz, left, pi - 1);
    quickSort(matriz, pi + 1, right);
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

    quickSort(matriz, 0, LINHAS*COLUNAS - 1);

    printf("\nMatriz ordenada:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
