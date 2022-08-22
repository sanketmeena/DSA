#include<stdio.h>
#include<stdlib.h>

struct linkedList
{
    int data;
    struct linkedList* next;
};
struct linkedList* head=(linkedList*)malloc(sizeof(linkedList));
head=NULL;

void main()
{
    while(1)
    {
        printf("Enter choice : ");
        printf("1. Append\n");
        printf("2. Display\n");
        printf("3. Add at first\n");

        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : append();
            break;
            case 2 : display();
            break;
            case 3 : add_at_first();
            break;
            default: {
                    printf("Enter right choice...\n");
                    printf("Press any key...\n");
                    getch();
            }
        }
    }
}
