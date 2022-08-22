#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* head=NULL;
//Why don't we allocate memory here ?

void add_at_first()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&temp->data);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->prev=NULL;

        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    printf("\n%d added successfully \n",temp->data);
    printf("Press any key...");
    getch();
}
void add_data()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));


    printf("\nEnter the data : ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;

    if(head==NULL)
    {
        head=temp;
        printf("\nData successfully added\n");
        printf("Press any key...\n");
        getch();
    }
    else
    {
        struct node* p;
        p=head;

        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;


        printf("\nData successfully added\n");
        printf("Press any key...\n");
        getch();
    }
}
void display()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;

    if(head==NULL)
    {
        printf("No data available\n");
    }
    else
    {
            printf("\nData present in the list is...\n");

        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        while(temp!=NULL);
    }
    /*while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }*/
    printf("\nPress any key...");
    getch();
}
void reverse()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    if(head==NULL)
    {
        printf("No data available\n");
    }
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        printf("\nThe list in reverse is as follows  : \n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->prev;
        }
    }
    printf("\nPress any key...");
    getch();
}
void main()
{
    while(1)
    {
        system("cls");
        printf("Enter the choice : \n");
        printf("1. add data\n");
        printf("2. display data\n");
        printf("3. Add at first\n");
        printf("4. Print list in reverse\n");


        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : add_data();
            break;
            case 2 : display();
            break;
            case 3 : add_at_first();
            break;
            case 4 : reverse();
            break;
            default:
                {
                    printf("Entered Wrong choice\n");
                    printf("Press any key...\n");
                    getch();
                }
        }
    }
}
