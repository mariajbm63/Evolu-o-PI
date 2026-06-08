#include <stdio.h>
#include <stdlib.h>

typedef struct tarefa {
  int id;
  int pri;
  struct tarefa *proximo;
} Tarefas;

typedef struct {
  Tarefas *head;
  Tarefas *tail;
} Fila;

// função de inserir na fila
void inserir(int id, int pri, Fila *fila) {
  // crio a coisa que ira ser adicionada e guarado todas as infos que recebp
  Tarefas *novaTarefa = malloc(sizeof(Tarefas));

  novaTarefa->id = id;
  novaTarefa->pri = pri;
  novaTarefa->proximo = NULL;

  // se ela for a primeira, o inicio e o fim vão ser ela mesma
  if(fila->head == NULL) {
    fila->head = novaTarefa;
    fila->tail = novaTarefa;
  } else {
    // caso não for a primeira, fim do ultimo aponta para a nova tarefa e ela mesma se torna o fim
    fila->tail->proximo = novaTarefa;
    fila->tail = fila->tail->proximo;
  }
}

// função de remover
void remover(Fila *fila) {
  Tarefas *aux = NULL;
  
  // vejo se existe fila
  if(fila->head != NULL) {
    // se existir eu faço o inico apontar para a proxima tarefa da fila
    aux = fila->head;
    fila->head = fila->head->proximo;
    
    // se acabou, tudo é NULL
    if(fila->head == NULL) {
      fila->tail = NULL;
    }

    printf("Removida: id=%d prioridade=%d\n", aux->id, aux->pri);

    free(aux);
  } else {
    printf("Fila vazia\n");
  }
}

// função que percorre a lista e imprime
void listar(Fila *fila) {
  Tarefas *aux = NULL;

  if(fila->head != NULL) {
    aux = fila->head;
    while(aux != NULL) {
      printf("id=%d prioridade=%d\n", aux->id, aux->pri);
      aux = aux->proximo;
    }
  } else {
    printf("Fila vazia\n");
  }
}

int main() {
  Fila *fila = malloc(sizeof(Fila));
  fila->head = NULL;
  fila->tail = NULL;

  char comando;
  int fim = 0;

  while(scanf(" %c", &comando) != EOF && fim == 0) {
    if(comando == 'I') {
      int id, pri;
      scanf("%d %d", &id, &pri);

      inserir(id, pri, fila);
    } else if(comando == 'L') {
      listar(fila);
    } else if(comando == 'R') {
      remover(fila);
    } else if(comando == 'F') {
      fim = 1;
    }
  }

  free(fila);
  return 0;
}
