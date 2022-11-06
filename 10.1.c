// Implementation of graph using Adjacency matrix 
// The undirected graph version

#include <stdio.h>

int main()
{
    // n is the number of vertices
    // m is the number of edges
    int m = 0, n = 0, i = 0;
    int a = 0, b = 0;
    int u = 0, v = 0;
    printf("Enter your value of nodes and edges: \n");
    scanf("%d %d", &n, &m);
    int adjMat[n][n];

    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)
        {
            adjMat[a][b] = 0;
        }
    }

    for (i=0; i<m; i++)
    {
        printf("Enter your value of source and destination: \n");
        scanf("%d %d", &u, &v);
        adjMat[u-1][v-1] = 1;
        adjMat[v-1][u-1] = 1;
    }

    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)
        {
            if (adjMat[a][b] == 1)
                printf("%d", adjMat[a][b]);
            else
                printf("%d", 0);
        }
        printf("\n");
    }

    return 0;
}