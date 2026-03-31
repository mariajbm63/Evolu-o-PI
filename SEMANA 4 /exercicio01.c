#include <stdio.h>

// função que muda as decorações
void decoracoes(int linha, int coluna, char matriz[linha][coluna]) {
    for(int i = 0; i < linha; i++) {
        for(int j = 0; j < coluna; j++) {
            // verifica onde esta o poste e muda de acordo com as condiçoes
            if((matriz[i][j] == 'P')) {

                // bloco da mudaça das diagonais primeiro
                if((j - 1 >= 0) && (i + 1 < linha) && (matriz[i + 1][j - 1] == '-')) {
                    matriz[i + 1][j - 1] = 'x';
                }
                if((i - 1 >= 0) && (j - 1 >= 0) && (matriz[i - 1][j - 1] == '-')) {
                    matriz[i - 1][j - 1] = 'x';
                }
                if((i - 1 >= 0) && (j + 1 < coluna) && (matriz[i - 1][j + 1] == '-')) {
                    matriz[i - 1][j + 1] = 'x';
                }
                if((i + 1 < linha) && (j + 1 < coluna) && (matriz[i + 1][j + 1] == '-')) {
                    matriz[i + 1][j + 1] = 'x';
                }

                // bloco que muda os vizinhos a esquerda, direita, em cima e em baixo, e prevalece o + se tiver um mudado pra um x
                if((i + 1 < linha) && (matriz[i + 1][j] == '-' || matriz[i + 1][j] == 'x')) {
                    matriz[i + 1][j] = '+';
                }
                if((j + 1 < coluna) && (matriz[i][j + 1] == '-' || matriz[i][j + 1] == 'x')) {
                    matriz[i][j + 1] = '+';
                }
                if((i - 1 >= 0) && (matriz[i - 1][j] == '-' || matriz[i - 1][j] == 'x')) {
                    matriz[i - 1][j] = '+';
                }
                if((j - 1 >= 0) && (matriz[i][j - 1] == '-' || matriz[i][j - 1] == 'x')) {
                    matriz[i][j - 1] = '+';
                }
            }
        }
    }
}

// função pra imprimir a matriz depois das decorações
void imprimir(int linha, int coluna, char matriz[linha][coluna]) {
    for(int i = 0; i < linha; i++) {
        for(int j = 0; j < coluna; j++) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}

// função principal que gera a matriz
int main() {
    // variaveis iniciais
    int col;
    int lin;

    scanf("%d %d", &lin, &col);

    char matriz[lin][col];
    char vetor[col + 1];  // +1 por causa do \0

    // formação da matriz a partir de cada input
    for(int i = 0; i < lin; i++) {
        scanf("%s", vetor);
        for(int j = 0; j < col; j++) {
            matriz[i][j] = vetor[j];
        }
    }

    // chamada das funções
    decoracoes(lin, col, matriz);
    imprimir(lin, col, matriz);

    return 0;
}
