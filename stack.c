#include<stdio.h>
#define CAPACITY 5
int stack[CAPACITY];
int top=-1;

int is_full()
{
    if(top== CAPACITY-1) return 1;
    else return 0;
}
int is_empty()
{
    if(top==-1) return 1;
    else return 0;
}

void push()
{
    if(is_full())
    {
        printf("Stack is completely full\n");
        printf("press any key...\n");
        getch();
    }
    else
    {
        printf("Enter element : ");
        int el; scanf("%d",&el);
        top++;
        stack[top]= el;
        printf("Element is pushed successfully \n");
        printf("press any key...\n");
        getch();
    }
}
void pop()
{
    if(is_empty())
    {
        printf("Stack is empty\n");
        printf("press any key...\n");
        getch();
    }
    else
    {
        top--;
        printf("Element is poped-up successfully\n");
        printf("press any key...\n");
        getch();
    }
}
void traverse()
{
    if(is_empty())
    {
        printf("No element is in the stack\n");
        printf("press any key...\n");
        getch();
    }
    else
    {
        for(int i=0; i<=top; i++) printf("%d ",stack[i]);
        printf("press any key...\n");
        getch();
    }
}
void empty()
{
    top=-1;
    printf("stack deleted completely");
    printf("press any key...\n");
    getch();
}
void size()
{
    if(is_empty())
    {
        printf("stack is empty\n");
        printf("press any key...\n");
        getch();
    }

    else
    {
        printf("There are %d elements in stacks \n", top+1);
        printf("press any key...\n");
        getch();
    }

}

void main()
{
    while(1){
        system("CLS");
        int i;
        printf("Enter the choice : \n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. Traverse\n");
        printf("4. Empty\n");
        printf("5. size\n");
        printf("Your choice : ");
        scanf("%d",&i);
        switch(i)
        {
            case 1 : push();
            break;
            case 2 : pop();
            break;
            case 3 : traverse();
            break;
            case 4 : empty();
            break;
            case 5 : size();
            break;
            default: printf("Enter again\n\n");
            break;
        }
    }
}
