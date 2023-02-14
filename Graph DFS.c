#include<stdio.h>
#include<stdlib.h>

int visited[]={0,0,0,0,0,0,0};
    
    
int graph[][7]={{0,1,1,1,0,0,0},
                {1,0,1,0,0,0,0},
                {1,1,0,1,1,0,0},
                {1,0,1,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};

void DFS(int i)
{
    printf("%d ",i);
    visited[i]=1;
    for(int j=0; j<7; j++)
    {
        if(graph[i][j]==1 && !visited[j])
        {
            visited[j]=1;
            DFS(j);
        }
    }
}

void main()
{
    DFS(0);
}
