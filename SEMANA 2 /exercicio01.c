#include <stdio.h>

int main() {
  // aqui eu armazeno o input da questão
  char letraFinal;
  scanf("%c", &letraFinal);

  // esse é o for geral que conta todas as letras de A(inicio da piramide) ate a ultima letra(final da piramide)
  for(int i = 'A'; i <= letraFinal; i++) {
    // esse for serve para gerar os pontos a direita e como ele é de acordo com a quantidade de letras da coluna fica letraFinal - i pra fazer isso
    for(int l = 0; l < letraFinal - i; l++) {
      printf(".");
    }
    // esse for printa de A ate a letra final pra direita, então ele printa de forma crescente A, B, C, D, ...
    for(int k = 'A'; k <= i; k++) {
      printf("%c", k);
    }
    // esse for printa da antipenultima letra(pq não precisa printar a ultima 2 vezes) ate A, então ele printa de forma decrescente ...D, C, B, A
    for(int j = i - 1; j >= 'A'; j--) {
       printf("%c", j);
    }
    // esse for é a mesma coisa que o primeiro, mas ele printa os pontos da esquerda
    for(int n = 0; n < letraFinal - i; n++) {
      printf(".");
    }
    // quebra de linha para gerar as colunas da piramide
    printf("\n");
  }

  return 0;
}
