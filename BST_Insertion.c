#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;
//root->left=NULL;
//root->right=NULL;

void append()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->right=NULL;
    temp->left=NULL;
    printf("\nEnter the data : ");
    scanf("%d",&temp->data);


    struct node *p=root,*prev=root;

    if(root == NULL) root=temp;
    else
    {
        while(p!=NULL)
        {
            if(p->data == temp->data)
            {
                printf("Element is already there, can't insert\n");
                getch();
                return;
            }
            else if(p->data > temp->data) p=p->left;
            else p=p->right;

            if(p!=NULL) prev=p;
        }
        if(prev->data > temp->data) prev->left=temp;
        else prev->right=temp;
    }
}
void pre_order(struct node* temp)
{
    if(temp != NULL)
    {
        printf("%d ",temp->data);
        pre_order(temp->left);
        pre_order(temp->right);
    }
}
void post_order(struct node* temp)
{
    if(temp != NULL)
    {
        post_order(temp->left);
        post_order(temp->right);
        printf("%d ",temp->data);
    }
}
void in_order(struct node* temp)
{
    if(temp != NULL)
    {
        in_order(temp->left);
        printf("%d ",temp->data);
        in_order(temp->right);
    }
}

int main()
{
    while(1)
    {
        system("CLS");
        printf("Enter the OPTION...\n");
        printf("1. Append\n");
        printf("2. Print Pre-order\n");
        printf("3. Print Post-order\n");
        printf("4. Print Inorder\n");

        int ch;
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 : append();
            break;
            case 2 :{
                        pre_order(root);
                        printf("\nPress any key...\n");
                        getch();
                    }
            break;
            case 3 :{
                        post_order(root);
                        printf("\nPress any key...\n");
                        getch();
                    }
            break;
            case 4 :{
                        in_order(root);
                        printf("\nPress any key...\n");
                        getch();
                    }
            break;
            default: printf("Choose Wisely\n");
        }
    }

    return 0;
}
