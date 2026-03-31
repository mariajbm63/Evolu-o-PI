#include <stdio.h>

int main() {
  // aqui eu inicializo as variaveis de acordo com oq vou receber de input
  int N;
  int X;
  int A, B;

  scanf("%d", &N);
  scanf("%d %d", &A, &B);

  /* aqui eu faço a soma de todos os termos dado, 
  tipo o exemplo de 10, 1 + 2 + 3 ... + 10 */
  int somaTotal = N * (1 + N) / 2;

  /* aqui eu separo a quantidade de multimplos de A que existe em N*/
  int qtdeA = N / A;
  int A2 = qtdeA * A;
  int somaA = qtdeA * (A + A2) / 2;

  /* aqui eu separo a quantidade de multimplos de B que existe em N*/
  int qtdeB = N / B;
  int B2 = qtdeB * B;
  int somaB = qtdeB * (B + B2) / 2;

  /* aqui eu separo a quantidade de multimplos de A e B em comum que existe em N*/
  int AB = A * B;
  int qtdeAB = N / AB;
  int AB2 = qtdeAB * AB;
  int somaAB = qtdeAB * (AB + AB2) / 2;

  // aqui eu tiro os multimos de A e B, e volto com os multiplos de AB
  int soma = somaTotal - somaA - somaB + somaAB;

  if (soma % 2 == 0) {
    printf("%d\n", soma);
    printf("Lá ele!!!");
  }
  else {
    printf("%d\n", soma);
    printf("Opa xupenio AULAS...");
  }
  return 0;
}
