#include <stdio.h>

int main() {
  int num_placas, area_desejada, i=0;
  printf("Digite o número de placas: ");
  scanf("%d", &num_placas);

  int alturas[num_placas];
  for (i = 0; i < num_placas; i++) {
    printf("Digite a altura da placa %d: ", i + 1);
    scanf("%d", &alturas[i]);
  }

  printf("Digite a área desejada: ");
  scanf("%d", &area_desejada);

  int esquerda = 0, direita = alturas[0];
  for ( i = 0; i < num_placas; i++) {
    if (alturas[i] > direita) {
      direita = alturas[i];
    }
  }

  while (esquerda <= direita) {
    int meio = (esquerda + direita) / 2;

    int soma_area = 0;
    for ( i = 0; i < num_placas; i++) {
      if (alturas[i] > meio) {
        soma_area += (alturas[i] + meio + 1) * (alturas[i] - meio) / 2;
      }
    }

    if (soma_area == area_desejada) {
      printf("A posição exata do corte é %d cm\n", meio);
      return 0;
    } else if (soma_area < area_desejada) {
      direita = meio - 1;
    } else {
      esquerda = meio + 1;
    }
  }

  printf("Não foi possível encontrar a posição exata do corte.\n");
  return 0;
}
