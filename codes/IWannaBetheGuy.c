#include<stdio.h>
#include <stdlib.h>

int main()
{



    int n,i=1,c=1,p,q;

    scanf("%d",&n);
    int s[n],a;


    while(i<=n)
    {
        s[i]=1;
        i++;
    }

    scanf("%d",&p);

    i=1;

    while(i<=p)
    {
        scanf("%d",&a);
        s[a]=0;
        i++;
    }

    scanf("%d",&q);

    i=1;

    while(i<=q)
    {
        scanf("%d",&a);
        s[a]=0;
        i++;
    }

    //char temp;

    /*do
    {
        scanf("%d%c", &a, &temp);
        s[a]=0;
    }while(temp == ' ');

    do
    {
        scanf("%d%c", &a, &temp);
        s[a]=0;
    }while(temp == ' ');*/

    i=1;

    while(i<=n)
    {
        if(s[i]!=0)
        {
            c=0;
            break;

        }
        i++;
    }

    if(c==1)
    {
        printf("I become the guy.\n");
    }
    else
    {
        printf("Oh, my keyboard!\n");
    }

    return 0;

}
