#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node* link;
};
struct node* top=NULL;

void push()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->link=NULL;//This should be here otherwise the while loop in display function will not stop.
    printf("\nEnter data : ");
    scanf("%d",&temp->data);

    if(top==NULL) top=temp;
    else
    {
        temp->link=top;
        top=temp;
    }
    printf("\nData added successfully : %d\n",top->data);
    getch();
}
void pop()
{
    if(top==NULL) printf("\nStack is empty\n");
    else
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp=top;
        printf("\nDeleted element : %d\n",temp->data);
        top=top->link;
        free(temp);
    }
    printf("\nPress any key...\n");
    getch();
}
void empty()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=top;
    while(top != NULL)
    {
        top=top->link;
        free(temp);
        temp=top;
    }
}
void display()
{
    struct node* temp;
    temp=top;
    if(top==NULL) printf("\nStack is empty\n");
    else
    {
        printf("\nStack contains following data : \n");
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }
    printf("\nPress any key...\n");
    getch();
}
void length()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=top;
    int len=0;
    if(top==NULL) printf("\nStack is Empty\n");
    else
    {
        while(temp != NULL)
        {
            len++;
            temp=temp->link;
        }
        printf("\nThe size of the stack is : %d\n",len);
    }
    printf("\nPress any key...\n");
    getch();
}

void main()
{
    while(1)
    {
        system("CLS");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Empty\n");
        printf("5. Size\n");

        int ch;
        printf("Enter choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : push();
            break;
            case 2 : pop();
            break;
            case 3 : display();
            break;
            case 4 : empty();
            break;
            case 5 : length();
            break;
            default:
                {
                    printf("\nEntered wrong choice, Enter again\n");
                    getch();
                }
                break;
        }
    }
}
