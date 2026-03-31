#include <stdio.h>

int main() {
  // aqui incializa as variabeis e tem variaveis de controle
  int N, K, P;
  int Q = 0;
  int primeiroNum = -1;
  scanf("%d %d %d", &N, &K, &P);

  // esse for percorre o intervalo que foi colocado  na questão, de começar em N e terminar em nueros menores que K
  for(int i = N; i < K; i++) {
    int numWhile = i;
    int primosImpares = 0;
    int invalido = 0;

    // aqui eu vejo ate quando ele é divisivel por 2
    while(numWhile > 0 && numWhile % 2 == 0) {
      numWhile = numWhile / 2;
    }
    
    // esse for serve pra percorrer todos os multiplos impares da 'fatoração' do termo la
    for(int j = 3; j <= numWhile; j = j + 2) {
      int contarRepeticao = 0;

      // esse while vai dividindo pelo impar e se ele for divido por mais de uma vez, contabiliza
      while(numWhile % j == 0) {
        contarRepeticao += 1;
        numWhile = numWhile / j;
      }
      
      // aqui vejo se ele tem primos impares distintos entre si para fazer a contagem
      if(contarRepeticao == 1) {
        primosImpares++;
      }
      if(contarRepeticao > 1) {
        invalido = 1;
      }
    }

    // aqui eu finalizo tudo pra me retornar o primeiro numero maior que N e menor que K e o numero depois que seria Q
    if(invalido == 0 && primosImpares == P) {
      if(primeiroNum == -1) {
        primeiroNum = i;
      }
      else {
        Q++;
      }
    }
  }

  if(primeiroNum != -1) { 
    printf("%d %d\n", primeiroNum, Q);
  }
  else {
    printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
  }

  return 0;
}
