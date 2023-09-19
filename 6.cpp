#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLS 3

typedef struct {
    int linha;
    int col;
} Posicao;

Posicao searchMatrix(int matriz[LINHAS][COLS], int value) {
    Posicao pos = {-1, -1};  // Valor inicial, indicando que não foi encontrado

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matriz[i][j] == value) {
                pos.linha = i;
                pos.col = j;
                return pos;  // Retorna a posição da primeira ocorrência
            }
        }
    }
    return pos;  // Retorna {-1, -1} se não encontrado
}

int main() {
    int matriz[LINHAS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int value;
    printf("Digite um valor para buscar: ");
    scanf("%d", &value);

    Posicao pos = searchMatrix(matriz, value);
    if (pos.linha != -1) {
        printf("Valor encontrado na posicao: [%d][%d]\n", pos.linha, pos.col);
    } else {
        printf("Valor nao encontrado.\n");
    }

    return 0;
}

