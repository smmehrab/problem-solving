#include<stdio.h>

int main()
{


    while(1){
    int n,m,ot,mt,r;
    scanf("%d %d %d %d",&n,&m,&ot,&mt);

    if((m*ot)>=mt)
    {
        r=((n/m)*mt);
        if(((n%m)*ot)<=mt)
        {
            r=r+((n%m)*ot);

        }
        else
        {
            r=r+mt;
        }
    }
    else
    {
        r=(n*ot);
    }
    printf("%d\n",r);}
    return 0;

}
