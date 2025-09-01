#include <stdio.h>

#define TAM 10     // Tamanho do tabuleiro
#define NAVIO 3    // Valor do navio
#define HABIL 5    // Valor da área afetada
#define TAM_HAB 5  // Tamanho da matriz de habilidade (5x5)

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAM; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origem_linha, int origem_coluna) {
    int offset = TAM_HAB / 2; // deslocamento para centralizar

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origem_linha - offset + i;
            int coluna = origem_coluna - offset + j;

            // Verifica se está dentro dos limites do tabuleiro
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != NAVIO) {
                    tabuleiro[linha][coluna] = HABIL;
                }
            }
        }
    }
}

// Gera uma matriz em forma de cone (triângulo apontando para baixo)
void gerarCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2) - i && j <= (TAM_HAB / 2) + i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera uma matriz em forma de cruz
void gerarCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera uma matriz em forma de octaedro (losango)
void gerarOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Posicionando navios
    tabuleiro[1][2] = tabuleiro[1][3] = tabuleiro[1][4] = NAVIO;
    tabuleiro[5][6] = tabuleiro[6][6] = tabuleiro[7][6] = NAVIO;
    tabuleiro[0][0] = tabuleiro[1][1] = tabuleiro[2][2] = NAVIO;
    tabuleiro[7][2] = tabuleiro[8][1] = tabuleiro[9][0] = NAVIO;

    // Matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplicando habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);      // Cone centrado em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 6, 6);      // Cruz centrada em (6,6)
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);  // Octaedro centrado em (8,8)

    // Imprimir tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}