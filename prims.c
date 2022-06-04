#include<stdio.h>
#include<limits.h>

// returns index of minimum non negative value otherwise -1;
int min_priority(int N, int array[N]) {
    int index = 0;
    for (int i = 0; i < N; ++i)
    {
        if(array[i] >= 0 && array[i] < array[index]) {
            index = i;
        }
    }

    if (array[index] < 0)
    {
        return -1;
    }
    
    return index;
}

void prims(int start, int N, int parent[N], int G[N][N]) {
    int priority[N];
    for (int i = 0; i < N; ++i)
        priority[i] = INT_MAX;

    // pick start as initial node
    priority[start] = 0;
    parent[start] = start;

    int node = start;

    // while unfixed node exists;
    while(node >= 0) {
        priority[node] = -1; // fix current node;
        for (int i = 0; i < N; ++i)
        {
            if(G[node][i] > 0 && priority[i] > G[node][i]) {
                priority[i] = G[node][i];
                parent[i] = node;
            }
        }
        node = min_priority(N, priority);
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
            printf("%d <--> %d, Cost: %d\n", i, p, G[i][p]);
        }
    }

    printf("\nTotal Cost of Spanning Tree: %d\n\n", total_cost);

    return 0;
}