#include <stdio.h>
#define INF 9999
#define V 4
void distanceVectorRouting(int costMatrix[V][V])
{
    int distance[V][V], j, k, i;
    // Initialize distance array
    for (j = 0; j < V; j++)
    {
        for (k = 0; k < V; k++)
        {
            distance[j][k] = costMatrix[j][k];
        }
    }
    // Update distances based on intermediate nodes
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            for (k = 0; k < V; k++)
            {
                if (distance[j][i] + distance[i][k] < distance[j][k])
                {
                    distance[j][k] = distance[j][i] + distance[i][k];
                }
            }
        }
    }
    // Print routing tables
    for (j = 0; j < V; j++)
    {
        printf("\nRouting Table for Node %d:\n", j);
        printf("Destination\tDistance\n");
        for (k = 0; k < V; k++)
        {
            printf("%d\t\t%d\n", k, distance[j][k]);
        }
    }
}
int main()
{
    int costMatrix[V][V] = {
        {0, 2, INF, 6},
        {2, 0, 3, 8},
        {INF, 3, 0, 5},
        {6, 8, 5, 0},
    };
    distanceVectorRouting(costMatrix);
    return 0;
}
