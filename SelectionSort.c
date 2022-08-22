#include<stdio.h>
void printarr(int *a,int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
}
void selectionSort(int* a,int n)
{
    printf("\nSelection sort is running\n");
    for(int i=0; i<n-1; i++)
    {
        int min_indx=i;
        for(int j=i+1; j<n; j++)
        {
            if(a[min_indx] > a[j])
            {
                min_indx=j;
            }
        }
        //Because of below code, each number will be swap, either with itself or some other element but it will.
        int temp=a[min_indx];
        a[min_indx]=a[i];
        a[i]=temp;
    }
}
void main()
{
    int a[]={2,3,1,5,3,2,6,4,6,1,0};
    int n=11;
    printarr(a,n);
    selectionSort(a,n);
    printarr(a,n);
}
