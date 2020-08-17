#include<stdio.h>

int main()
{
    while(1){

    int n,i=0,j=0,k=0;
    char a[100100],b[100100],c[100100],x,y;

    scanf("%d\n",&n);

    gets(a);
    gets(b);
    gets(c);

    while(i<n)
    {
        j=0;k=0;
        while(j<n-1)
        {
            if(b[j]==a[i])
            {
                k++;
            }
            j++;
        }
        if(k!=0)
        {
            x=a[i];
        }
        i++;
    }

    i=0;

    while(i<n-1)
    {
        j=0;k=0;
        while(j<n-2)
        {
            if(c[j]==b[i])
            {
                k++;
            }
            j++;
        }
        if(k!=0)
        {
            x=b[i];
        }
        i++;
    }

    i=0;

    while(i<n-2)
    {
        if(b[i]=='x')
        {
            printf("%c\n",b[i]);
        }
        i++;
    }

    }return 0;
}
