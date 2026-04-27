#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//------------------------- FUNÇÕES DE OPERAÇÕES ----------------------

int dobro(int valor) {
  return valor * 2;
}

int quadrado(int valor) {
  return valor * valor;
}

int absoluto(int valor) {
  return abs(valor);
}

//---------------------------------------------------------------------
// função que aloca a matriz dinamicamente e fazendo o malloc saber que ele vai retornar numeros pra sua alteração - função obrigatoria
int *alocacao(int linha, int coluna) {
  int *matriz = (int *)malloc(linha * coluna * sizeof(int));
  return matriz;
}

// recebendo a matriz - função obrigatoria
void leitura(int linha, int coluna, int *matriz) {
  int i = 0;
  int numAtual;
  while(i < linha * coluna) {
    scanf("%d", &numAtual);
    matriz[i] = numAtual;
    i++;
  }
}

// aqui faz o ponteiro de uma função pras operações - função obrigatoria
void aplicarOperacao(int linha, int coluna, int (*operacao)(int), int *matriz) {
  int i = 0;
  while(i < linha * coluna) {
    matriz[i] = operacao(matriz[i]);
    i++;
  }
}

// imprimo a matriz - função obrigatoria
void print(int linha, int coluna, int *matriz) {
  int i = 0;
  int pularLinha = 0;

  while(i < linha * coluna) {
    pularLinha++;
    printf("%d ", matriz[i]);

    if(pularLinha == coluna) {
      printf("\n");
      pularLinha = 0;
    }
    i++;
  }
}

// liberar a memoria que foi alocada - função obrigatoria
void liberacao(int *matriz) {
  free(matriz);
}

//---------------------------------------------------------------------

int main() {
  // aqui eu recebo os inputs iniciais, crio a memoria do espaço da matriz com a função de alocação e chamo a função de leitura pra formar a matriz
  int linha, coluna, operacao;
  scanf("%d %d", &linha, &coluna);
  int *matriz = alocacao(linha, coluna);
  leitura(linha, coluna, matriz);
  scanf("%d", &operacao);

  // bloco condicional para decidir qual será a operação
  if(operacao == 1) {
    aplicarOperacao(linha, coluna, dobro, matriz);
  } else if (operacao == 2) {
    aplicarOperacao(linha, coluna, quadrado, matriz);
  } else {
    aplicarOperacao(linha, coluna, absoluto, matriz);
  }

  // chamada da função print e da liberação, pra print a matriz final e liberar a memoria alocada
  print(linha, coluna, matriz);
  liberacao(matriz);
  return 0;
}
