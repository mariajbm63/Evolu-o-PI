#include <stdio.h>

// matriz que preenche com as distancias
void inicializarMatrizes(int linha, int coluna, char mapa[linha][coluna + 1], int distancias[linha][coluna]) {
  for (int i = 0; i < linha; i++) {
    scanf("%s", mapa[i]); 
    for (int j = 0; j < coluna; j++) {
      distancias[i][j] = -1; // controle das maiores distancias
    }
  }
}

// fun��o que acha onde a rebeka esta
void encontrarOrigem(int linha, int coluna, char mapa[linha][coluna + 1], int distancias[linha][coluna]) {
  // pegando o ponto em que rebeka esta
  for (int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      if (mapa[i][j] == 'o') {
        distancias[i][j] = 0;
        }
    }
  }
}

// roda a l�gica da onda e imprimir o resultado final
void executarFuga(int linha, int coluna, char mapa[linha][coluna + 1], int distancias[linha][coluna]) {
  // variaveis de controle
  int achouSaida = 0;
  int atualizacao = 1;
  int passo = 0;
  int distanciaFinal = -1;

  // O la�o roda enquanto a puder andar E a sa�da n�o for encontrada
  while (atualizacao == 1 && achouSaida == 0) {
    atualizacao = 0; 

    for (int i = 0; i < linha; i++) {
      for (int j = 0; j < coluna; j++) {
        // local onde rebeka pode passar
        if (distancias[i][j] == passo) {
          // ve se indo pra cima ta liberado
          if (i - 1 >= 0 && achouSaida == 0 && mapa[i - 1][j] != '#' && distancias[i - 1][j] == -1) {
            distancias[i - 1][j] = passo + 1;
            atualizacao = 1;
            if (mapa[i - 1][j] == 'd') {
              achouSaida = 1;
              distanciaFinal = passo + 1;
            }
          }

          // ve se indo pra baixo ta liberado
          if (i + 1 < linha && achouSaida == 0 && mapa[i + 1][j] != '#' && distancias[i + 1][j] == -1) {
            distancias[i + 1][j] = passo + 1;
            atualizacao = 1;
            if (mapa[i + 1][j] == 'd') {
              achouSaida = 1;
              distanciaFinal = passo + 1;
            }
          }

          // ve se indo pra esquerda ta liberado
          if (j - 1 >= 0 && achouSaida == 0 && mapa[i][j - 1] != '#' && distancias[i][j - 1] == -1) {
            distancias[i][j - 1] = passo + 1;
            atualizacao = 1;
            if (mapa[i][j - 1] == 'd') {
              achouSaida = 1;
              distanciaFinal = passo + 1;
            }
          }

          // ve se indo pra direita ta liberado
          if (j + 1 < coluna && achouSaida == 0 && mapa[i][j + 1] != '#' && distancias[i][j + 1] == -1) {
            distancias[i][j + 1] = passo + 1;
            atualizacao = 1;
            if (mapa[i][j + 1] == 'd') {
              achouSaida = 1;
              distanciaFinal = passo + 1;
            }
          }
        }
      }
    }
        
    // so aumentamos o passo para o pr�ximo turno se ainda n�o achamos a sa�da
    if (achouSaida == 0) {
      passo++;
    }
  }

  // impress�o do Resultado Final
  if (achouSaida == 1) {
    printf("Apos correr %d metros e quase desistir por causa da dist�ncia, Rebeka conseguiu escapar!\n", distanciaFinal);
  } else {
    printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
  }
}

int main() {
  int linha;
  int coluna;
  scanf("%dx%d", &linha, &coluna);

  // duas matrizes que armazenam a distancia e o mapa da fuga em si
  char mapa[linha][coluna + 1];
  int distancias[linha][coluna];

  // Chamada das fun��es
  inicializarMatrizes(linha, coluna, mapa, distancias);
  encontrarOrigem(linha, coluna, mapa, distancias);
  executarFuga(linha, coluna, mapa, distancias);

  return 0;
}
