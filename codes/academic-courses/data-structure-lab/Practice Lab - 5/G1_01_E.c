#include<stdio.h>
int min(int a,int b, int c)
{
    if(a<b)
    {
        if(a<c) return a;
        else return c;
    }
    else
    {
        if(b<c) return b;
        else return c;
    }
    if(b<c)
    {
        if(b<a) return b;
        else return a;
    }
    else
    {
        if(c<a) return c;
        else return a;
    }
    if(a<c)
    {
        if(a<b) return a;
        else return b;
    }
    else
    {
        if(c<b) return c;
        else return b;
    }
}
int main()
{
    int a,b,c,m,bm,cm;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    m=min(a,b,c);
    m++;
    while(m--)
    {
        bm=2*m;
        cm=4*m;
        if(cm>c) continue;
        else
        {
            if(bm>b) continue;
            else break;
        }
    }
    printf("%d\n",m+(2*m)+(4*m));
    return 0;
}
