#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int codigo;
  char nome[100];
  int quantidade;
  float preco;
} Produto;

typedef struct {
  int codigo;
  char tipo;
  int quantidade;
} Movimento;

typedef struct {
  int codigo;
  char tipo;
  int estoque;
  char erro[200];
} Inconsistencia;

void processarArquivos(FILE *produtos, FILE *movimentos) {
  char linha[300];
  int capacidadeProduto = 1;
  int quantidadeProduto = 0;
  int capacidadeMovimentos = 1;
  int quantidadeMovimentos = 0;
  Produto *produtosLista = malloc(capacidadeProduto * sizeof(Produto)); 
  Movimento *movimentosLista = malloc(capacidadeMovimentos * sizeof(Movimento)); 

  while(fgets(linha, 300, produtos) != NULL) {
    if(capacidadeProduto == quantidadeProduto) {
      capacidadeProduto *= 2;
      Produto *temp = realloc(produtosLista, capacidadeProduto * sizeof(Produto));
      if(temp == NULL) {
        printf("Erro na alocação de memoria de produtos");
      }
      produtosLista = temp;
    }

    sscanf(linha, "%d %s %d %f",
      &produtosLista[quantidadeProduto].codigo,
      produtosLista[quantidadeProduto].nome,
      &produtosLista[quantidadeProduto].quantidade,
      &produtosLista[quantidadeProduto].preco); 

    quantidadeProduto++;
  }

  while(fgets(linha, 300, movimentos) != NULL) {
    if(capacidadeMovimentos == quantidadeMovimentos) {
      capacidadeMovimentos *= 2;
      Movimento *temp = realloc(movimentosLista, capacidadeMovimentos * sizeof(Movimento));
      if(temp == NULL) {
        printf("Erro na alocação de memoria de produtos");
      }
      movimentosLista = temp;
    }

    sscanf(linha, "%d %c %d",
      &movimentosLista[quantidadeMovimentos].codigo,
      &movimentosLista[quantidadeMovimentos].tipo,
      &movimentosLista[quantidadeMovimentos].quantidade); 

    quantidadeMovimentos++;
  }

  int movimentosAplicados = 0;
  int saidasRecusadas = 0;
  int codigosInexistentes = 0;
  int encontrado = 0;

  int capacidadeInconsistencia = 1;
  int quantidadeInconsistencia = 0;
  Inconsistencia *inconsistenciaLista = malloc(capacidadeInconsistencia * sizeof(Inconsistencia));

  for(int i = 0; i < quantidadeMovimentos; i++) {
    encontrado = 0;
    for(int j = 0; j < quantidadeProduto; j++) {
      
      if(produtosLista[j].codigo == movimentosLista[i].codigo) {
        encontrado = 1;
        if(movimentosLista[i].tipo == 'E') {
          produtosLista[j].quantidade += movimentosLista[i].quantidade;
          movimentosAplicados++;

        } else if(movimentosLista[i].tipo == 'S') {
          if(movimentosLista[i].quantidade <= produtosLista[j].quantidade) {
            produtosLista[j].quantidade -= movimentosLista[i].quantidade;
            movimentosAplicados++;
          } else {
            if(capacidadeInconsistencia == quantidadeInconsistencia) {
              capacidadeInconsistencia *= 2;
              Inconsistencia *temp = realloc(inconsistenciaLista, capacidadeInconsistencia * sizeof(Inconsistencia));
              if(temp == NULL) {
                printf("Erro na alocação de memoria de incosistencia");
              }
              inconsistenciaLista = temp;
            }

            inconsistenciaLista[quantidadeInconsistencia].codigo = movimentosLista[i].codigo;
            inconsistenciaLista[quantidadeInconsistencia].tipo = movimentosLista[i].tipo;
            inconsistenciaLista[quantidadeInconsistencia].estoque = movimentosLista[i].quantidade;
            strcpy(inconsistenciaLista[quantidadeInconsistencia].erro, "ESTOQUE_INSUFICIENTE");
            
            saidasRecusadas++;
            quantidadeInconsistencia++;
          }
        }
      }
    }
    if(!encontrado) {
      if(capacidadeInconsistencia == quantidadeInconsistencia) {
        capacidadeInconsistencia *= 2;
        Inconsistencia *temp = realloc(inconsistenciaLista, capacidadeInconsistencia * sizeof(Inconsistencia));
        if(temp == NULL) {
          printf("Erro na alocação de memoria de incosistencia");
        }
        inconsistenciaLista = temp;
      }

      inconsistenciaLista[quantidadeInconsistencia].codigo = movimentosLista[i].codigo;
      inconsistenciaLista[quantidadeInconsistencia].tipo = movimentosLista[i].tipo;
      inconsistenciaLista[quantidadeInconsistencia].estoque = movimentosLista[i].quantidade;
      strcpy(inconsistenciaLista[quantidadeInconsistencia].erro, "PRODUTO_INEXISTENTE");
      
      codigosInexistentes++;
      quantidadeInconsistencia++;
    }
  }

  FILE *estoque_atualizado = fopen("estoque_atualizado.txt", "w");
  for(int i = 0; i < quantidadeProduto; i++) {
    fprintf(estoque_atualizado, "%d %s %d %f\n", 
      produtosLista[i].codigo,
      produtosLista[i].nome,
      produtosLista[i].quantidade,
      produtosLista[i].preco);
  }

  FILE *relatorio = fopen("relatorio.txt", "w");
  fprintf(relatorio, "PRODUTOS PROCESSADOS: %d\n", quantidadeProduto);
  fprintf(relatorio, "MOVIMENTOS APLICADOS: %d\n", movimentosAplicados);
  fprintf(relatorio, "SAIDAS RECUSADAS: %d\n", saidasRecusadas);
  fprintf(relatorio, "MOVIMENTOS SEM CADASTRO: %d\n", codigosInexistentes);
  fprintf(relatorio, "ESTOQUE BAIXO:\n");
  for(int i = 0; i < quantidadeProduto; i++) {
    if(produtosLista[i].quantidade <= 5) {
      fprintf(relatorio, "%d %s %d\n", produtosLista[i].codigo, produtosLista[i].nome, produtosLista[i].quantidade);
    }
  }
  fprintf(relatorio, "INCONSISTENCIAS:\n");
  for(int i = 0; i < quantidadeInconsistencia; i++) {
    fprintf(relatorio, "%d %c %d %s\n", inconsistenciaLista[i].codigo, inconsistenciaLista[i].tipo, inconsistenciaLista[i].estoque, inconsistenciaLista[i].erro);
  }

  fclose(estoque_atualizado);
  fclose(relatorio);
  free(produtosLista);
  free(movimentosLista);
  free(inconsistenciaLista);
}

int main() {
  FILE *produtos = fopen("produtos.txt", "r");
  FILE *movimentos = fopen("movimentos.txt", "r");

  if(produtos && movimentos) {
    processarArquivos(produtos, movimentos);
  } else {
    printf("Erro ao abrir os arquivos");
  }
  
  if(produtos) {
    fclose(produtos);
  }
  if(movimentos) {
    fclose(movimentos);
  }

  return 0;
}
