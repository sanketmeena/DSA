#include<stdio.h>
void main()
{
    int arr[20];
    printf("Enter elements : ");
    for(int i=0; i<20; i++)
    {
        printf("%3d  : ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nElements after sorting ...\n");
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<19-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0; i<20; i++) printf("%d ",arr[i]);
}
