#include<stdio.h>
int max(int a,int b,int c)
{
    if(a<b)
    {
        if(b<c)
        {
            return c;
        }
        else return b;
    }
    else if(b<a)
    {
        if(a<c)
        {
            return c;
        }
        else return a;
    }
    else if(a==b)
    {
        if(c>b)
        {
            return c;
        }
        else return b;
    }
}
int min(int a,int b,int c)
{
    if(a>b)
    {
        if(b>c)
        {
            return c;
        }
        else return b;
    }
    else if(b>a)
    {
        if(a>c)
        {
            return c;
        }
        else return a;
    }
    else if(a==b)
    {
        if(c<b)
        {
            return c;
        }
        else return b;
    }
}

int main()
{

    int n,a[5100],i,one[5100],two[5100],three[5100],o=0,tw=0,th=0;

    scanf("%d",&n);

    i=0;
    while(i<n)
    {
        scanf("%d",&a[i]);
        if(a[i]==1){one[o]=i+1;o++;}
        else if(a[i]==2){two[tw]=i+1;tw++;}
        else if(a[i]==3){three[th]=i+1;th++;}
        i++;
    }

    int x=min(o,tw,th);
    printf("%d\n",x);

    i=0;
    while(i<x)
    {
        printf("%d %d %d\n",one[i],two[i],three[i]);
        i++;
    }
    return 0;

}
