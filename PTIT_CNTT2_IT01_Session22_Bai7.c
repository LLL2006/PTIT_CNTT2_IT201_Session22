#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adjList[100];
int visited[100];

int queue[100], front = 0, rear = -1;

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

void BFS(int start) {
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);

        Node* temp = adjList[v];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[++rear] = temp->data;
            }
            temp = temp->next;
        }
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
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo BFS tu %d: ", start);
    BFS(start);
    printf("\n");

    return 0;
}