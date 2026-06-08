#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int valor;
  struct no *left;
  struct no *right;
} No;

// aqui eu coloco um novo nó na arvore
No* inserir(No *raiz, int valor) {
  if(raiz == NULL) {
    // crio o novo espaço se for a primeira info, logo a raiz
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
    // se ja existe raiz, ela vai ter que verificar se o valor é menor ou maior
  } else {
    // se menor, vai chamar a propria função pra percorrer todo o lado esquerda e fixar a posição
    if(raiz->valor > valor) {
      raiz->left = inserir(raiz->left, valor);
    } else if(raiz->valor < valor) {
      // se maior, vai fazer a mesma coisa que o esquerdo, mas com o lado direitp
      raiz->right = inserir(raiz->right, valor);
    }
  }

  return raiz;
}

// função de printar em ordem(esquerda - nó - direita)
void emOrdem(No *raiz) {
  if(raiz != NULL) {
    emOrdem(raiz->left);
    printf("%d ", raiz->valor);
    emOrdem(raiz->right);
  }
}

// função de printar em pre ordem(nó - esquerda - direita)
void preOrdem(No *raiz) {
  if(raiz != NULL) {
    printf("%d ", raiz->valor);
    preOrdem(raiz->left);
    preOrdem(raiz->right);
  }
}

// função de printar em pos ordem(esquerda - direita - nó)
void posOrdem(No *raiz) {
  if(raiz != NULL) {
    posOrdem(raiz->left);
    posOrdem(raiz->right);
    printf("%d ", raiz->valor);
  }
}

// procurando o menor valor
int menorValor(No *raiz) {
  while(raiz->left != NULL) {
    raiz = raiz->left;
  }

  return raiz->valor;
}

// procurando o maior valor
int maior(No *raiz) {
  while(raiz->right != NULL) {
    raiz = raiz->right;
  }

  return raiz->valor;
}

// função de descobrir a altura
int altura(No *raiz) {
  if (raiz != NULL) {
    // ela vai percorrer durante toda a esquerda e direita e a cada nó ele vai dizer seu andar
    int altEsquerda = altura(raiz->left);
    int altDireita = altura(raiz->right);

    // se uma das duas for maior, esse vai ser a altura + 1(raiz)
    if (altEsquerda > altDireita) {
        return altEsquerda + 1;
    } else {
        return altDireita + 1;
    }
  }
  // se nãoachou nada é pq a arvore esta vazia
  return -1;
}

int contarNos(No *raiz) {
  if(raiz != NULL) {
    // aqui vai percorrer todos os dois lados e vai adicionando toda vvez que achar um cara novo + 1(raiz)
    int nosEsquerda = contarNos(raiz->left);
    int nosDireita = contarNos(raiz->right);
    return nosDireita + nosEsquerda + 1;
  } 
  return 0;
}

// a folha é oq não tem filho, logo seu lado direiro e esquerdo são NULL
int contarFolhas(No *raiz) {
  // verificando se a arvore existe
  if(raiz == NULL) {
    return 0;
  }

  if(raiz->left == NULL && raiz->right == NULL) {
    return 1;
  }
  
  // ela tem que percorrer o final de cada lado e retornar 1 pra incrementar
  return contarFolhas(raiz->left) + contarFolhas(raiz->right);
}

int main() {
  int numero;
  No *raiz = NULL;

  while(scanf("%d", &numero) != EOF && numero != -1) {
    raiz = inserir(raiz, numero);
  }

  if(raiz == NULL) {
    printf("ARVORE VAZIA\n");
  } else {
    printf("PREORDEM: ");
    preOrdem(raiz);
    printf("\n");
  
    printf("EMORDEM: ");
    emOrdem(raiz);
    printf("\n");
  
    printf("POSORDEM: ");
    posOrdem(raiz);
    printf("\n");
  
    printf("NOS: ");
    int nos = contarNos(raiz);
    printf("%d\n", nos);
  
    printf("FOLHAS: ");
    int folhas = contarFolhas(raiz);
    printf("%d\n", folhas);
  
    printf("ALTURA: ");
    int alturaCont = altura(raiz);
    printf("%d\n", alturaCont);

    printf("MENOR: ");
    int menorCont = menorValor(raiz);
    printf("%d\n", menorCont);
  
    printf("MAIOR: ");
    int maiorCont = maior(raiz);
    printf("%d\n", maiorCont);
  }

  return 0;
}
