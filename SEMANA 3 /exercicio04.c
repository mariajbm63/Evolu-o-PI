#include <stdio.h>
#include <string.h>

int main() {
  char lista[105];
  scanf(" %100[^\n]", lista);
  int len = strlen(lista);
  int inicios[105];
  int fins[105];
  int qtePalavras = 0;
  
  for(int i = 0; i < len; i++) {
    if((lista[i] == 32) || (lista[i] >= 33 && lista[i] <= 47) || (lista[i] >= 58 && lista[i] <= 64) || (lista[i] >= 91 && lista[i] <= 96) || (lista[i] >= 123 && lista[i] <= 126)) {
      lista[i] = ' ';
    }
    else if (lista[i] >= 65 && lista[i] <= 90) {
      char substituir = lista[i] + 32;
      lista[i] = substituir;
    }
  }

  for(int j = 0; j < len; j++) {
    if(lista[j] >= 97 && lista[j] <= 122) {
      if(j == 0 || lista[j - 1] == ' ') {
        inicios[qtePalavras] = j;
      }
      if(j == len - 1 || lista[j + 1] == ' ') {
        fins[qtePalavras] = j;
        qtePalavras++;
      }
    }
  }
  return 0;
}
