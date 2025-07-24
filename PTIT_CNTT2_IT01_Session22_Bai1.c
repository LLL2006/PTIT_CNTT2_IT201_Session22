#include <stdio.h>

void addEdge(int graph[][100], int node1, int node2) {
    graph[node1][node2] = 1;
graph[node2][node1] = 1;
}

void printGraph(int graph[][100], int n) {
    for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
printf("%d ", graph[i][j]);
}
printf("\n");
}
}

int main() {
    int n, m;
    printf("Nhap so dinh: ");
    scanf("%d", &n);
    printf("Nhap so canh: ");
    scanf("%d", &m);

int graph[100][100] = {0};

for(int i = 0; i < m; i++) {
int node1, node2;
scanf("%d %d", &node1, &node2);
addEdge(graph, node1, node2);
}

printGraph(graph, n);

return 0;
}