#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  float Slength;
  float Swidth;
  float Plenght;
  float Pwidth;
  char species[50];
} Iris;

void processarArquivo(FILE *arquivo, char nome[]) {
  char linha[300];
  fgets(linha, 300, arquivo);

  int capacidade = 1;
  int quantidade = 0;
  Iris *flores = malloc(capacidade * sizeof(Iris));

  while(fgets(linha, 300, arquivo) != NULL) {
    if(capacidade == quantidade) {
      capacidade *= 2;
      Iris *temp = realloc(flores, capacidade * sizeof(Iris));
      if(temp == NULL) {
        printf("Falha no realloc");
      }
      flores = temp;
    }
    
    sscanf(linha, "%f,%f,%f,%f,%s", 
      &flores[quantidade].Slength, 
      &flores[quantidade].Swidth,
      &flores[quantidade].Plenght,
      &flores[quantidade].Pwidth,
      flores[quantidade].species);
      quantidade++;
    }

  float somaSlenght = 0;
  float somaSwidth = 0;
  float somaPlenght = 0;
  float somaPwidth = 0;

  for(int i = 0; i < quantidade; i++) {
    somaSlenght += flores[i].Slength;
    somaSwidth += flores[i].Swidth;
    somaPlenght += flores[i].Plenght;
    somaPwidth += flores[i].Pwidth;
  }

  float mediaSlenght = somaSlenght / quantidade;
  float mediaSwidth = somaSwidth / quantidade;
  float mediaPlenght = somaPlenght / quantidade;
  float mediaPwidth = somaPwidth / quantidade;

  int contadorSetosa = 0;
  int contadorVersicolor = 0;
  int contadorVirginica = 0;
    
  for(int i = 0; i < quantidade; i++) {
    if(strcmp(flores[i].species, "Iris-setosa") == 0) {
      contadorSetosa++;
    } else if(strcmp(flores[i].species, "Iris-versicolor") == 0) {
      contadorVersicolor++;
    } else if(strcmp(flores[i].species, "Iris-virginica") == 0) {
      contadorVirginica++;
    }
  }

  char moda[50];
  int comparar = contadorSetosa;
  if(comparar < contadorVersicolor) {
    comparar = contadorVersicolor;
  } else if(comparar < contadorVirginica) {
    comparar = contadorVirginica;
  }

  if(comparar == contadorSetosa) {
    strcpy(moda, "Iris-setosa");
  } else if(comparar == contadorVersicolor) {
    strcpy(moda, "Iris-versicolor");
  } else if(comparar == contadorVirginica) {
    strcpy(moda, "Iris-virginica");
  }

  printf("%s\n", nome);

  for(int i = 0; i < quantidade; i++) {
    printf("%.2f | %.2f | %.2f | %.2f | %s\n", 
      flores[i].Slength,
      flores[i].Swidth,
      flores[i].Plenght,
      flores[i].Pwidth,
      flores[i].species
    );
  }

  printf("Moda: %s\n", moda);
  printf("Média Sepal Length: %.2f\n", mediaSlenght);
  printf("Média Sepal Width: %.2f\n", mediaSwidth);
  printf("Média Pepal Length: %.2f\n", mediaPlenght);
  printf("Média Pepal Width: %.2f\n", mediaPwidth);

  fseek(arquivo, 0, SEEK_END);
  fprintf(arquivo, "Moda: %s\n", moda);
  fprintf(arquivo, "Média Sepal Length: %.2f\n", mediaSlenght);
  fprintf(arquivo, "Média Sepal Width: %.2f\n", mediaSwidth);
  fprintf(arquivo, "Média Pepal Length: %.2f\n", mediaPlenght);
  fprintf(arquivo, "Média Pepal Width: %.2f\n", mediaPwidth);

  free(flores);
}

int main() {
  int qtdeArquivos;
  scanf("%d", &qtdeArquivos);
  
  char nome[50];
  for(int i = 1; i <= qtdeArquivos; i++) {
    sprintf(nome, "iris%d.csv", i);
    FILE *arquivo = fopen(nome, "r+");

    if(arquivo) {
      processarArquivo(arquivo, nome);
    } else {
      printf("Erro ao ler o arquivo\n");
    }
    fclose(arquivo);
  }
  
  return 0;
}
