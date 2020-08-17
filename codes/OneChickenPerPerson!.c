#include<stdio.h>

int main()
{
    int n,m,p;
    scanf("%d %d",&n,&m);

    if(n>m)
    {
        p=n-m;
        if(p==1)
        {
            printf("Dr. Chaz needs %d more piece of chicken!\n",p);
        }
        else {printf("Dr. Chaz needs %d more pieces of chicken!\n",p);}

    }
    else if(n<m)
    {
        p=m-n;
        if(p==1)
        {
            printf("Dr. Chaz will have %d piece of chicken left over!\n",p);
        }
        else {printf("Dr. Chaz will have %d pieces of chicken left over!\n",p);}
    }
    return 0;
}
