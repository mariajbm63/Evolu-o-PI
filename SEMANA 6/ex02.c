#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// o dano foi dado dentro de um max, no exemplo e decidi segui-lo, mas ele so funciona pra float então redefini
#define max(a,b) ((a) > (b) ? (a) : (b))

// ----------------------------------------------------------------------

// função de alocação de memoria da matriz
int **alocacao(int linha, int coluna) {
  int **matriz = (int *)malloc(linha * sizeof(int *));

  for(int i = 0; i < linha; i++) {
    matriz[i] = (int *)malloc(coluna * sizeof(int));
  }

  return matriz;
}

// função de um ponteiro pra aplicar o ataque
void aplicarAtaque(int posiCenX, int posiCenY, int linha, int coluna, int **matrizCopiada, void (*ataque)(int, int, int, int, int**)) {

  ataque(posiCenX, posiCenY, linha, coluna, matrizCopiada);
}

// função que libera a memoria alocada
void liberarMatriz(int linha, int **matriz) {
  for(int i = 0; i < linha; i++) {
    free(matriz[i]); 
  }
  free(matriz); 
}

// função de imprimir a matriz
void imprimirMatriz(int linha, int coluna, int **matriz) {
  for(int i = 0; i < linha; i++) {
    for(int j = 0; j < coluna; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

// -------------------------- FUNÇOES DE ATAQUE -------------------------
void explosaoArcana(int posiCenX, int posiCenY, int linha, int coluna, int **matrizCopia) {
  for(int i = 0; i < linha; i++) {
    for(int j = 0; j < coluna; j++) {
      // aqui eu pego a distancia do centro e da celula atual
      int distX = abs(posiCenX - i);
      int distY = abs(posiCenY - j);

      // depois eu vejo se ele esta na primeira camada
      if(distX + distY <= 1) {
        //  tirando o dano da celula
        int dano = 50;
        int HPAtual = matrizCopia[i][j];
        int HPNovo = max(0, HPAtual - dano);
        matrizCopia[i][j] = HPNovo;
      }
      // para o caso da segunda camada, são os oitos vizinhos da primeira com exeção dos extremos
      else if((distX <= 2 && distY <= 2) && !(distX == 2 && distY == 2)) {
        int dano = 25;
        int HPAtual = matrizCopia[i][j];
        int HPNovo = max(0, HPAtual - dano);
        matrizCopia[i][j] = HPNovo;
      }
    }
  }
}

// função para ver se tem vivos dentro da fumaça venenosa
int verVivos(int linha, int coluna, int **matrizCopia, int alvoX, int alvoY) {
  int playersVizinhos = 0;
  // percorre de uma linha abaixo e acima do vizinho da primeira camada
  for(int x = alvoX - 1; x <= alvoX + 1; x++) {
    for(int y = alvoY - 1; y <= alvoY + 1; y++) {
      if(x >= 0 && x < linha && y >= 0 && y < coluna) {
        if(!(x == alvoX && y == alvoY)) {
          // se tiver vivo, aumenta a quantidade
          if (matrizCopia[x][y] > 0) {
            playersVizinhos++;
          }
        }
      }
    }
  }

  return playersVizinhos;
}

// função da nuvem
void nuvemVenenosa(int posiCenX, int posiCenY, int linha, int coluna, int **matrizCopia) {
  int turno = 0;
  int parou = 0;

  int **matrizTurno = alocacao(linha, coluna);
  
  // enquanto não completar os 3 turnos ou não parar, vai funcionar
  while(turno < 3 && parou == 0) {
    int fumacaovivos = 0;

    for(int i = 0; i < linha; i++) {
      for(int j = 0; j < coluna; j++) {
        matrizTurno[i][j] = matrizCopia[i][j];
      }
    }

    // percorre a matriz e acha a distancia do centro pra celula atual dnv
    for(int i = 0; i < linha; i++) {
      for(int j = 0; j < coluna; j++) {
        int distX = abs(posiCenX - i);
        int distY = abs(posiCenY - j);
        
        // se a celula estiver na primeira e na segunda camada toma dano, novamente com exceção dos extremos
        if((distX <= 2 && distY <= 2) && !(distX == 2 && distY == 2)) {
          // chamada da função pra ver os vivos e calcular o dano
          int qtdeVivos = verVivos(linha, coluna, matrizTurno, i, j);
          int dano = 5 + (8 * qtdeVivos);
          int HPAtual = matrizTurno[i][j];

          matrizCopia[i][j] = max(0, HPAtual - dano);
          if(matrizCopia[i][j] > 0) {
            fumacaovivos = 1;
          }
        }
      }
    }

    // imprime a função a cada turno
    imprimirMatriz(linha, coluna, matrizCopia);
    printf("\n");

    // condição de parada
    if(fumacaovivos == 0) {
      parou = 1;
    }

    turno++;
  }

  liberarMatriz(linha, matrizTurno);
}

// ----------------------------------------------------------------------

int main() {
  // recebe os primeiros inputs
  int M, N;
  scanf("%d %d", &M, &N);
  int **matriz = alocacao(M, N);
  int **matrizCopiada = alocacao(M, N);
  int numAtual;
  
  // constroi a matriz
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      scanf("%d", &numAtual);
      matriz[i][j] = numAtual;
      matrizCopiada[i][j] = numAtual;
    }
  }

  // recebe o resto dos inputs
  int x, y;
  scanf("%d %d", &x, &y);
  char ataque[50];
  scanf("%s", ataque);

  // imprime a matriz original
  printf("Estado inicial do mapa:\n");
  imprimirMatriz(M, N, matriz);
  printf("\n");
  
  // ver qual é o ataque e imprime a matriz copia
  if(strcmp(ataque, "EXPLOSAO_ARCANA") == 0) {
    printf("Estado do mapa após usar a Explosão Arcana:\n");
    aplicarAtaque(x, y, M, N, matrizCopiada, explosaoArcana);
    imprimirMatriz(M, N, matrizCopiada);
  } else if(strcmp(ataque, "NUVEM_VENENOSA") == 0) {
    printf("Estado do mapa, por turno, após usar a Nuvem Venenosa:\n");
    aplicarAtaque(x, y, M, N, matrizCopiada, nuvemVenenosa);
  }

  // chamada da função pra liberar a memoria
  liberarMatriz(M, matriz);
  liberarMatriz(M, matrizCopiada);

  return 0;
}
