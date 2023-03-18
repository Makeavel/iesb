#include <stdio.h>
#include <math.h>

double calculate_area(double height) {
    return height * 0.5; // calcula a área da placa cortada pela metade
}

double recursive_cut(double *heights, int n, double desired_area, double left, double right) {
    double mid = (left + right) / 2; // calcula a posição do corte
    double sum = 0.0;

    // calcula a soma das áreas acima do corte
    for (int i = 0; i < n; i++) {
        if (heights[i] > mid) {
            sum += calculate_area(heights[i] - mid);
        }
    }

    // verifica se a soma é igual à área desejada
    if (fabs(sum - desired_area) < 1e-9) {
        return mid;
    }

    // se a soma for menor, o corte deve ser mais alto
    if (sum < desired_area) {
        return recursive_cut(heights, n, desired_area, left, mid);
    }

    // se a soma for maior, o corte deve ser mais baixo
    return recursive_cut(heights, n, desired_area, mid, right);
}

int main() {
    int n;
    double desired_area;

    printf("Entre com o número de placas: ");
    scanf("%d", &n);

    double heights[n];

    printf("Entre com as alturas das placas: ");

    for (int i = 0; i < n; i++) {
        scanf("%lf", &heights[i]);
    }

    printf("Entre com a área desejada: ");
    scanf("%lf", &desired_area);

    double max_height = heights[0];

    // encontra a altura máxima das placas
    for (int i = 1; i < n; i++) {
        if (heights[i] > max_height) {
            max_height = heights[i];
        }
    }

    // realiza o corte recursivo
    double position = recursive_cut(heights, n, desired_area, 0.0, max_height);

    printf("A posição exata do corte é: %.6lf\n", position);

    return 0;
}
