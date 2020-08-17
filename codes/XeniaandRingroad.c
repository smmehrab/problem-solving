#include<stdio.h>

int main()
{

    unsigned long long n,m,y,i,h=0,x=1;
    scanf("%llu %llu",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%llu",&y);

            if(y<x)
            {
                h=h+y+n-x;
            }
            else {
                h=h+y-x;
            }


        x=y;


    }

    printf("%llu\n",h);
    return 0;

}
