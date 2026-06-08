#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  long long mat;
  int pri;
  float cr;
  int L;
  int R;
  int score;
  char situacao[10];
} Alunos;

typedef struct no {
  Alunos aluno;
  struct no *proximo;
} No;

typedef struct {
  No *inicio;
  No *fim;
} Fila;

// função que calcula o score
int calculoScore(Alunos aluno) {
  return (round(aluno.cr * 100))/aluno.pri;
}

// dunção de adiciona na fila
void enqueue(Fila *fila, Alunos aluno) {
  No *novo = malloc(sizeof(No));

  // verifico se criou o espaço do novo aluno
  if(novo != NULL) {
    novo->aluno = aluno;
    novo->proximo = NULL;

    // se for o primeiro da fila, o inicio e o fim vão ser ele
    if(fila->inicio == NULL) {
      fila->inicio = novo;
      fila->fim = novo;
      // caso não for o primeiro da fila, o fim do ultimo vai apontar pra ele e ele é o proprio fim
    } else {
      fila->fim->proximo = novo;
      fila->fim = novo;
    }
  } else {
    printf("Erro na alocacao de memoria de inserir fila\n");
  }
}

// função de remover
Alunos dequeue(Fila *fila) {
  No *aux = fila->inicio;
  Alunos alunoRemov = {0};
  
  // se criou o espaço de aux o fila inicio se torna o proximo da fila
  if(aux != NULL) {
    alunoRemov = aux->aluno;
    fila->inicio = fila->inicio->proximo;
    // caso a fila tenha acabado =, o fim tambem é nulo
    if(fila->inicio == NULL) {
      fila->fim = NULL;
    }
    free(aux);
  }

  return alunoRemov;
}

int main() {
  char comando[10];
  char disciplina[51];
  int vagas;
  int fim = 0;
  int temp = 1;
  Fila *filaRequisicoes = malloc(sizeof(Fila));
  filaRequisicoes->inicio = NULL;
  filaRequisicoes->fim = NULL;

  Fila *filaConfirmados = malloc(sizeof(Fila));
  filaConfirmados->inicio = NULL;
  filaConfirmados->fim = NULL;

  // aqui recebe o comando ate a parada de fim ou terminar o arquivo
  while(scanf("%s", comando) != EOF && fim == 0) {
    if(strcmp(comando, "START") == 0) {
      scanf("%s %d", disciplina, &vagas);  
    } else if(strcmp(comando, "ADD") == 0) {
      Alunos alunoNovo;
      scanf("%lld %d %f %d %d", 
        &alunoNovo.mat, 
        &alunoNovo.pri, 
        &alunoNovo.cr, 
        &alunoNovo.L, 
        &alunoNovo.R);

        int scoreNovo = calculoScore(alunoNovo);
        alunoNovo.score = scoreNovo;

        enqueue(filaRequisicoes, alunoNovo);
    } else if(strcmp(comando, "PROC") == 0) {
      int qtde;
      int flag = 0;
      int i = 0;
      scanf("%d", &qtde);

      while(qtde > i && flag == 0) {
        if(filaRequisicoes->inicio == NULL) {
          flag = 1;
        } else {
          Alunos alunoRemov = dequeue(filaRequisicoes);

          if(temp < alunoRemov.L) {
            temp = alunoRemov.L;
          } 
          
          if(temp > alunoRemov.R) {
            printf("[TIMEOUT] mat=%lld | Desconectado da fila.\n", alunoRemov.mat);
          } else {
            if(vagas > 0) {
              printf("[ALOCADO] mat=%lld | score=%d | Processado no seg: %d\n", alunoRemov.mat, alunoRemov.score, temp);
              vagas--;
              temp++;

              enqueue(filaConfirmados, alunoRemov);
            } else {
              printf("[LOTADO] mat=%lld | score=%d | Processado no seg: %d\n", alunoRemov.mat, alunoRemov.score, temp);
              temp++;
            }
          }
        }
        i++;
      }

    } else if(strcmp(comando, "FIM") == 0) {
      fim = 1;
      int i = 1;

      printf("--- LISTA OFICIAL: %s ---\n", disciplina);
      while(filaConfirmados->inicio != NULL) {
        Alunos aprovado = dequeue(filaConfirmados);

        printf("%d. Matricula: %lld\n", i, aprovado.mat);
        i++;
      }
    }
  }
  
  free(filaConfirmados);
  free(filaRequisicoes);

  return 0;
}
