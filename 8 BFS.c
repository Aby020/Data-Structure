#include <stdio.h>

#define MAX_SIZE 100

int n, graph[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE], nodeValues[MAX_SIZE];
int front = -1, rear = -1, queue[MAX_SIZE];

void enqueue(int data) {
    if (rear == n - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = data;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        if (front == rear) front = rear = -1;
        else front++;
    }
}

void bfs(int startNode) {
    visited[startNode] = 1;
    enqueue(startNode);
    printf("Visited nodes: ");
    while (front != -1) {
        int currentNode = queue[front];
        dequeue();
        printf("%d ", nodeValues[currentNode]);
        for (int i = 0; i < n; i++) {
            if (graph[currentNode][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter values of each node:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i + 1);
        scanf("%d", &nodeValues[i]);
        visited[i] = 0; // Initialize visited array
    }

    printf("Enter adjacency matrix (0 or 1) for edges:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Edge between node %d and node %d (1/0): ", nodeValues[i], nodeValues[j]);
            scanf("%d", &graph[i][j]);
        }
    }

    int startValue;
    printf("Enter starting node value: ");
    scanf("%d", &startValue);

    int startIndex = -1;
    for (int i = 0; i < n; i++) {
        if (nodeValues[i] == startValue) {
            startIndex = i;
            break;
        }
    }

    if (startIndex == -1) {
        printf("Invalid starting node value\n");
    } else {
        bfs(startIndex);
    }

    return 0;
}
