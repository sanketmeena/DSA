#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 8

int queue[CAPACITY];
int start=0,end=0;

int isFull()
{
    if(end==CAPACITY) return 1;
    else return 0;
}
int isEmpty()
{
    if(end==start) return 1;
    else return 0;
}
void enque(int val)
{
    queue[end]=val;
    end++;
}
int deque()
{
    int val=queue[start];
    for(int i=1; i<end; i++) queue[i-1]=queue[i];
    end--;
    return val;
}
void traverse()
{
    printf("\nThe elements are : \n");
    for(int i=0; i<end; i++) printf("%d ",queue[i]);
}

void main()
{
    int visited[]={0,0,0,0,0,0,0};
    int root=4;
    
    int graph[][7]={{0,1,1,1,0,0,0},
                    {1,0,0,1,0,0,0},
                    {1,0,0,1,1,0,0},
                    {1,1,1,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0}};
                    
    visited[root]=1;
    enque(root);
    printf("%d ",queue[0]);
    
    while(!isEmpty())
    {
        int node=deque();
        
        for(int i=0; i<7; i++)
        {
            if(graph[node][i] == 1 && visited[i]==0)
            {
                printf("%d ",i);
                visited[i]=1;
                enque(i);
            }
        }
    }
}
