#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// todas as funções de printf vão basicamente percorrer a lista de struct e verificar de acordo com o parametro passado, contar e printar o resultado final

// struct para armazenar as informações dos jogos
struct jogo {
  char titulo[50];
  char genero[50];
  char estudio[50];
  char console[50];
  int nota;
  int ano;
};

// função de ver o ano da função pedida e do parametro solicitado
void printfAno(int N, struct jogo lista[], int ano) {
  int contador = 0;
  for(int i = 0; i < N; i++) {
    if(lista[i].ano == ano) {
      printf("%s\n", lista[i].titulo);
      contador++;
    }
  }

  if(contador > 0) {
    printf("Tenho %d jogos || %d.\n", contador, ano);
  } else {
    printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
  }
}

// função de ver a primeira letra da função pedida e do parametro solicitado
void printfLetra(int N, struct jogo lista[], char letra) {
  int contador = 0;
  for(int i = 0; i < N; i++) {
    if(lista[i].titulo[0] == letra) {
      printf("%s\n", lista[i].titulo);
      contador++;
    }
  }

  if(contador > 0) {
    printf("Tenho %d jogos || %c.\n", contador, letra);
  } else {
    printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
  }
}

// função de ver o estudio da função pedida e do parametro solicitado
void printfStudio(int N, struct jogo lista[], char studio[]) {
  int contador = 0;
  for(int i = 0; i < N; i++) {
    if(strcmp(lista[i].estudio, studio) == 0) {
      printf("%s\n", lista[i].titulo);
      contador++;
    }
  }

  if(contador > 0) {
    printf("Tenho %d jogos || %s.\n", contador, studio);
  } else {
    printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
  }
}

// função de ver o console da função pedida e do parametro solicitado
void printfConsole(int N, struct jogo lista[], char console[]) {
  int contador = 0;
  for(int i = 0; i < N; i++) {
    if(strcmp(lista[i].console, console) == 0) {
      printf("%s\n", lista[i].titulo);
      contador++;
    }
  }

  if(contador > 0) {
    printf("Tenho %d jogos || %s.\n", contador, console);
  } else {
    printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
  }
}

// função de printar o noome e a nota do jogo da função pedida
void printfColecao(int N, struct jogo lista[]) {
  int contador = 0;
  for(int i = 0; i < N; i++) {
    printf("%s %d\n", lista[i].titulo, lista[i].nota);
  }
}

// função de cadastro dos jogos para armazenar na lista de struct cada um
void cadastro(int N, struct jogo lista[]) {
  for(int i = 0; i < N;i++) {
    scanf("%s %s %s %s %d %d", lista[i].titulo, lista[i].genero, lista[i].estudio, lista[i].console, &lista[i].nota, &lista[i].ano);

    if(lista[i].nota > 7) {
      printf("AWESOME! Mais um GOTY pra minha coleção!\n");
    } else if(lista[i].nota < 4) {
      printf("Era melhor jogar mais um jogo de Mahjong.\n");
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);

  struct jogo colecao[110];
  cadastro(N, colecao);

  char funcao[50];
  char parametro[50];

  // while pra percorrer todos os jogos e verificar qual comando foi passado
  while(scanf("%s", funcao) != EOF) {
    if(strcmp(funcao, "printColecao") == 0) {
      printfColecao(N, colecao);
    }
      else {
      scanf("%s", parametro);

      if(strcmp(funcao, "printAno") == 0) {
        int ano = atoi(parametro);
        printfAno(N, colecao, ano);
      }

      else if(strcmp(funcao, "printLetra") == 0) {
        printfLetra(N, colecao, parametro[0]);
      }

      else if(strcmp(funcao, "printStudio") == 0) {
        printfStudio(N, colecao, parametro);
      }

      else if(strcmp(funcao, "printConsole") == 0) {
        printfConsole(N, colecao, parametro);
      }
    }
  }

  printf("Enjoei de jogar, agora vou ver TV.");

  return 0;
}
