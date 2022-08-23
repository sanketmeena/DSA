#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printarr(int *A,int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",A[i]);
    printf("\n");
}
int find_max(int* A,int n)
{
    int max=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(A[i]>max) max=A[i];
    }
}

void count_sort(int *A,int n)
{
    int max=find_max(A,n);
    int* B=(int*)calloc((max+1),sizeof(int));

    printarr(B,max+1);

    for(int i=0; i<n; i++)
    {
        B[A[i]]+=1;
    }
    int j=0;
    for(int i=0; i<=max; i++)
    {
        if(B[i]>0)
        {
            A[j]=i;
            j++;
            B[i]-=1;
            i-=1;
        }
    }
    printarr(A,n);
}
void main()
{
    int A[]={3,2,5,6,4,3,6,7,2,7,8,9,1,0};
    int n=14;
    printarr(A,n);
    count_sort(A,n);
}
