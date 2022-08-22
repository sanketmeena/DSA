#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define CAPACITY 5
int queue[CAPACITY];
int front=0,rear=0;

void insert()
{
    if(CAPACITY ==rear)
    {
        printf("Queue is full\n");
        printf("Press any key...");
        getch();
    }
    else
    {
        printf("Enter data : ");
        int el; scanf("%d",&el);
        queue[rear]=el;
        rear++;
    }
}
void delete()
{
    if(rear==front)
    {
        printf("Queue is Empty\n");
        printf("Press any key...");
        getch();
    }
    else
    {
        printf("Deleted item is : %d\n",queue[front]);
        for(int i=1; i<rear; i++)
        {
            queue[i-1]=queue[i];
        }
        rear--;
        printf("Press any key...");
        getch();
    }
}
void traverse()
{
    if(rear==front)
    {
        printf("Queue is Empty\n");
        printf("Press any key...");
        getch();
    }
    else
    {
        printf("\nQueue elements are : \n");
        for(int i=front; i<rear; i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\nPress any key...");
        getch();
    }
}
void main()
{
    while(1)
    {
        system("cls");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");

        int i;
        printf("\nEnter your choice : ");
        scanf("%d",&i);

        switch(i)
        {
            case 1 : insert();
            break;
            case 2 : delete();
            break;
            case 3 : traverse();
            break;
            default: {
                    printf("Wrong choice\n");
                    printf("Press any key...\n");
                    getch();
            }
            break;
        }
    }
}
