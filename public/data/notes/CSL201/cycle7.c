#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void addEdge(int adjMatrix[MAX][MAX], int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;
}

void DFS(int adjMatrix[MAX][MAX], int vertex, int visited[], int vertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(adjMatrix, i, visited, vertices);
        }
    }
}

void BFS(int adjMatrix[MAX][MAX], int startVertex, int visited[], int vertices) {
    int queue[MAX], front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int vertices, choice, src, dest, startVertex;
    int adjMatrix[MAX][MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("1.Add Edge\n2.DFS\n3.BFS\n0.Exit");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addEdge(adjMatrix, src, dest);
                break;
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &startVertex);
                for (int i = 0; i < vertices; i++) {
                    visited[i] = 0;
                }
                printf("Depth First Search: ");
                DFS(adjMatrix, startVertex, visited, vertices);
                printf("\n");
                break;
            case 3:
                printf("Enter starting vertex: ");
                scanf("%d", &startVertex);
                for (int i = 0; i < vertices; i++) {
                    visited[i] = 0;
                }
                printf("Breadth First Search: ");
                BFS(adjMatrix, startVertex, visited, vertices);
                printf("\n");
                break;
            case 0:
                exit(0);
        }
    }
    return 0;
}
