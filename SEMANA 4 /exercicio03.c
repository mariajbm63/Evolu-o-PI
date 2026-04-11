#include <stdio.h>

// fun��o que espalha as gotas
void espalharGotas(int linha, int coluna, char matriz[linha][coluna + 1]) {
  for(int i = 0; i < linha - 1; i++) {
    for(int j = 0; j < coluna; j++) {

      // esse if pega a posi��o das gotas
      if(matriz[i][j] == 'o') {
        // esse espalha a gota automaticamente se ela estiver caindo e n�o tiver estantes embaixo
        if(matriz[i + 1][j] == '.') {
          matriz[i + 1][j] = 'o'; 
        }
        // agora � o casp em que a gota cai e tem estante embaixo
        else if(matriz[i + 1][j] == '#') {
          int parada = 0; // flag de parada
          int esquerda = j - 1; // 'incremento' pra andar a esquerda
          // ent�o enquanto n�o tiver pra onde a gota escorrer ela anda pra esquerda
          while(esquerda >= 0 && parada == 0) {
            matriz[i][esquerda] = 'o';

            // a gota escorreu, parou
            if(matriz[i + 1][esquerda] == '.') {
              matriz[i + 1][esquerda] = 'o';
              parada = 1;
            }
            // a gota n�o escorreu, n�o parou
            else {
              esquerda--;
            }
          }

          int parada2 = 0; // flag de parada
          int direita = j + 1; // 'incremento' pra andar a direita
          // ent�o enquanto n�o tiver pra onde a gota escorrer ela anda pra direita
          while(direita < coluna && parada2 == 0) {
            matriz[i][direita] = 'o';

            // a gota escorreu, parou
            if(matriz[i + 1][direita] == '.') {
              matriz[i + 1][direita] = 'o';
              parada2 = 1;
            }
            // a gota n�o escorreu, n�o parou
            else {
              direita++;
            }
          }
          // atualiza a posi��o pra n�o verificar uma que ja foi
          j = direita;
        }
      }
    }
  }
}

// fun�a� que imprime a nova matriz
void imprimir(int linha, int coluna, char matriz[linha][coluna + 1]) {
for(int i = 0; i < linha; i++) {
  for(int j = 0; j < coluna; j++) {
    printf("%c", matriz[i][j]);
    }
  printf("\n");
  }
}

int main() {
  // variaveis iniciais
  int linha;
  int coluna;

  scanf("%d %d", &linha, &coluna);
  char matriz[linha][coluna + 1];
  char vetor[coluna + 1];

  // forma��o da matriz de entrada
  for(int i = 0; i < linha; i++) {
    scanf("%s", vetor);
    for(int j = 0; j < coluna; j++) {
      matriz[i][j] = vetor[j];
      }
  }

  // chamada das fun��es
  espalharGotas(linha, coluna, matriz);
  imprimir(linha, coluna, matriz);
  
  return 0;
}
