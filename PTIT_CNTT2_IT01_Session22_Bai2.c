#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[], int node1, int node2) {
    if (graph[node1] == NULL) {
        graph[node1] = createNode(node2);
    } else {
        Node* temp = graph[node1];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode(node2);
    }

    if (graph[node2] == NULL) {
        graph[node2] = createNode(node1);
    } else {
        Node* temp = graph[node2];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode(node1);
    }
}

void printGraph(Node* graph[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf(" %d", temp->data);
            temp = temp->next;
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

    Node* graph[100] = {NULL};

    for (int i = 0; i < m; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        addEdge(graph, node1, node2);
    }

    printGraph(graph, n);

    return 0;
}
