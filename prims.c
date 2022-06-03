#include<stdio.h>
#include<limits.h>

int min_index(int N, int array[N]) {
    int index = 0;
    for (int i = 0; i < N; ++i)
    {
        if(array[i] >= 0 && array[i] < array[index]) {
            index = i;
        }
    }

    if (array[index] == -1)
    {
        return -1;
    }
    
    return index;
}

void prims(int src, int N, int parent[N], int G[N][N]) {
    int cost[N];
    for (int i = 0; i < N; ++i)
    {
        cost[i] = INT_MAX;
        parent[i] = -1;
    }

    // pick src as initial node
    cost[src] = 0;
    parent[src] = src;

    int node = min_index(N, cost);

    while(node >= 0) {
        cost[node] = -1;
        for (int i = 0; i < N; ++i)
        {
            if(G[node][i] > 0 && cost[i] > G[node][i]) {
                cost[i] = G[node][i];
                parent[i] = node;
            }
        }
        node = min_index(N, cost);
    }
}

int main() {

    int N, S, E;
    printf("Enter No. of Nodes: ");
    scanf("%d", &N);

    printf("Enter Source: ");
    scanf("%d", &S);

    int G[N][N];
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            G[i][j] = 0;
        }
    }

    printf("Enter No. of Edges: ");
    scanf("%d", &E);

    for(int i = 0; i < E; ++i) {
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);
        G[a][b] = cost;
        G[b][a] = cost;
    }

    int parent[N];
    prims(S, N, parent, G);

    printf("\nMinimum Spanning Tree: \n");
    int total_cost = 0;
    for (int i = 0; i < N; ++i)
    {
        int p = parent[i];
        if(i != p) {
            total_cost += G[i][p];
            printf("%d <--> %d, Cost: %d\n", i, p, total_cost);
        }
    }

    printf("\nTotal Cost of Spanning Tree: %d\n\n", total_cost);

    return 0;
}