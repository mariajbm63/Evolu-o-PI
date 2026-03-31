#include <stdio.h>

int main() {
  // aqui tem as variaveis de controle e as que vão receber os valores de input
  int clientesAtendidos, multiplo, comMaisDe1;
  int horas, minutos, latasCompradas;
  int latasTotal = 0;
  int ganhador = -1;
  int minutosTotais = 0;
  int latasGanhador = 0;
  
  scanf("%d", &clientesAtendidos);
  scanf("%d", &multiplo);
  scanf("%d", &comMaisDe1);
  
  // aqui é a lista de clientes que todos recebem 0 latas compradas
  int lista[clientesAtendidos];
  for(int j = 0; j < clientesAtendidos; j++) {
    lista[j] = 0;
  }

  // aqui é pra ver se tem uma ou mais pessoas que compraram mais de uma lata, então pega quem foi a pessoa na fila
  if (comMaisDe1 > 0) {
    for(int k = 0; k < comMaisDe1; k++) {
      scanf("%d:%d %d", &horas, &minutos, &latasCompradas);

      int minutosTotais1 = (horas - 7) * 60 + minutos;
      int index = (minutosTotais1 / 3) - 1;
      
      lista[index] = latasCompradas;
    }
  }

  // aqui roda por todos os clientes atendidos
  for(int i = 0; i < clientesAtendidos; i++) {
    int cliente = i + 1;
    int latasDesteCliente = 0;

    // verifica se não é o primeiro da lista e armazena o valor da lata
    if (lista[i] > 0) {
      latasDesteCliente = lista[i];
    } else if (multiplo != 0 && cliente % multiplo == 0) {
      latasDesteCliente = 1;
    }

    // somatorio de lata a cada cliente
    latasTotal += latasDesteCliente;

    // verifica se o cliente atuaç ganhou e para o loop
    if (latasTotal >= 50 && ganhador == -1) {
      ganhador = cliente;
      latasGanhador = latasDesteCliente;
      minutosTotais = cliente * 3;
    }
  }

  int horasTotais = 7 + (minutosTotais / 60);
  int minutosRestantes = minutosTotais % 60;

  // prints finais
  if (ganhador == -1) {
    int faltas = 50 - latasTotal;
    if (faltas == 1) {
      printf("Ainda nao foram vendidas latas suficientes. Falta %d lata.\n", faltas);
    } else {
      printf("Ainda nao foram vendidas latas suficientes. Faltam %d latas.\n", faltas);
    }
  } else {
    if (latasGanhador == 1) {
      printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou 1 lata.\n", ganhador, horasTotais, minutosRestantes);
    } else {
      printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou %d latas.\n", ganhador, horasTotais, minutosRestantes, latasGanhador);
    }
  }

  return 0;
}
