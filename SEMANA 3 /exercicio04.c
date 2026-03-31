#include <stdio.h>
#include <string.h>

int main() {
  // variaveis como sempre
  char lista[105];
  scanf(" %100[^\n]", lista);
  int len = strlen(lista);
  int inicios[105];
  int fins[105];
  int qtePalavras = 0;
  
  // aqui toda as impurezas(tira tudo)
  for(int i = 0; i < len; i++) {
    if((lista[i] == 32) || (lista[i] >= 33 && lista[i] <= 47) || (lista[i] >= 58 && lista[i] <= 64) || (lista[i] >= 91 && lista[i] <= 96) || (lista[i] >= 123 && lista[i] <= 126)) {
      lista[i] = ' ';
    }
  }

  // aqui roda toda a lista
  for(int j = 0; j < len; j++) {
    // aqui ve se é maiuscula ou minuscula
    if((lista[j] >= 97 && lista[j] <= 122) || (lista[j] >= 65 && lista[j] <= 90)) {
      
      // aqui eu pego o indece de cada palavra
      if(j == 0 || lista[j - 1] == ' ') {
        inicios[qtePalavras] = j;
      }
      // e aqui eu pego o final de cada palavra
      if(j == len - 1 || lista[j + 1] == ' ') {
        fins[qtePalavras] = j;
        qtePalavras++;
      }
    }
  }

  // aqui começa a verificação do anagrama
  int totalPares = 0;

  // esse primeiro for roda toda a quantidade de palavras
  for (int a = 0; a < qtePalavras; a++) {
    // esse segundo gera o tamanho das palavras pra compara
    for (int b = a + 1; b < qtePalavras; b++) {
      
      int tamA = fins[a] - inicios[a] + 1;
      int tamB = fins[b] - inicios[b] + 1;

      if (tamA == tamB) {
        
        int contA[26] = {0};
        int contB[26] = {0};

        // contagem das palavras de A
        for (int k = inicios[a]; k <= fins[a]; k++) {
          char letra = lista[k];
          // Se for maiuscula converte pra minuscula para contar
          if (letra >= 65 && letra <= 90) {
            letra = letra + 32;
          }
          contA[letra - 'a']++; 
        }
        
        // contagem das palavras de B
        for (int k = inicios[b]; k <= fins[b]; k++) {
          char letra = lista[k];
          // Se for maiuscula converte pra minuscula para contar
          if (letra >= 65 && letra <= 90) {
            letra = letra + 32;
          }
          contB[letra - 'a']++;
        }

        // compara A e B
        int ehAnagrama = 1; 
        for (int k = 0; k < 26 && ehAnagrama == 1; k++) {
          if (contA[k] != contB[k]) {
            ehAnagrama = 0; 
          }
        }

        // printa com a respota final
        if (ehAnagrama == 1) {
          
          if (totalPares == 0) {
            printf("Pares de anagramas encontrados:\n");
          }

          for (int k = inicios[a]; k <= fins[a]; k++) {
            printf("%c", lista[k]);
          }
          
          printf(" e ");
          
          for (int k = inicios[b]; k <= fins[b]; k++) {
            printf("%c", lista[k]);
          }
          printf("\n");

          totalPares++; 
        }
      }
    }
  }

  if (totalPares > 0) {
    printf("\nTotal de pares: %d\n", totalPares);
  } else {
    printf("Nao existem anagramas na frase.\n");
  }

  return 0;
}
