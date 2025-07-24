#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void convertToAdjList(int adjMatrix[100][100], Node* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1) {
                Node* newNode = createNode(j);
                if (adjList[i] == NULL) {
                    adjList[i] = newNode;
                } else {
                    Node* temp = adjList[i];
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = newNode;
                }
            }
        }
    }
}

void printAdjList(Node* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    int n;
    printf("Nhap so dinh: ");
    scanf("%d", &n);

    int adjMatrix[100][100];

    printf("Nhap ma tran ke (%d dong, moi dong %d so 0 hoac 1):\n", n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    Node* adjList[100];

    convertToAdjList(adjMatrix, adjList, n);

    printAdjList(adjList, n);

    return 0;
}