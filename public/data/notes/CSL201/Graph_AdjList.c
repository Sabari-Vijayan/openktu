#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node {
    int data;
    struct Node* link;
} Node;

Node* adjList[MAX_NODES];
int visited[MAX_NODES];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->link = adjList[u];
    adjList[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = u;
    newNode->link = adjList[v];
    adjList[v] = newNode;
}

void DFS(int data) {
    visited[data] = 1;
    printf("%d ", data);

    Node* temp = adjList[data];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
        temp = temp->link;
    }
}

void BFS(int startVertex) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* temp = adjList[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                queue[rear++] = adjVertex;
                visited[adjVertex] = 1;
            }
            temp = temp->link;
        }
    }
}

int main() {
    int nodes = 5;
    for (int i = 0; i < nodes; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    printf("DFS: ");
    DFS(0);
    printf("\n");

    for (int i = 0; i < nodes; i++)
        visited[i] = 0;

    printf("BFS: ");
    BFS(0);

    return 0;
}
