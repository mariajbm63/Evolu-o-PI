#include <stdio.h>
#include <stdlib.h>

// função de alocação que me retorna o endereço do ponteiro com os numeros armazenados
int* alocacao(int *tamanho) {
  int numero;
  int memoria = 1;
  int index = 0;
  int *vetorPonteiro = malloc(memoria * sizeof(int));

  // aqui roda ate chegar o fim fos inputs
  while(scanf("%d", &numero) != EOF) {
    vetorPonteiro[index] = numero;
    index++;

    // se precisa de mais espaço, cria mais espaço
    if(index == memoria) {
      memoria = memoria * 2;
      vetorPonteiro = realloc(vetorPonteiro, memoria * sizeof(int));
    }
  }

  *tamanho = index;

  return vetorPonteiro;
}

// função de printar o resultado pedido
void imparesPares(int posiAtual, int *vetorPonteiro) {
  printf("Mais um bom dia de trabalho!\n");
  for(int i = 0; i < posiAtual; i++){
    if(vetorPonteiro[i] % 2 != 0) {
      printf("%d\n", vetorPonteiro[i]);
    }
  }
  for(int i = 0; i < posiAtual; i++){
    if(vetorPonteiro[i] % 2 == 0) {
      printf("%d\n", vetorPonteiro[i]);
    }
  }
  printf("Vou visitar esses lugares de novo... algum dia.\n");
}

int main() {
  int posiAtual = 0;
  int *vetor;

  // chamada das funções + o free
  vetor = alocacao(&posiAtual);
  imparesPares(posiAtual, vetor);
  free(vetor);

  return 0;
}
