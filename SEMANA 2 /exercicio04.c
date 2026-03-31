#include <stdio.h>

int main() {
  // aqui, como sempre, tem as variaveis dos inputs e algumas variaveis de controle que são mudadas constantemente nos laços
    int q;
    scanf("%d", &q);

    int colAtual = 0;
    int movimento1 = 1;
    int ultimoB = 0;
    int erro = 0;

    for (int i = 0; i < q; i++) {
        int X;
        char C;
        scanf("%d %c", &X, &C);

        // aqui é a verificação do limite de passos
        if (erro == 0) {
            
          // aqui são os ifs de cada movimento aninhados(D, B e E)
          if (C == 'D') {
              // aqui épra so imprimir pontos sem 0s espaços(que devem ser seguidos na linha por causa das colunas)
              if (movimento1 == 1) {
                    for (int k = 0; k < X; k++) {
                        printf(".");
                    }
                    printf("\n");
                    colAtual = X - 1; 
                    movimento1 = 0;
                    ultimoB = 0;
              } else {
                    // se o movimento D for depois de B precisa imprimir espaços vazios pra acompanhar a coluna atual
                    for (int k = 0; k < colAtual; k++) {
                        printf(" ");
                    }
                    // aqui imprime os pontos que forma a linha que foi pedida
                    for (int k = 0; k < X + 1; k++) {
                        printf(".");
                    }
                    printf("\n");
                    colAtual += X; // serve pra saber em qual coluna estamos de acordo com o movimento atual de D e E
                    ultimoB = 0;
                }
            } 
            
          else if (C == 'E') {
            // aqui verifica o movimento limitado, então se foi pra esquerda de (0, 0) da erro e se não tiver espaço o suficiente pra recuar tambem da erro
              if (movimento1 == 1) {
                    erro = 1; 
                } else if (colAtual - X < 0) {
                    erro = 1;
              } else {
                    // preenche de espaços na linha que ta sendo imprimida para meio que "voltar" nas colunas
                    for (int k = 0; k < colAtual - X; k++) {
                        printf(" ");
                    }
                    // imprime os pontos das linhas
                    for (int k = 0; k < X + 1; k++) {
                        printf(".");
                    }
                    printf("\n");
                    colAtual -= X; // serve pra saber em qual coluna estamos de acordo com o movimento atual de D e E
                    ultimoB = 0;
                }
            } 
            
          else if (C == 'B') {
              if (movimento1 == 1) {
                    // se partir de (0, 0), a linha desce direto sem precisar de espaços
                    for (int j = 0; j < X - 1; j++) {
                        printf(".\n");
                    }
                    colAtual = 0;
                    movimento1 = 0;
                    ultimoB = 1;
              } else {
                    // imprime os espaços para acompanhara coluna atual e desce
                    for (int j = 0; j < X - 1; j++) { 
                        for (int k = 0; k < colAtual; k++) {
                            printf(" ");
                        }
                        printf(".\n");
                    }
                    ultimoB = 1;
                }
            }
        }
    }

    // se algum momento deu erro
    if (erro == 1) {
        printf("Informacao invalida\n");
    } else if (ultimoB == 1) {
        // se o ultimo input for B, imrpime 1 a mais
        for (int k = 0; k < colAtual; k++) {
            printf(" ");
        }
        printf(".\n");
    }

    return 0;
}
