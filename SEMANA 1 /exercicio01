#include <stdio.h>

int main() {
  // aqui eu inicializei as variaveis dos inputs.
  int dia1, mes1, ano1;
  int dia2, mes2, ano2; 

  scanf("%d/%d/%d %d/%d/%d", &dia1, &mes1, &ano1, &dia2, &mes2, &ano2);
  /* --------------------------------------------------------------------- */

  /* PERCENTUAL DE AMOR --------------------------------------------------
  aqui eu começo os calculos de data para descobrir 
  o resto que será o percentual final, atraves de operações basicas */

  int dataAmor = dia1 + dia2 + mes1 + mes2 + ano1 + ano2;
  int dataAlterada = (dataAmor * 7) % 101;

  /* Aqui eu começo os blocos de condicionais para printar suas respectivas frases */
  if (dataAlterada < 20) {
    printf("Amor: %d%% Pessimo dia para se apaixonar.\n", dataAlterada);
  }
  else if (dataAlterada >= 20 && dataAlterada <= 40) {
    printf("Amor: %d%% Melhor manter o coracao <3 longe de perigo.\n", dataAlterada);
  }
  else if (dataAlterada >= 41 && dataAlterada <= 69) {
    printf("Amor: %d%% Se o papo e as ideias baterem, esta liberado pensar em algo.\n", dataAlterada);
  }
  else if (dataAlterada >= 70 && dataAlterada <= 80) {
    printf("Amor: %d%% Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.\n", dataAlterada);
  }
  else {
    printf("Amor: %d%% Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.\n", dataAlterada);
  }

  /* PERCENTUAL DE SORTE --------------------------------------------------
  aqui eu começo os calculos de data para descobrir 
  o resto que será o percentual final, atraves de operações basicas */

  int dataAlterada2 = ((dia1 + dia2 + mes1 + mes2) * 9 + ano2 - ano1) % 101;

  /* Aqui eu começo os blocos de condicionais para printar suas respectivas frases */
  if (dataAlterada2 < 30) {
    printf("Sorte: %d%% Nem jogue moedas pra cima hoje.", dataAlterada2);  
  }
  else if (dataAlterada2 >= 30 && dataAlterada2 <= 50) {
    printf("Sorte: %d%% Melhor nao arriscar.", dataAlterada2);
  }
  else if (dataAlterada2 >= 51 && dataAlterada2 <= 79) {
    printf("Sorte: %d%% Por sua conta em risco.", dataAlterada2);
  }
  else if (dataAlterada2 >= 80 && dataAlterada2 <= 90) {
    printf("Sorte: %d%% Hoje vale a pena arriscar.", dataAlterada2);
  }
  else {
    printf("Sorte: %d%% Nao tenha medo de virar cartas hoje.", dataAlterada2);
  }
  printf(" Sem tigrinho nem jogos de azar, por favor!\n");

  /* PERCENTUAL DE TRABAKHO --------------------------------------------------
  aqui eu começo os calculos de data para descobrir 
  o resto que será o percentual final, atraves de operações basicas */
  int dataAlterada3 = ((ano1 + ano2) - (dia1 + dia2 + mes1 + mes2) * 8) % 101;

  /* Aqui eu começo os blocos de condicionais para printar suas respectivas frases */
  if (dataAlterada3 < 40) {
    printf("Trabalho: %d%% Sem tigrinho nem jogos de azar, por favor!\n", dataAlterada3);
  }
  else if (dataAlterada3 >= 40 && dataAlterada3 <= 50) {
    printf("Trabalho: %d%% Segura a emocao, nao xinga ninguem, nao esquece de beber agua.\n", dataAlterada3);
  }
  else if (dataAlterada3 >= 51 && dataAlterada3 <= 69) {
    printf("Trabalho: %d%% Um dia proveitoso com certeza, leve sua simpatia consigo.\n", dataAlterada3);
  }
  else if (dataAlterada3 >= 70 && dataAlterada3 <= 84) {
    printf("Trabalho: %d%% Boas vibracoes hoje, chances podem estar ao seu redor.\n", dataAlterada3);
  }
  else {
    printf("Trabalho: %d%% Use do maximo de networking possível hoje, dia bom para negocios.\n", dataAlterada3);
  }

  /* PERCENTUAL DE COR --------------------------------------------------
  aqui eu começo os calculos de data para descobrir 
  o resto que será o percentual final, atraves de operações basicas */
  int diaQuadrado = dia1 * dia1 + dia2 * dia2;
  int mesQuadrado = mes1 * mes1 + mes2 * mes2;
  int anoQuadrado = ano1 * ano1 + ano2 * ano2;
  int dataAlterada4 = (diaQuadrado + mesQuadrado + anoQuadrado) % 11;

  /* Aqui eu começo os blocos de condicionais para printar suas respectivas frases */
  if (dataAlterada4 == 0) {
    printf("Cor: Cinza.");
  }
  else if (dataAlterada4 == 1) {
    printf("Cor: Vermelho");
  }
  else if (dataAlterada4 == 2) {
    printf("Cor: Laranja.");
  }
  else if (dataAlterada4 == 3) {
    printf("Cor: Amarelo.");
  }
  else if (dataAlterada4 == 4) {
    printf("Cor: Verde.");
  }
  else if (dataAlterada4 == 5) {
    printf("Cor: Azul.");
  }
  else if (dataAlterada4 == 6) {
    printf("Cor: Roxo.");
  }
  else if (dataAlterada4 == 7) {
    printf("Cor: Marrom.");
  }
  else if (dataAlterada4 == 8) {
    printf("Cor: Rosa.");
  }
  else if (dataAlterada4 == 9) {
    printf("Cor: Preto.");
  }
  else {
    printf("Cor: Branco.");
  }

  return 0;
}
