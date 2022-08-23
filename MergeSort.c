#include<stdio.h>
#include<stdlib.h>

void printarr(int *A,int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",A[i]);
    printf("\n");
}
void merge(int* A,int low,int mid,int high)
{
    int B[37];
    int i,j,k; //To add +1;
    i=low;
    j=mid+1;
    k=low;
    //int *B=(int*)malloc(100,sizeof(int)); it's not working

    while(i<=mid && j<=high)
    {
        if(A[i] < A[j])
        {
            B[k]=A[i];
            i++,k++;
        }
        else
        {
            B[k]=A[j];
            j++,k++;
        }
    }
    while(i<=mid)
    {
        B[k]=A[i];
        i++,k++;
    }
    while(j<=high)
    {
        B[k]=A[j];
        j++,k++;
    }
    for(int l=0; l<=high; l++) A[l]=B[l];
}

void mergeSort(int *A,int low,int high)
{
    int mid=(low+high)/2;

    if(low<high)
    {
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}

void main()
{
    int A[]={5,3,2,3,6,7,8,9,1,3,0,78};
    int n=12;
    printarr(A,n);
    mergeSort(A,0,n-1);
    printarr(A,n);
}
