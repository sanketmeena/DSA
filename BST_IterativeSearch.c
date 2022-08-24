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
struct node* search(struct node* temp,int key)
{
    while(temp!=NULL)
    {
        if(temp->data == key) return temp;
        else if(temp->data > key) return search(temp->left,key);
        else return search(temp->right,key);
    }
    return NULL;
}
void main()
{
    struct node* p=create(9);
    struct node* p1=create(4);
    struct node* p2=create(2);
    struct node* p3=create(7);
    struct node* p4=create(5);
    struct node* p5=create(7);
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

    struct node* n = search(p,00);
    if(n != NULL) printf("Element found : %d",n->data);
    else printf("Not found");
}
