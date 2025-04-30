#include <stdio.h>

#define TAM 10

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0; // 0 = água
}

int podeColocar(int tabuleiro[TAM][TAM], int x, int y, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        int nx = x, ny = y;
        if (direcao == 'H') ny += i;
        else if (direcao == 'V') nx += i;

        if (nx < 0 || ny < 0 || nx >= TAM || ny >= TAM || tabuleiro[nx][ny] != 0)
            return 0;
    }
    return 1;
}

void colocarNavio(int tabuleiro[TAM][TAM], int x, int y, int tamanho, char direcao) {
    if (podeColocar(tabuleiro, x, y, tamanho, direcao)) {
        for (int i = 0; i < tamanho; i++) {
            if (direcao == 'H') tabuleiro[x][y + i] = 3;
            else tabuleiro[x + i][y] = 3;
        }
    }
}

void colocarDiagonalPrincipal(int tabuleiro[TAM][TAM], int inicio, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if (tabuleiro[inicio + i][inicio + i] != 0)
            return;

    for (int i = 0; i < tamanho; i++)
        tabuleiro[inicio + i][inicio + i] = 3;
}

void colocarDiagonalSecundaria(int tabuleiro[TAM][TAM], int inicio, int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if (tabuleiro[inicio + i][TAM - 1 - (inicio + i)] != 0)
            return;

    for (int i = 0; i < tamanho; i++)
        tabuleiro[inicio + i][TAM - 1 - (inicio + i)] = 3;
}

void mostrarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%2d ", tabuleiro[i][j]);
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro);

    colocarNavio(tabuleiro, 0, 0, 4, 'H');  // navio horizontal
    colocarNavio(tabuleiro, 2, 2, 3, 'V');  // navio vertical
    colocarDiagonalPrincipal(tabuleiro, 5, 3);   // navio na diagonal 
    colocarDiagonalSecundaria(tabuleiro, 0, 4);  // navio na diagonal 

    mostrarTabuleiro(tabuleiro);

    return 0;
}