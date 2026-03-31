#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  /* Aqui eu inicializo as variaveis que vou receber dos 
  inputs e o valor inicial que rebeka tem de saldo */
  int total;
  int x, y, z;
  int rebeka = 3;

  scanf("%d", &total);
  scanf("%d", &x);
  scanf("%d", &y);
  scanf("%d", &z);

  /* Aqui eu faço o caculo da sobra percentual do dinheiro que serve
  para verificar se a rebeka sairia com dinheiro a mais caso investisse*/
  int sobra = 100 - (x + y + z);

  /* -------------------------- CONDICÃO 1 ----------------------------*/
  // eu começo verificando se a divisão retorna um inteiro
  if ((x * total) % 100 == 0 && (y * total) % 100 == 0 && (z * total) % 100 == 0) {

    /*0 aqui eu calculo a quantidade que cada homem recebe de acordo com 
    sua porcentagem e o resto - caso tenha - que a rebeka vai receber */
    int premioX = (x * total) / 100; 
    int premioY = (y * total) / 100; 
    int premioZ = (z * total) / 100;
    int resto = total - (premioX + premioY + premioZ);
    rebeka += resto;

    // print da condição 1
    printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", premioX, premioY, premioZ);
  }

  /* -------------------------- CONDICÃO 2 ----------------------------*/
  /* se a condição 1 não rolar, eu verifico se a rebeka pode investir o 
  dinheiro e realizo a divisão para ver se retorna um inteiro */
  else if ((x * (total + 1)) % 100 == 0 && (y * (total + 1)) % 100 == 0 && (z * (total + 1)) % 100 == 0 && (sobra * (total + 1) / 100 > 1)) {
    /*0 aqui eu calculo a quantidade que cada homem recebe de acordo com 
    sua porcentagem e o resto - caso tenha - que a rebeka vai receber */
    // aqui soma mais 1 no total porque a rebeka investiu
    total = total + 1;
    int premioX = (x * total) / 100; 
    int premioY = (y * total) / 100; 
    int premioZ = (z * total) / 100;
    int resto = total - (premioX + premioY + premioZ);

    // aqui decrementa porque a rebeka investiu 1
    rebeka--;
    rebeka += resto;
  }

  /* -------------------------- CONDICÃO 3 ----------------------------*/
  /* se a condição 1 e 2 não rolar, eu verifico se a rebeka pode investir 
  mais dinheiro e realizo a divisão para ver se retorna um inteiro */
  else if ((x * (total + 2)) % 100 == 0 && (y * (total + 2)) % 100 == 0 && (z * (total + 2)) % 100 == 0 && (sobra * (total + 2) / 100 > 2)) {
    // se ela investir 2 reais tem a verificação dos char, então os recebos a partir dos inputs
    char x1, y1, z1;
    scanf(" %c", &x1);
    scanf(" %c", &y1);
    scanf(" %c", &z1);
    
    // aqui é a soma das verificações dos char
    int somaLetras = (x1 - 96) + (y1 - 96) + (z1 - 96);
    printf("%d\n", somaLetras);

    /*0 aqui eu calculo a quantidade que cada homem recebe de acordo com 
    sua porcentagem e o resto - caso tenha - que a rebeka vai receber */
    // aqui soma mais 2 no total porque a rebeka investiu
    total = total + 2;
    int premioX = (x * total) / 100; 
    int premioY = (y * total) / 100; 
    int premioZ = (z * total) / 100;
    int resto = total - (premioX + premioY + premioZ);

    // aqui decrementa porque a rebeka investiu 2
    rebeka -= 2;
    rebeka += resto;
  }

  /* -------------------------- CONDICÃO 4 ----------------------------*/
  /* se a condição 1, 2 e 3 não rolar, eu verifico se a rebeka pode investir 
  mais dinheiro e realizo a divisão para ver se retorna um inteiro */
  else if ((x * (total + 3)) % 100 == 0 && (y * (total + 3)) % 100 == 0 && (z * (total + 3)) % 100 == 0 && (sobra * (total + 3) / 100 > 3)) {
    // se ela investir 3 reais tem a verificação das idades, então os recebos a partir dos inputs
    int x2, y2, z2;
    int somaIdade;
    scanf("%d", &x2);
    scanf("%d", &y2);
    scanf("%d", &z2);

    // awui é a outra verificação das idades, em que pelo menos 1 precisa ser divisor de 3
    if (x2 % 3 == 0 || y2 % 3 == 0 || z2 % 3 == 0) {
      // depois tem que somar as parcelas da quantidade de vezes que a idade foi dividida por 3
      int somaIdade = (x2 / 3) + (y2 / 3) + (z2 / 3);
      printf("%d\n", somaIdade);
    }

    /*0 aqui eu calculo a quantidade que cada homem recebe de acordo com 
    sua porcentagem e o resto - caso tenha - que a rebeka vai receber */
    // aqui soma mais 3 no total porque a rebeka investiu
    total = total + 3;
    int premioX = (x * total) / 100; 
    int premioY = (y * total) / 100; 
    int premioZ = (z * total) / 100;
    int resto = total - (premioX + premioY + premioZ);
    // aqui decrementa porque a rebeka investiu 4
    rebeka -= 3;
    rebeka += resto;
  }

  // caso não dê para a rebeka investir dinheiro
  else {
    printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
  }

  // por fim, a rebeka consegue voltar pra casa se ele conseguiu 7 reais, isso gera esse respectivo print
  if (rebeka >= 7) {
    printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
  }
  // caso a rebeka não consiga pelo menos 7 reais para volytar pra casa
  else {
    printf("E parece que Rebeka vai ter que voltar andando...\n");
  }

  return 0;
}
