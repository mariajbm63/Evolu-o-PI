#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
  uint32_t ID : 10;
  uint32_t status : 3;
  uint32_t bateria: 1;
  int32_t temperatura : 12;
  uint32_t controle : 6;
} campos;

typedef union {
  uint32_t byteBruto;
  campos infos;
} uni32;

int main() {
  int capacidade = 1;
  int quantidade = 0;
  char vetor[20];
  uni32 *vetoresUni = malloc(capacidade * sizeof(uni32));

  while(scanf("%s", vetor) == 1 && strtol(vetor, NULL, 16) != 0) {
    if(capacidade == quantidade) {
      capacidade *= 2;
      uni32 *temp = realloc(vetoresUni, capacidade * sizeof(uni32));
        if(temp == NULL) {
          free(vetoresUni);
          return 1;
        }
        vetoresUni = temp;
    }
    uni32 pacote;
    pacote.byteBruto = strtol(vetor, NULL, 16);
    vetoresUni[quantidade] = pacote;

    quantidade++;
  }

  for(int i = 0; i < quantidade; i++) {
    printf("Pacote [%d] - Dado Bruto: 0x%08X\n", i + 1, vetoresUni[i].byteBruto);
    printf("ID do Sensor : %d\n", vetoresUni[i].infos.ID);
    printf("Status : %d\n", vetoresUni[i].infos.status);
    if(vetoresUni[i].infos.bateria == 0) {
      printf("Bateria Baixa: Nao\n");
    } else {
      printf("Bateria Baixa: SIM (ALERTA)\n");
    }
    printf("Temperatura : %d graus\n", vetoresUni[i].infos.temperatura);
    printf("-------------------------------------------------\n");
  }

  free(vetoresUni);
  return 0;
}
