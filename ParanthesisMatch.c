#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<strings.h>

char stack[10];
int top=-1;

int push()
{
    top++;
    stack[top]='(';
}
void pop()
{
    top--;
}


void main()
{
    printf("Enter the equation : \n");
    char* eq=(char*)malloc(sizeof(char));
    scanf("%[^\n]s",eq);
    //printf("\n%s",eq);

    //printf("\n%d",strlen(eq));

    for(int i=0; i<strlen(eq); i++)
    {
        char ch=*(eq+i);
        if(ch == '(')
        {
            push();
        }
        else if(ch == ')')
        {
            pop();
            if(top==-2)
            {
                printf("\n1Unbalanced equation\n");
                return;
            }
        }
        else continue;
    }
    //After whole equation ends... Stack should be empty
    if(top>-1)
    {
        printf("\n2Unbalanced equation\n");
    }
    else
    {
        printf("\nBalanced Equation\n");
    }
}
