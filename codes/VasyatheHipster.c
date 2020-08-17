#include<stdio.h>

int main()
{

    int r,b,fashion,survive;

    scanf("%d %d",&r,&b);

    if(r<=b)
    {
        fashion=r;
        survive=(b-r)/2;
    }
    else
    {
        fashion=b;
        survive= (r-b)/2;
    }
    printf("%d %d\n",fashion,survive);
    return 0;


}
