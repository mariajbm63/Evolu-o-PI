#include <stdio.h>

typedef struct {
  unsigned int erro : 10;
  unsigned char modo : 3;
  unsigned char leitura : 4;
} Campos;

typedef union {
  unsigned char byteBruto;
  Campos infos;
} naoSei;

int main() {
  naoSei variavel;
  int temp;
  scanf("%d", &temp);
  variavel.byteBruto = (unsigned char)temp;

  printf("Byte bruto: %u | Erro: %u | Modo: %u | Leitura: %u", 
    variavel.byteBruto, 
    variavel.infos.erro, 
    variavel.infos.modo, 
    variavel.infos.leitura);
}
