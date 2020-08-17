#include<stdio.h>

int main()
{

    char s[100010];
    int n,i=0,a=0,d=0;
    scanf("%d\n",&n);


    while(i<n)
    {
        scanf("%c",&s[i]);
        i++;
    }

    i=0;

    while(i<n)
    {
        if(s[i]=='A')
        {
            a++;
        }
        else
        {
            d++;
        }
        i++;
    }
    if(a>d)
    {
        printf("Anton\n");
    }
    else if(a<d)
    {
        printf("Danik\n");
    }
    else
    {
        printf("Friendship\n");
    }

    return 0;
}
