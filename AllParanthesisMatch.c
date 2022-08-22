#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<strings.h>

#define CAPACITY 20

char stack[CAPACITY];
int top=-1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

//Match function, returns 1, if mismatch else returns 0
int match(char ch)
{
    if(ch==')' && stack[top]=='(')
    {
        return 0;
    }
    else if(ch=='}' && stack[top]=='{')
    {
        return 0;
    }
    else if(ch==']' && stack[top]=='[')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void pop(char ch)
{
    if(match(ch))
    {
        printf("\n3. Unbalanced\n");
        exit(0);
    }
    top--;
}

void main()
{
    printf("Enter the equation : \n");
    //Here it is necessary to give the size of char, otherwise it will start showing error (200)
    char* eq=(char*)malloc(200*sizeof(char));
    scanf("%[^\n]s",eq);
    //printf("\n%d",strlen(eq));

    for(int i=0; i<strlen(eq); i++)
    {
        char ch= *(eq+i);
        //On open bracket, call push
        if(ch=='(' || ch=='{' || ch=='[')
        {
            push(ch);
        }
        else if(ch==')' || ch=='}' || ch==']')
        {
            //On closing bracket call pop but closed & present bracket should be match.
            pop(ch);
            if(top == -2)
            {
                printf("\n2. Unbalanced\n");
                return;
            }
        }
        else continue;
    }
    //At the end of equation, stack should be empty
    if(top != -1)

    {
        printf("\n4. Unbalanced\n");
        return;
    }
    else
    {
        printf("\nBalanced\n");
    }
}
