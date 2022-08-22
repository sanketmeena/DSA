#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node* link;
};

//root = (struct node*)malloc(sizeof(struct node));
struct node* root=NULL;

void append()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    //Node is ready completely

    if(root==NULL) root=temp;
    else
    {
        struct node* p;
        p=root;
        while(p->link != NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }

}
void add_at_first()
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&p->data);
    p->link=root;
    root=p;
    printf("\nData added at first successfulY \n");
    printf("Press any key...\n");
    getch();
}
void add_at_after()
{
    struct node* temp, *p;
    temp=(struct node*)malloc(sizeof(struct node));
    p=(struct node*)malloc(sizeof(struct node));


    int el;
    printf("Enter data after which you want to add & the data : ");
    scanf("%d%d",&el,&p->data);

    temp=root;
    while(temp->data != el) temp=temp->link;

    p->link=temp->link;
    temp->link= p;

    printf("Data after %d added successfully \n",el);
    printf("\nPress any key...\n");
    getch();
}
void display()
{
    if(root==NULL) printf("No data present\n");
    else
    {
        struct node* p;
        p=root;
        while(p != NULL)
        {
            printf("%d ",p->data);
            p=p->link;
        }
    }
    printf("\nPress any key...\n");
    getch();
}
void length()
{
    struct node* p=(struct node*)malloc(sizeof(struct node));

    p=root;
    int len=0;
    if(p==NULL)
    {
        printf("No data present\n\n");
        printf("Press any key...");
        getch();
    }
    else
    {
        while(p!=NULL)
        {
            p=p->link;
            len++;
        }
        printf("The length is %d\n",len);
        printf("Press any key...\n");
        getch();
    }
}
void delete()
{
    struct node* p,*r;
    p=(struct node*)malloc(sizeof(struct node));
    r=(struct node*)malloc(sizeof(struct node));

    int el;
    printf("Enter data you want to delete : ");
    scanf("%d",&el);

    if(root->data == el) root=root->link;
    else
    {
        p=root;
        r=root;
        while(p->data != el)
        {
            p=p->link;
            if(p->data == el) break;
            else r=r->link;

            if(p->link == NULL)
            {
                printf("Did not find the data you entered\n");
                printf("\nPress any key...\n");
                getch();
                return;
            }

        }
        r->link=p->link;
        }
    printf("Data %d is deleted successfully \n",el);
    printf("Press any key...\n");
    getch();
}

void main()
{
    while(1)
    {
        system("cls");
        int i;
        printf("Enter the choice : \n");
        printf("1. append\n");
        printf("2. add at first\n");
        printf("3. add at after\n");
        printf("4. Display\n");
        printf("5. Length\n");
        printf("6. Delete a node\n");
        printf("Your choice : ");
        scanf("%d",&i);

        switch(i)
        {
            case 1 : append();
            break;
            case 2 : add_at_first();
            break;
            case 3: add_at_after();
            break;
            case 4 : display();
            break;
            case 5 : length();
            break;
            case 6 : delete();
            break;
            default: printf("Wrong choice\n");
            break;
        }
    }
}
