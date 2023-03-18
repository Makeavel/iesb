#include <stdio.h>
#include <math.h>

#define EPS 1e-9

int main() {
    int n, a;
    while (scanf("%d %d", &n, &a) == 2 && (n || a)) {
        int c[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);
        }
        double lo = 0, hi = 1e4;
        while (hi - lo > EPS) {
            double mid = (lo + hi) / 2;
            double total = 0;
            for (int i = 0; i < n; i++) {
                if (c[i] > mid) {
                    total += c[i] - mid;
                }
            }
            if (fabs(total * mid - a) < EPS) {
                printf("%.4f\n", mid);
                break;
            } else if (total * mid > a) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        if (hi - lo <= EPS) {
            printf("-.-\n");
        }
    }
    return 0;
}
