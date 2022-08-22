#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
void find_number(int arr[],int n,int len)
{
   int low,mid,high;
   low=0;
   high=len-1;
   mid=(low+high)/2;
   while(low<=high)
   {
       mid=(low+high)/2;
       if(arr[mid]==n)
       {
           printf("Your number %d is found at : %d",n,mid);
           return;
       }
       else if(arr[mid]>n)
       {
           high=mid-1;
       }
       else
       {
            low=mid+1;
       }
   }
       printf("Didn't find your number...");
}
int main()
{
    int arr[10]={1,3,8,10,20,400,401,402,500,600};

    printf("Enter number to find its index : ");
    int n;
    scanf("%d",&n);

    find_number(arr,n,10);

    return 0;
}
