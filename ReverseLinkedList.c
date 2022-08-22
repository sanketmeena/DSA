#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
void main()
{
    char ch[10];
    scanf("%[^\n]s",ch);

    char m;

    /*while(m != '\0')
    {
        printf("%c ",m);
        m=getchar();
    }*/
    for(int i=0; i<strlen(ch); i++)
    {
        m=*(ch+i);
        printf("%c ",m);
    }
}
