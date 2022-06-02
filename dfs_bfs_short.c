#include <stdio.h>
#define MAX_SIZE 100000

int queue[MAX_SIZE], stack[MAX_SIZE];
int queue_start = 0;
int queue_end = 0;
int stack_size = 0;

void print(int value) {
    printf("%d\n", value);
}

void dfs(int src, int N, int visited[N], int G[N][N]) {

    // stack_push(my_stack, src);
    stack[stack_size++] = src;

    visited[src] = 1;

    printf("DFS: \n");

    while(stack_size > 0) {
        // int node = stack_top(my_stack);
        // stack_pop(my_stack);
        int node = stack[--stack_size];
    
        printf("Visited: %d\n", node);

        for (int i = 0; i < N; ++i)
        {
            if(G[node][i] == 1 && visited[i] == 0) {
                stack[stack_size++] = i; // stack_push(my_stack, i);
                visited[i] = 1;
            }
        }
    }
}

void bfs(int src, int N, int visited[N], int G[N][N]) {

    // queue_push(my_queue, src);
    queue[queue_end++] = src;
    visited[src] = 1;

    printf("BFS: \n");

    while(queue_end > queue_start) {

        // int node = queue_top(my_queue);
        // queue_pop(my_queue);
        int node = queue[queue_start++];

        printf("Visited: %d\n", node);

        for (int i = 0; i < N; ++i)
        {
            if(G[node][i] && !visited[i]) {
                // queue_push(my_queue, i);
                queue[queue_end++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    
    int N, S, E;
    printf("Enter No. of Nodes: ");
    scanf("%d", &N);

    printf("Enter Source: ");
    scanf("%d", &S);

    int G[N][N], visited1[N], visited2[N];
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        visited1[i] = 0;
        visited2[i] = 0;
    }
    

    printf("Enter No. of Edges: ");
    scanf("%d", &E);

    for(int i = 0; i < E; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a][b] = 1;
        G[b][a] = 1;
    }

    dfs(S, N, visited1, G);
    bfs(S, N, visited2, G);

    return 0;
}