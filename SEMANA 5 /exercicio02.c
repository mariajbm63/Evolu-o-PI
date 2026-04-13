#include <stdio.h>
#include <stdlib.h>

// função de media
float media(float *notas, int qtdeAlunos) {
  float soma = 0.0;
  for(int i = 0; i < qtdeAlunos; i++) {
    soma = soma + notas[i];
  }
  float media = soma / qtdeAlunos;
  
  return media;
}

// função de moda
float moda(int qtdeAlunos, float *notas) {
  float moda = notas[0];
  int contagem = 0;
  int teveEmpate = 0;
  
  // aqui eu acho qual o numero mais se repete
  for(int i = 0; i < qtdeAlunos; i++) {
    int contagemAtual = 0;
    for(int j = 0; j < qtdeAlunos; j++) {
      if(notas[i] == notas[j]) {
        contagemAtual++;
      }
    }

    // aqui eu vejo duas situações, se ela ja pode ser atualizada pra o valor da moda ou se teve empate
    if(contagem < contagemAtual) {
      contagem = contagemAtual;
      moda = notas[i];
      teveEmpate = 0;
    } else if(contagem == contagemAtual && notas[i] != moda) {
      teveEmpate = 1;
    }
  }

  // se teve empate ela me retona um numero especifico
  if(teveEmpate == 1) {
    moda = -1.0;
  }

  return moda;
}

// função de quantos alunos foram aprovados por media
int passou(int qtdeAlunos, float *notas, float media) {
  int maiorQMedia = 0;
  for(int i = 0; i < qtdeAlunos; i++) {
    if(notas[i] > media) {
      maiorQMedia++;
    }
  }

  return maiorQMedia;
}

// função da mediana
float mediana(int qtdeAlunos, float *notas) {
  float mediana = 0.0;
  // primeiro faço um bubble sort para ordenar o vetor de notas
  for(int i = 0; i < qtdeAlunos; i++) {
    for(int j = 0; j < qtdeAlunos - 1; j++) {
      float troca = notas[j];
      if(notas[j] < notas[j + 1]) {
        notas[j] = notas[j + 1];
        notas[j + 1] = troca;
      }
    }
  }

  // aqui é caso a lista seja impar, eu pego o termo central e ele é a mediana
  if(qtdeAlunos % 2 != 0) {
    int index = qtdeAlunos / 2;
    mediana = notas[index];
  }
  // se o tamanho da lista for par, eu pego o termo do meio e o anterior a ele, e tiro a media dos dois
  else {
    int index1 = (qtdeAlunos / 2) - 1;
    int index2 = (qtdeAlunos / 2);
    mediana = (notas[index1] + notas[index2]) / 2;
  }

  return mediana;
}

// função do primeiro relatorio
void relatorio1(float media, float resultado[1], int passou, float mediana, float moda, float *indices, int qtdeAlunos, float *notas) {
  int indexMaior = -1;
  int indexMenor = -1;
  int parou = 0;
  int parou2 = 0;

  // aqui eu acho o aluno de menor nota, o aluno de maior nota e suas respectivas notas. Levando em conta que se tiver alunos com as mesmas notas, eu considero o primeiro que achei com uma flag
  for(int i = 0; i < qtdeAlunos; i++) {
    if(notas[0] == indices[i] && parou == 0) {
      indexMaior = i + 1;
      parou = 1;
    }
    if(notas[qtdeAlunos - 1] == indices[i] && parou2 == 0) {
      indexMenor = i + 1;
      parou2 = 1;
    }
  }

  printf("Relatorio inicial\n");
  printf("Media: %.2f\n", media);
  printf("Maior nota: %.2f (aluno %d)\n", notas[0], indexMaior);
  printf("Menor nota: %.2f (aluno %d)\n", notas[qtdeAlunos - 1], indexMenor);
  printf("Acima da media: %d\n", passou);
  printf("Mediana: %.2f\n", mediana);
  // o caso da moda ser mais de um numero
  if(moda == -1.0) {
    printf("Moda: Nao ha moda unica\n");
  }
  else {
    printf("Moda: %.2f\n", moda);
  }
}

void relatorio2(float media, float resultado[1], int passou, float mediana, float moda, float *indices,int qtdeAlunos, float *notas) {
  int indexMaior = -1;
  int indexMenor = -1;
  int parou = 0;
  int parou2 = 0;

  // mesma coisa que o relatorio1, mas agora no 2
  for(int i = 0; i < qtdeAlunos; i++) {
    if(notas[0] == indices[i] && parou == 0) {
      indexMaior = i + 1;
      parou = 1;
    }
    if(notas[qtdeAlunos - 1] == indices[i] && parou2 == 0) {
      indexMenor = i + 1;
      parou2 = 1;
    }
  }

  printf("Relatorio atualizado\n");
  printf("Media: %.2f\n", media);
  printf("Maior nota: %.2f (aluno %d)\n", notas[0], indexMaior);
  printf("Menor nota: %.2f (aluno %d)\n", notas[qtdeAlunos - 1], indexMenor);
  printf("Acima da media: %d\n", passou);
  printf("Mediana: %.2f\n", mediana);
  if(moda == -1.0) {
    printf("Moda: Nao ha moda unica");
  }
  else {
    printf("Moda: %.2f", moda);
  }
}

int main() {
  int n;
  int k;
  scanf("%d", &n);
  float *notasVetor = malloc(n * sizeof(float)); // lista do input que vou alterar com o bubble sort
  float *indices = malloc(n * sizeof(float)); // essa lista eu deixo guardada a ordem original do input pra saber qual o local exato do aluno
  float maiorMenorNotas[1] = {-1.0}; // como as funções so retornam um valor, eu criei uma lista com duas variaveis pra armazenar o maior e o menor valor

  for(int i = 0; i < n; i++) {
    float nota;
    scanf("%f", &nota);
    notasVetor[i] = nota;
    indices[i] = nota;
  }

  // chamada das funções
  float mediaVariavel = media(notasVetor, n);
  float modaVariavel = moda(n, notasVetor);
  int passouVariavel = passou(n, notasVetor, mediaVariavel);
  float medianaVariavel = mediana(n, notasVetor);
  relatorio1(mediaVariavel, maiorMenorNotas, passouVariavel, medianaVariavel, modaVariavel, indices, n, notasVetor);
  
  // caso precise de realocação de memoria
  scanf("%d", &k);
  if (k > 0) {
    int m = k + n;
    notasVetor = realloc(notasVetor, m * sizeof(float));
    indices = realloc(indices, m * sizeof(float));

    for(int i = 0; i < k; i++) {
      float nota;
      scanf("%f", &nota);
      notasVetor[n + i] = nota;
      indices[n + i] = nota;
    }
  
    printf("\n");
    float mediaVariavel2 = media(notasVetor, m);
    float modaVariavel2 = moda(m, notasVetor);
    int passouVariavel2 = passou(m, notasVetor, mediaVariavel2);
    float medianaVariavel2 = mediana(m, notasVetor);
    relatorio2(mediaVariavel2, maiorMenorNotas, passouVariavel2, medianaVariavel2, modaVariavel2, indices, m, notasVetor);
  }
  else {
    printf("\n");
    relatorio2(mediaVariavel, maiorMenorNotas, passouVariavel, medianaVariavel, modaVariavel, indices, n, notasVetor);
  }

  free(indices);
  free(notasVetor);

  return 0;
}
