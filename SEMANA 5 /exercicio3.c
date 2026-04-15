#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mesclagem(int n, char *strings, int *inicios, int *tamanhos) {
  int maiorStr = 0;
  int tamanhoTotal = 0;
  
  // aqui eu percorro a string gigante que juntei todos os inputs pra fazer a alocação de memoria certinha
  for(int i = 0; i < n; i++) {
    tamanhoTotal += tamanhos[i];
    
    if(tamanhos[i] > maiorStr) {
      maiorStr = tamanhos[i];
    }
  }
  
  char *mergedString = malloc((tamanhoTotal + 1) * sizeof(char));
  int pos = 0;

  // aqui eu reescrevo eka da forma correta
  for(int i = 0; i < maiorStr; i++) {
    for(int j = 0; j < n; j++) {
      if(i < tamanhos[j]) {
        mergedString[pos] = strings[inicios[j] + i];
        pos++;
      }
    }
  }

  // coloco o barra zero no final como confição de parada
  mergedString[pos] = '\0';
  return mergedString;
}

void fusao(char *lista) {
  int mudou;
  do {
    mudou = 0;
    int i = 0;
    // aqui eu percorro toda a lista ja mesclada
    while (lista[i] != '\0' && lista[i + 1] != '\0') {
      // se for igual vou fazer a fusão + a situação do z
      if (lista[i] == lista[i + 1]) {
        if (lista[i] == 'z') {
          lista[i] = 'a';
        } else {
          lista[i] = lista[i] + 1;
        }

        // aqui eu ando pra esquerda
        for (int j = i + 1; lista[j] != '\0'; j++) {
          lista[j] = lista[j + 1];
        }

        // aqui eu vejo de novo o i pra caso ter a possibilidade de fazer a fusão com a anterior ou andar mais
        mudou = 1;
        if (i > 0) {
          i--;
        }
      } else {
        i++;
      }
    }
  } while (mudou);
}

int main() {
  int N;
  scanf("%d", &N);
  while(getchar() != '\n');

  char *vetorPonteiro = malloc(1 * sizeof(char));
  int *inicios = malloc(N * sizeof(int));
  int *tamanhos = malloc(N * sizeof(int));
  int tamanhoTotal = 0;

  // aqui eu recebo tudo e defino o começo, os tamnhos de cada entrada e junto letra por letra no vetorPonteiro
  for(int i = 0; i < N; i++) {
    inicios[i] = tamanhoTotal;
    int lenStrAtual = 0;
    char letra;

    while(scanf("%c", &letra) == 1 && letra != '\n') {
      vetorPonteiro = realloc(vetorPonteiro, (tamanhoTotal + 1) * sizeof(char));
      vetorPonteiro[tamanhoTotal] = letra;
      tamanhoTotal++;
      lenStrAtual++;
    }

    tamanhos[i] = lenStrAtual;
  }

  // chamada das funções
  char *mergedString = mesclagem(N, vetorPonteiro, inicios, tamanhos);
  printf("%s\n", mergedString);

  fusao(mergedString);
  printf("%s", mergedString);
  

  free(vetorPonteiro);
  free(inicios);
  free(tamanhos);
  free(mergedString);

  return 0;
}
