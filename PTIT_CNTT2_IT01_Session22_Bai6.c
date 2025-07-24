#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adjList[100];
int visited[100];

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    Node* temp = adjList[v];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            DFS(temp->data);
        }
        temp = temp->next;
    }
}


int main() {
    int v, e;
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    for (int i = 0; i < v; i++) {
        adjList[i] = NULL;
    }

    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(start);
    printf("\n");

    return 0;
}