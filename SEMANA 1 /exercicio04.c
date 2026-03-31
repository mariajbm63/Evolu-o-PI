#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Aqui eu incializo todas as variaveis que irei receber pelo input
  int x;
  int y;
  int c;
  scanf("%d %d %d", &x, &y, &c);

  /*-------------------- VERIFICAÇÃO DO PRIMEIRO QUADRANTE -----------------*/
  if (x > 0 && y > 0) {
    /* depois de verificar qual o quadrante, eu verifico se ele não 
    se choca com a restrição de quadrante que não posso pisar */
    if (c == 1) {
      printf("caminhada invalida"); // caso ele se choque com a restrição
    }
    else {
      /* caso ele não se choque, eu faço a distancia do ponto incial 
      ate o seu objetivo no caminho da diagonal*/
      int x1 = abs(x) + 1;
      int y1 = abs(y) + 1;
      printf("%d passos em y e %d passos em x", y1, x1);
    }
  }

  /*-------------------- VERIFICAÇÃO DO SEGUNDO QUADRANTE -----------------*/
  if (x > 0 && y < 0) {
    /* depois de verificar qual o quadrante, eu verifico se ele não 
    se choca com a restrição de quadrante que não posso pisar */
    if (c == 2) {
      printf("caminhada invalida"); // caso ele se choque com a restrição
    }
    else {
      /* caso ele não se choque, eu faço a distancia do ponto incial 
      ate o seu objetivo no caminho da diagonal */
      int x1 = abs(x) + 1;
      int y1 = abs(y) + 1;
      printf("%d passos em y e %d passos em x", y1, x1);
    }
  }

  /*-------------------- VERIFICAÇÃO DO TERCEIRO QUADRANTE -----------------*/
  if (x < 0 && y < 0) {
    /* depois de verificar qual o quadrante, eu verifico se ele não 
    se choca com a restrição de quadrante que não posso pisar */
    if (c == 3) {
      printf("caminhada invalida"); // caso ele se choque com a restrição
    }
    else {
      /* caso ele não se choque, eu faço a distancia do ponto incial 
      ate o seu objetivo no caminho da diagonal */
      int x1 = abs(x) + 1;
      int y1 = abs(y) + 1;
      printf("%d passos em y e %d passos em x", y1, x1);
    }
  }

  /*-------------------- VERIFICAÇÃO DO QUARTO QUADRANTE -----------------*/
  if (x < 0 && y > 0) {
    /* depois de verificar qual o quadrante, eu verifico se ele não 
    se choca com a restrição de quadrante que não posso pisar */
    if (c == 4) {
      printf("caminhada invalida"); // caso ele se choque com a restrição
    }
    else {
      /* caso ele não se choque, eu faço a distancia do ponto incial 
      ate o seu objetivo no caminho da diagonal */
      int x1 = abs(x) + 1;
      int y1 = abs(y) + 1;
      printf("%d passos em y e %d passos em x", y1, x1);
    }
  }

  return 0;
}
