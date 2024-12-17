#include <stdio.h>
#define INF 9999
#define v 4

void broadcastTree(int graph[v][v])
{

    int selected[v] = {0};

    selected[0] = 1;

    for(int x=0;x<v-1;x++)
    {
        int min = INF,x=0,y=0;

        for(int i=0;i<v;i++ )
        {
            if(selected[i])
            {
                for(int j=0;j<v;j++)
                {
                    if(!selected[j] && graph[i][j] && graph[i][j]<min)
                    {
                        min = graph[i][j];
                        x=i;
                        y=j;
                    }

                }
            }
        }

        printf("%d -> %d (%d)\n",x,y,min);
        selected[y]=1;
    }


}


int main()
{
    int graph[v][v] = {
        {0, 2, INF, 6},
        {2, 0, 3, 8},
        {INF, 3, 0, 5},
        {6, 8, 5, 0},
    };
    broadcastTree(graph);
    return 0;
}