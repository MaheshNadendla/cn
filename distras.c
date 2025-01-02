#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
#define V 5 // Number of vertices
int minDistance(int dist[], int visited[])
{
    int min = INF, minIndex;
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void dijkstra(int graph[V][V], int src)
{
    int dist[V], visited[V] = {0};
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}
int main()
{
    int graph[V][V] = {
        {0, 2, 0, 1, 0},
        {2, 0, 3, 2, 0},
        {0, 3, 0, 0, 1},
        {1, 2, 0, 0, 1},
        {0, 0, 1, 1, 0},
    };
    int src;
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &src);
    dijkstra(graph, src);
    return 0;
}