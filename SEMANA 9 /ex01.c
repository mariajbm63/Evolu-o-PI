#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
  char cor;
  struct no *proximo;
} No;

typedef struct {
  No *topo;
} Pilha;

// função que adiciona nova info na pilha
void empilha(Pilha *pilha, char cor) {
  // cria o espaço do novo topo
  No *novo = malloc(sizeof(No));
  
  if(novo != NULL) {
    // recebe tudo e depois joga no topo
    novo->cor = cor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
  } else {
    printf("Erro ao alocar memoria em empilha\n");
  }
}

// função de imprimit. Se a pilha não estiver vazia, 
// vai percorrer a pilha ate o ultimo elemento e printar as cores
void imprimir(Pilha *pilha) {
  No *cores = pilha->topo;
  if(pilha->topo == NULL) {
    printf("Pilha vazia!\n");
    printf("\n");
  } else {
    while(cores != NULL) {
      printf("%c\n", cores->cor);
      cores = cores->proximo;
    }
    printf("\n");
  }
}

// função de fundir, primeiro verifico se existe dois elementos na pilha
int fundir(Pilha *pilha) {
  No *primeiro = pilha->topo;
  
  if(primeiro == NULL) {
    return 0;
  }
  
  No *segundo = pilha->topo->proximo;
  if(segundo == NULL) {
    return 0;
  }
  
  // depois eu vejo as combinações de cores
  if((primeiro->cor == 'g' && segundo->cor == 'b') || (primeiro->cor == 'b' && segundo->cor == 'g')) {
    // dentro do bloco de cada combinação existe essa estrutura que:
    // pega o primeiro e aponta para o proximo
    No *temp1 = pilha->topo;
    pilha->topo = pilha->topo->proximo;
  
    No *temp2 = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    // se livra dos dois
    free(temp1);
    free(temp2);

    // e empilha a nova cor da combinação que foi tirada anteriormente
    empilha(pilha, 'c');
    return 1;

  } else if((primeiro->cor == 'r' && segundo->cor == 'b') || (primeiro->cor == 'b' && segundo->cor == 'r')) {
    No *temp1 = pilha->topo;
    pilha->topo = pilha->topo->proximo;
  
    No *temp2 = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    free(temp1);
    free(temp2);

    empilha(pilha, 'm');
    return 1;
    
  } else if((primeiro->cor == 'r' && segundo->cor == 'g') || (primeiro->cor == 'g' && segundo->cor == 'r')) {
    No *temp1 = pilha->topo;
    pilha->topo = pilha->topo->proximo;
  
    No *temp2 = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    free(temp1);
    free(temp2);

    empilha(pilha, 'y');
    return 1;
  }

  return 0;
}

// função de eliminar os 3 blocos
// primeiro eu vejo se existe 3 elementos na pilha
int eliminar(Pilha *pilha) {
  No *primeiro = pilha->topo;

  if(primeiro != NULL) {
    No *segundo = primeiro->proximo;

    if(segundo != NULL) {
      No *terceiro = segundo->proximo;

      if(terceiro != NULL) {
        // se exister eu vejo se eles são da mesma cor 
        //e faço o negocio de pegar o primeiro, apontar para o proximo e se livar dele 3 vezes
        if((primeiro->cor == segundo->cor) && (primeiro->cor == terceiro->cor)) {
          for(int i = 0; i < 3; i++) {
            No *temp1 = pilha->topo;
            pilha->topo = pilha->topo->proximo;
            free(temp1);
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

int main() {
  char caracter;
  Pilha *pilha = malloc(sizeof(Pilha));
  pilha->topo = NULL;
  
  // eu recebo as entradas ate o final do arquivo
  while(scanf(" %c", &caracter) != EOF) {
    empilha(pilha, caracter);

    int flag1 = 1;
    int flag2 = 1;

    // enquanto uma das funções fizer algo, vai ter que repeti-las
    while(flag1 || flag2) {
      flag1 = fundir(pilha);
      flag2 = eliminar(pilha);
    }
    imprimir(pilha);
  }

  printf("Thank You So Much For Playing My Game!");

  return 0;
}
