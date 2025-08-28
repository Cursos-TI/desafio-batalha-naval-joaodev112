#include <stdio.h>

#define TAM 10

int main() {
    int tabuleiro[TAM][TAM] = {0};

    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[2][6] = 3;

    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    printf("   ");  // Espaço para alinhar com números das linhas
    for (char letra = 'A'; letra < 'A' + TAM; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Imprime o tabuleiro com números das linhas alinhados
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);  // Linha numerada (com largura 2)
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
