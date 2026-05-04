#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// armazena as infos de cada cidade
struct cidade {
  char nome[50];
  int populacao;
  int periculosidade;
  char funcao[50];
  int temChave;
  int valorChave;
};

//função que percorre e desvenda a mensagem recebida
void decodificar(struct cidade lista[], int index, char frase[]) {
  int idxNome = 0;
  int idxPop = 0;
  int idxFuncao = 0;
  int espacos = 0;
  int lendoFuncao = 0;
  char str[20] = "";

  lista[index].periculosidade = 0;
  lista[index].temChave = 0;

  //percorre a frase ate o final do buffer
  for(int i = 0; frase[i] != '\0'; i++) {
    // verificando a mensagem especial
    if(frase[i] == '!') {
      lista[index].temChave = 1;
    }

    // se a letra atual for maiuscula e ainda estiver rolando a verificação ele armazena o resultado na struct de nome da cidade - primeira letra é maiuscula e o resto do nome da cidade ele converte para minuscula
    if(isupper(frase[i])) {
      if(idxNome == 0) {
        lista[index].nome[idxNome] = frase[i];
      } else {
        lista[index].nome[idxNome] = tolower(frase[i]);
      }
      idxNome++;
    }

    //se for um numero ele armazena na quantidade de gente na struct
    if(isdigit(frase[i])) {
      str[idxPop] = frase[i];
      idxPop++;
    }

    // add 1 para definir o nivel de perigo da cidade atual
    if(frase[i] == '*') {
      lista[index].periculosidade += 1;
    }

    // contagem de espaços para descobrir a função da cidade
    if(frase[i] == ' ') {
      espacos++;
      if(espacos >= 2) {
        lendoFuncao = 1;
      }
    } else {
      if(espacos >= 2) {
        // se tiver contado dois espaços seguidos, ele verifica se é uma letra 
        if(lendoFuncao == 1 && isalpha(frase[i])) {
          if(idxFuncao == 0) {
            // se for o começo da palavra converte pra maiusculo, caso contrario bota todo mundo praminusculo
            lista[index].funcao[idxFuncao] = toupper(frase[i]);
          } else {
            lista[index].funcao[idxFuncao] = tolower(frase[i]);
          }
          idxFuncao++;
        }
      }
      espacos = 0;
    } 
  }

  // dando o final em cada lista de nome
  lista[index].nome[idxNome] = '\0';
  lista[index].funcao[idxFuncao] = '\0';
  str[idxPop] = '\0';

  // verificando se tem a chave especial, caso não tiver a informação é de população e transformando tudo em int
  if(lista[index].temChave == 1) {
    lista[index].valorChave = atoi(str);
  } else {
    lista[index].populacao = atoi(str);
  }
}

// codigo do bubble sort, que ordena em decrescente e verifica cada situação de empate, e por fim troca
void bubbleSort(int totalCidade, struct cidade lista[]) {
  for(int i = 0; i < totalCidade - 1; i++) {
      for(int j = 0; j < totalCidade - i - 1; j++) {
        int trocar = 0;

        if(lista[j].populacao < lista[j + 1].populacao) {
          trocar = 1;
        } else if(lista[j].populacao == lista[j + 1].populacao) {
          if(lista[j].periculosidade < lista[j + 1].periculosidade) {
            trocar = 1;
          } else if(lista[j].periculosidade == lista[j + 1].periculosidade) {
            if(strcmp(lista[j].nome, lista[j + 1].nome) > 0) {
              trocar = 1;
            }
          }
        }
        if(trocar == 1) {
          struct cidade secundaria = lista[j];
          lista[j] = lista[j + 1];
          lista[j + 1] = secundaria;
        }
      }
  }
}

int main() {
  struct cidade lista[100];
  int totalCidade = 0;
  int achouChave = 0;
  int indexChave = -1;
  char frase[1000];

  while(scanf(" %[^\n]", frase) != EOF) {
    decodificar(lista, totalCidade, frase);

    // aqui eu vejo se achou a cidade e atribuo os valores do encontrado, caso eu não ache eu verifico a proxima mensagem da proxima cidade
    if(lista[totalCidade].temChave == 1) {
      indexChave = lista[totalCidade].valorChave;
      achouChave = 1;
    } else {
      totalCidade++;
    }
  }

  if(achouChave == 0) {
    printf("Gingrey ainda não foi achada, vamos esperar mais um pouco.");
  } else {
    bubbleSort(totalCidade, lista);
    
    int alvo = indexChave - 1;

    // para printar a quantidade certa de * do nivel de perigo da cidade
    char perigoStr[50] = "";
    for(int k = 0; k < lista[alvo].periculosidade; k++) {
      perigoStr[k] = '*';
    }
    perigoStr[lista[alvo].periculosidade] = '\0';

    printf("Gingrey foi encontrada em %s, uma cidadela com %d mil habitantes cuja função é %s e periculosidade %s.", lista[alvo].nome, lista[alvo].populacao, lista[alvo].funcao, perigoStr);

    int atingiu1000 = (lista[alvo].populacao >= 1000);
    int atingiuPerigo = (lista[alvo].periculosidade > 3);

    if(atingiu1000 && !atingiuPerigo) {
      printf(" Um lugar denso, vai ser difícil achar ela.");
    } else if(!atingiu1000 && atingiuPerigo) {
      printf(" Vai ser complicado entrar lá.");
    } else if(atingiu1000 && atingiuPerigo) {
      printf(" Talvez seja melhor desistir...");
    }
  }

  return 0;
}
