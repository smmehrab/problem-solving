#include<stdio.h>

int main()
{
    int k,n,w;
    scanf("%d %d %d",&k,&n,&w);
    int cost=0,neededMoney;
    int i;

    for(i=1;i<=w;i++)
    {
        cost=cost + (i*k);

    }

    neededMoney= cost - n;
    if(neededMoney<0)
    {
        neededMoney=0;
    }
    printf("%d\n",neededMoney);
    return 0;
}
