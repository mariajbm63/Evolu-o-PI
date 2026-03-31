#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // aqui inicializa umas variaveis de controle que vão ser atualizadas e mudadas constantemente no loop
    int numeroXupenio, qtdCanais; // Troquei N e X por nomes claros para não confundir na leitura
    int menorD = -1;
    int melhorCanal = -1;
    int melhorMinuto = -1;
    int termoEscolhido = -1;
    int canalAtual;

    // Conforme o enunciado: 1º o número do Xupenio, 2º a quantidade de canais
    scanf("%d", &numeroXupenio);
    scanf("%d", &qtdCanais);

    // esse for passa por cada canal disponivel
    for (canalAtual = 1; canalAtual <= qtdCanais; canalAtual++) {
        // outras variaveis de controle, mas essa é pra cada canal que estamos verificando
        int num1, num2;
        int menorDistancia = -1;
        int melhorTermo = -1;
        int melhorMinutoCanal = -1;
        int minuto = 1;
        int termoAtual = 0;
        int ultimoTermo = 0;
        int penultimoTermo = 0;
        int continuar = 1; // aqui usei para controlar em que momento eu pararia meu while

        scanf("%d %d", &num1, &num2);

        // aqui vejo qual é o canal atual e vou organizando as infos do f(i)
        while (continuar) {
            int distancia;
            int atualizarCanal = 0;

            // aqui é a logica do f(i) e nanan
            if (minuto == 1) {
                termoAtual = num1;
                penultimoTermo = num1;
            } else if (minuto == 2) {
                termoAtual = num2;
                ultimoTermo = num2;
            } else {
                termoAtual = ultimoTermo + penultimoTermo;
                penultimoTermo = ultimoTermo;
                ultimoTermo = termoAtual;
            }

            distancia = abs(termoAtual - numeroXupenio);

            // aqui meio que atualiza o melhor canal local
            if (menorDistancia == -1) {
                atualizarCanal = 1;
            } else {
                if (distancia < menorDistancia) {
                    atualizarCanal = 1;
                } else if (distancia == menorDistancia) {
                    // em caso de empate na distância no mesmo canal pega o menor termo
                    if (termoAtual < melhorTermo) {
                        atualizarCanal = 1;
                    }
                }
            }

            if (atualizarCanal) {
                menorDistancia = distancia;
                melhorTermo = termoAtual;
                melhorMinutoCanal = minuto;
            }

            // aqui é a condição de parada pq se calcular um numero maior que o do personagem ele precisa parar
            if (minuto >= 2 && termoAtual > numeroXupenio && termoAtual >= ultimoTermo) {
                continuar = 0;
            }

            if (minuto > 60) {
                continuar = 0;
            }
            if (continuar) {
                minuto = minuto + 1;
            }
        }

        // aqui compara os melhores valores so que com todos oa canais, então seria a parte global
        int atualizarTudo = 0;
        if (menorD == -1) {
            atualizarTudo = 1;
        } else {
            if (menorDistancia < menorD) {
                atualizarTudo = 1;
            } else if (menorDistancia == menorD) {
                // em caso de empate na distância entre canais pega o de maior indice
                atualizarTudo = 1;
            }
        }

        if (atualizarTudo) {
            menorD = menorDistancia;
            melhorCanal = canalAtual;
            melhorMinuto = melhorMinutoCanal;
            termoEscolhido = melhorTermo;
        }
    }

    // logica do VIP que soma tudo
    int soma = 0;
    int copia = termoEscolhido;
    
    if (copia < 0) {
        copia = -copia;
    }

    while (copia > 0) {
        soma = soma + (copia % 10);
        copia = copia / 10;
    }

    if (soma > 10) {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", melhorCanal, melhorMinuto);
    } else {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP não vai rolar :(\n", melhorCanal, melhorMinuto);
    }

    return 0;
}
