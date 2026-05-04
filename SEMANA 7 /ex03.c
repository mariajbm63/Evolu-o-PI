#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct mecha mecha;

typedef struct {
  char nome[30];
  int atrib1;
  int atrib2;
  
  void (*subrotina)(mecha *m, int slot, int input, int *output);
} subSistema;

struct mecha {
  int id;
  char modelo[50];
  int energiaAtual;
  int numSistemas;
  int valorWintermute;
  subSistema sistemas[];
};

void defesa(mecha *m, int slot, int input, int *output) {
  int danoFinal = 0;
  danoFinal = input - (*m).sistemas[slot].atrib1 - (slot * (*m).sistemas[slot].atrib2);
  if(danoFinal < 0) {
    danoFinal = 0;
  }
  *output = danoFinal;
}

void utilidade(mecha *m, int slot, int input, int *output) {
  int recuperado = 0;
  recuperado = (*m).sistemas[slot].atrib1 + (slot * (*m).sistemas[slot].atrib2);
  (*m).energiaAtual += recuperado;
  *output = recuperado;
}

void ataque(mecha *m, int slot, int input, int *output) {
  int energiaAtual = (*m).energiaAtual;
  int atrib2 = (*m).sistemas[slot].atrib2;
  int atrib1 = (*m).sistemas[slot].atrib1;

  if(energiaAtual < atrib2) {
    *output = -1;
  } else {
    int dano = atrib1 + energiaAtual + slot - input;
    (*m).energiaAtual -= atrib2;
    *output = dano;
  }
}

int main() {
  int n;
  scanf("%d", &n);

  mecha **esquadrao = malloc(n * sizeof(mecha*));

  for(int i = 0; i < n; i++) {
    int id, energia, qtde, wintermute;
    char modelo[50];

    scanf("%d %s %d %d", &id, modelo, &energia, &qtde);

    mecha *m = malloc(sizeof(mecha) + qtde * sizeof(subSistema));
    (*m).id = id;
    strcpy((*m).modelo, modelo);
    (*m).energiaAtual = energia;
    (*m).numSistemas = qtde;
    (*m).valorWintermute = wintermute;

    for(int j = 0; j < qtde; j++) {
      char tipo;

      scanf(" %c %s %d %d", &tipo, (*m).sistemas[j].nome, &(*m).sistemas[j].atrib1, &(*m).sistemas[j].atrib2);

      if(tipo == 'D') {
        (*m).sistemas[j].subrotina = defesa;
      }
      else if(tipo == 'U') {
        (*m).sistemas[j].subrotina = utilidade;
      }
      else if(tipo == 'A') {
        (*m).sistemas[j].subrotina = ataque;
      }
    }
    scanf("%d", &wintermute);
    (*m).valorWintermute = wintermute;
    esquadrao[id] = m;
  }

  printf("[RELATORIO DE MISSÃO: OPERAÇÃO LANÇA DE NETUNO]\n");
  for(int i = 0; i < n; i++) {
    mecha *m = esquadrao[i];
    printf("ID: %d | MECHA: %s | ENERGIA: %d\n", (*m).id, (*m).modelo, (*m).energiaAtual);

    for(int j = 0; j < (*m).numSistemas; j++) {
      if((*m).sistemas[j].subrotina == defesa) {
        int output;
        (*m).sistemas[j].subrotina(m, j, (*m).valorWintermute, &output);
        printf("-> [DEFESA] %s | Dano final sofrido: %d\n", (*m).sistemas[j].nome, output);
      }
    }

    for(int j = 0; j < (*m).numSistemas; j++) {
      if((*m).sistemas[j].subrotina == utilidade) {
        int output;
        (*m).sistemas[j].subrotina(m, j, (*m).valorWintermute, &output);
        printf("-> [UTILIDADE] %s | Energia atual: %d\n", (*m).sistemas[j].nome, (*m).energiaAtual);
      }
    }

    for(int j = 0; j < (*m).numSistemas; j++) {
      if((*m).sistemas[j].subrotina == ataque) {
        int output;
        (*m).sistemas[j].subrotina(m, j, (*m).valorWintermute, &output);
        if(output == -1) {
          printf("-> [ATAQUE] %s | Energia insuficiente!\n", (*m).sistemas[j].nome);
        } else {
          printf("-> [ATAQUE] %s | Dano causado: %d | Energia restante: %d\n", (*m).sistemas[j].nome, output, (*m).energiaAtual);
        }
      }
    }
    printf("ENERGIA FINAL: %d\n", (*m).energiaAtual);
    printf("-----------------------------------------\n");
  }

  printf("Esquadrao pronto para o combate.\n");

  for(int i = 0; i < n; i++) {
    free(esquadrao[i]);
  }
  free(esquadrao);

  return 0;
}
