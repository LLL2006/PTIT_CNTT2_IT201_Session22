#include <stdio.h>

int main() {
    int n, v;
    int adjMatrix[100][100] = {0};

    printf("Nhap so dinh va so canh: ");
    scanf("%d", &n, &v);

    printf("Nhap cac canh: ");
    for (int i = 0; i < v; i++) {
        int u , w;
        scanf("%d %d", &u, &w);
        adjMatrix[u][w] = 1;
        adjMatrix[w][u] = 1;
    }

    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    int degree = 0;

    for (int j = 0; j < n; j++) {
        if (adjMatrix[j][0] == 1) {
            degree++;
        }
    }

    printf("So dinh ke voi %d la: %d\n", k , degree);

    return 0;
}