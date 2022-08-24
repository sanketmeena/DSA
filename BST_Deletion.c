#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;

struct node* create(int d)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=d;
    return temp;
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

struct node* inOrderPredecessor(struct node* temp)
{
    temp=temp->left;
    while(temp->right != NULL)
    {
        temp=temp->right;
    }
    return temp;
}
struct node* inOrderPostdecessor(struct node* temp)
{
    temp=temp->right;
    while(temp->left != NULL)
    {
        temp=temp->left;
    }
    return temp;
}


struct node* delete(struct node* temp,int key)
{
    if(temp==NULL) return NULL;
    if(temp->right==NULL && temp->left==NULL)
    {
        free(temp);
        return NULL;
    }

    struct node *iPre;
    //searching for the node
    if(key > temp->data) temp->right=delete(temp->right,key);
    else if(key < temp->data) temp->left=delete(temp->left,key);
    //after finding the node
    else
    {
        if(temp->left != NULL)
        {
            iPre=inOrderPredecessor(temp);
            temp->data=iPre->data;
            temp->left=delete(temp->left,iPre->data);
        }
        else
        {
            iPre=inOrderPostdecessor(temp);
            temp->data=iPre->data;
            temp->right=delete(temp->right,iPre->data);
        }

    }
    return temp;
}
void main()
{
    struct node* p=create(9);
    struct node* p1=create(4);
    struct node* p2=create(2);
    struct node* p3=create(7);
    struct node* p4=create(5);
    struct node* p5=create(8);
    struct node* p6=create(11);
    struct node* p7=create(15);
    struct node* p8=create(14);

    p->left=p1;
    p->right=p6;
    p1->left=p2;
    p1->right=p3;
    p3->left=p4;
    p3->right=p5;
    p6->right=p7;
    p7->left=p8;

    in_order(p);
    delete(p,11);
    printf("\n");
    in_order(p);
}
