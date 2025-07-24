#include <stdio.h>

int main() {
    int n;
    int adjMatrix[100][100];

    printf("Nhap so dinh: ");
    scanf("%d", &n);

    printf("Nhap ma tran ke (%d dong, moi dong %d so 0 hoac 1):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    int edgeCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                edgeCount++;
            }
        }
    }

    printf("%d\n", edgeCount);

    return 0;
}