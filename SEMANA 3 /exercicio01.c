#include <stdio.h>

int main() {
  int T, N;
  scanf("%d", &T);

  // esse for serve pra percorrer a quantidade de vetores
  for(int i = 0; i < T; i++) {
    scanf("%d", &N);
    int lista[N];
    
    // esse for serve pra gerar o vetor de acordo com o seu tamanho
    for(int j = 0; j < N; j++) {
      scanf("%d", &lista[j]);
    }

    // variaveis de controle
    int seqAtual = 1;
    int maiorSeq = 1;
    int fim = 0;

    // esse for serve pra percorrer o vetor
    for(int k = 0; k < N - 1; k++) {
      // aqui vê se a sequencia é decrecemte e se for aumenta na sequencia, caso não a 'zera'
      if(lista[k] > lista[k + 1]) {
        seqAtual++;
      }
      else {
        seqAtual = 1;
      }

      // aqui é pra descobrir onde o vetor termina e atualizae a maior sequencia
      if(seqAtual > maiorSeq) {
        maiorSeq = seqAtual;
        fim = k + 1;
      }
    }

    // aqui é se não tiver sequencia decrecente imprime 0
    if (maiorSeq == 1) {
      printf("0\n");
    }
    // caso tiver sequencia, imrpime a maior de acordo com o inicio
    else {
      printf("%d\n", maiorSeq);
      int inicio = fim - maiorSeq + 1;
      for(int l = 0; l < maiorSeq; l++) {
        printf("%d ", lista[inicio + l]);
      }
      printf("\n");
    }
  }
return 0;
}
