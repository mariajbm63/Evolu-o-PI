#include <stdio.h>
#include <string.h>

// fun??o que incrementa cada posi??o que o reyn?oseioq passou
void coordenadas(int tamanhoM, char array[], int vetorBi[100][100], int x1, int y1) {
  for(int i = 0; i < tamanhoM; i++) {
    if(array[i] == 'c' || array[i] == 'b' || array[i] == 'e' || array[i] == 'd') {
      int moveu = 0;

      if(array[i] == 'c' && x1 > 0) {
        x1--;
        moveu = 1;
      }
      else if(array[i] == 'b' && x1 < 3) {
        x1++;
        moveu = 1;
      }
      else if(array[i] == 'e' && y1 > 0) {
        y1--;
        moveu = 1;
      }
      else if(array[i] == 'd' && y1 < 3) {
        y1++;
        moveu = 1;
      }
      
      if (moveu == 1) {
        vetorBi[x1][y1] += 1;
      }
    }
  }
}

// fun??o que pega o ponto mais visito pelo rey, sendo ele o local que manuela estaria e que ele deve evitar
void verificarCoordenadaManuela(int matriz[100][100], int resultado[3]) {
  for(int x = 0; x < 4; x++) {
    for(int y = 0; y < 4; y++) {
      if(matriz[x][y] > resultado[0]) {
        resultado[0] = matriz[x][y];
        resultado[1] = x;
        resultado[2] = y;
      }
    }
  }
}

int main() {
  // variaveis iniciais
  char lista[100];
  scanf(" %[^\n]", lista);
  int len = strlen(lista);
  int x = 0;
  int y = 0;
  int matriz[100][100] = {0};

  // como em c a fun??o so da return em um resultado, diferente de python, usei um vetor pra armazenar os resultados finais e conseguir manipula-los
  int resultado[3] = {-1, 0, 0};

  // chamada das fun??es
  coordenadas(len, lista, matriz, x, y);
  verificarCoordenadaManuela(matriz, resultado);

  // printf do resultado
  printf("Coordenada X:%d, Y:%d", resultado[2], resultado[1]);

  return 0;
}
