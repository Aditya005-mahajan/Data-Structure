#include <stdio.h>
#define MAX 100

int graph[MAX][MAX]; 
int visited[MAX];
int n;

void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, x, y;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    if (n > MAX) {
        printf("Error: The number of vertices cannot exceed %d\n", MAX);
        return 1;
    }
    
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (format: x y):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &x, &y);
        
        if (x >= n || y >= n) {
            printf("Error: Edge vertices should be in the range [0, %d]\n", n - 1);
            return 1;
        }
        
        graph[x][y] = 1;
        graph[y][x] = 1; 
    }
    
    printf("DFS traversal starting from vertex 0:\n");
    DFS(0);
    printf("\n");
    
    return 0;
}