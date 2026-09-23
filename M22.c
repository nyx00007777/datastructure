#include <stdio.h>

int c[2005];
int d[2005][2005];

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int e = 1; e <= a; ++e) {
        scanf("%d", &c[e]);
    }
    for (int e = 1; e <= a; ++e) {
        int g[105] = {0};
        int h = 0;
        for (int f = e; f <= a; ++f) {
            if (g[c[f]] == 0) {
                h++;
            }
            g[c[f]]++;
            d[e][f] = h;
        }
    }
    int i;
    scanf("%d", &i);
    while (i--) {
        int j, k;
        scanf("%d %d", &j, &k);
        printf("%d\n", d[j][k]);
    }
    return 0;
}