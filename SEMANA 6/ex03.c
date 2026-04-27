int calibracao(int valor) {
  return valor + 5;
}

int saturacao(int valor) {
  // operador ternario que substitui if-else, então se o valor for maior que 80, ele retorna 80, caso contrario retorna o proprio valor (não foi IA, aprendi com JScript, juro)
  return (valor > 80) ? 80 : valor;
}

int amplificador(int valor) {
  return valor * 2;
}

void modificar(int linha, int coluna, int **matriz, int (*filtros[])(int), int qtdeComando, int *comandos) {
  // os dois primeiros for são pra percorrer a matriz, classico
  for(int i = 0; i < linha; i++) {
    for(int j = 0; j < coluna; j++) {
      // aqui ele percorre o vetor do comando, então se for papiline, ele excuta os comandos e se for so 1, executa tambem
      for(int k = 0; k < qtdeComando; k++) {
        int comandoAplicado = comandos[k];
        matriz[i][j] = filtros[comandoAplicado](matriz[i][j]);
      }
    }
  }
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  int **matriz = (int *)malloc(N * sizeof(int));

  // alocação da matriz
  for(int i = 0; i < N; i++) {
    matriz[i] = (int *)malloc(M * sizeof(int));
  }

  // construindo a matriz
  int numAtual;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      scanf("%d", &numAtual);
      matriz[i][j] = numAtual;
    }
  }

  // fazendo o vetor de ponteiro para função
  int comando;
  int (*filtros[4])(int);
  filtros[1] = calibracao;
  filtros[2] = saturacao;
  filtros[3] = amplificador;

  // o while dos comandos, que so para ate receber 0
  while(scanf("%d", &comando) == 1 && comando != 0) {
    // aqui se o comando estiver entre 1 e 3, ele so vai ser executado 1 vez
    if(comando >= 1 && comando <= 3) {
      int seq[1] = {comando};
      modificar(N, M, matriz, filtros, 1, seq);
    } 
    // ele igual a 4 é o pipeline que armazena os comandos em um vetor, que é alocado dinamicamente e chama a função pra executar os filtros
    else if(comando == 4) {
      int k;
      scanf("%d", &k);
      int *comandos = (int *)malloc(k * sizeof(int));

      // recebendo os comandos do pipeline
      for(int i = 0; i < k; i++) {
        scanf("%d", &comandos[i]);
      }

      modificar(N, M, matriz, filtros, k, comandos);
      free(comandos);
    }
  }

  int sensorCritico = -1;
  int posiX = -1;
  int posiY = -1;

  // imprime a matriz com as modificações e chama o sensor critico e sua posição
  printf("Matriz processada:\n");
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      int sensorAtual = matriz[i][j];
      if(sensorAtual > sensorCritico) {
        sensorCritico = sensorAtual;
        posiX = i;
        posiY = j;
      }
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  printf("\nSensor critico: %d\n", sensorCritico);
  printf("Posicao: (%d,%d)", posiX, posiY);

  // liberando a memoria alocada
  for(int i = 0; i < N; i++) {
    free(matriz[i]);
  }
  free(matriz);
  return 0;
}
