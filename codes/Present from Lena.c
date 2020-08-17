#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char t;
    int i,j,n;
    scanf("%d",&n);


    for(i=0;i<=n;i++)
    {
        for(j=0;j<2*(n-i);j++) printf(" ");
        for(j=0;j<i;j++)
        {
            t=(char) j +'0';
            printf("%c ",t);
        }

        t=i+'0';
        if(i!=0) printf("%c ",t);
        else printf("%c",t);

        for(j=i-1;j>=0;j--)
        {
            t=j+'0';
            if(j!=0) printf("%c ",t);
            else printf("%c",t);
        }

        printf("\n");
    }

    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<2*(n-i);j++) printf(" ");
        for(j=0;j<i;j++)
        {
            t=j+'0';
            printf("%c ",t);
        }

        t=i+'0';
        if(i!=0) printf("%c ",t);
        else printf("%c",t);

        for(j=i-1;j>=0;j--)
        {
            t=j+'0';
            if(j!=0) printf("%c ",t);
            else printf("%c",t);
        }

        printf("\n");
    }

}
