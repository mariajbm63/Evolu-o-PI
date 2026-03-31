#include <stdio.h>
#include <string.h>

int main() {
  // iniciando as variaveis
  int qtdeTestes, flashs;
  char configuracao[65];
  char vetorGrande[70000];
  int posVetor = 0;
  
  scanf("%d", &qtdeTestes);

  // esse for diz respeito a quantidade de testes que serão feitps
  for(int i = 0; i < qtdeTestes; i++) {
    scanf("%s %d", configuracao, &flashs);
    int len = strlen(configuracao);
    
    // aqui eu começo percorrendo a quantidade de flashs que serão testados
    for(int k = 0; k < flashs; k++) {
      int parada = 1;

      // aqui percorre os leds pra trocar o estado
      for(int j = 0; j < len && parada == 1; j++) {
        if(configuracao[j] == 'X') {
          configuracao[j] = 'O';
          parada = 0;
        }
        else if (configuracao[j] == 'O') {
          configuracao[j] = 'X';
        }
      }
    }

    printf("%s\n", configuracao);

    // aqui ele armazena o negocio de acordo com a condição exigida ANTES de colar o fio
    if (i > 0) { // se não for o primeiro teste (i > 0), coloca o ornamento
      if (posVetor % 2 == 0) { // Verifica o tamanho do vetorGrande
        if (vetorGrande[posVetor - 1] == configuracao[0]) {
          vetorGrande[posVetor] = '@';
          posVetor++;
        } else {
          vetorGrande[posVetor] = '$';
          posVetor++;
        }
      } else {
        if (vetorGrande[posVetor - 1] == configuracao[0]) {
          vetorGrande[posVetor] = '#'; // Invertido conforme a regra
          posVetor++;
        } else {
          vetorGrande[posVetor] = '%'; // Invertido conforme a regra
          posVetor++;
        }
      }
    }

    // aqui gera o vetor com os negocios la(%, #, ...)
    for(int l = 0; l < len; l++) {
      vetorGrande[posVetor] = configuracao[l];
      posVetor++;
    }
  }
  
  vetorGrande[posVetor] = '\0';

  // aqui printa tudo
  printf("%s\n", vetorGrande);

  return 0;
}
