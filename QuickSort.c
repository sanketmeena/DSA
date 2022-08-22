#include<stdio.h>

int partition(int *A,int low,int high)
{
    int pivot=A[low];
    int i=low+1;
    int j=high;
    int temp;

    do
    {
        while(A[i] <= pivot)
        {
            i++;
        }
        while(A[j] > pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }

    }while(i<j);

    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}
void printArr(int* A,int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",A[i]);
    printf("\n");
}


void quick_sort(int* A,int low,int high)
{
    if(low < high)
    {
        int part_ele=partition(A,low,high);
        printArr(A,high);
        quick_sort(A,low,part_ele-1);
        quick_sort(A,part_ele+1,high);
    }
}

void main()
{
    int A[]={24,2,5,2,5,2,1,6,7,8,0,7,5,3,8};
    int n=15;
    printArr(A,n);
    quick_sort(A,0,n-1);
    printArr(A,n);
}
