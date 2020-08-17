#include<stdio.h>

int main()
{
    int n,f,z,i,j,k,l;
    scanf("%d",&n);
    f=0;z=0;
    while(n--)
    {
        scanf("%d",&i);
        if(i==0) z++;
        else f++;
    }

    if(z==0) printf("-1\n");
    else if((f==0)||(f/9==0)) printf("0\n");
    else if(f/9!=0)
    {
        f-=(f%9);
        while(f--) printf("5");
        while(z--) printf("0");
        printf("\n");
    }

    return 0;
}
