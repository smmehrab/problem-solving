#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    if(n<0)
    {
        printf("The integer isn't positive\n");
    }

    int hun,ten,one;

    hun = n/100;
    n=n%100;
    ten = n/10;
    n=n%10;
    one=n;

    if(hun>9 || hun == 0)
    {
        printf("The integer doesn't have 3 digits\n");

    }

    else
    {


        int x= hun + ten + one;
        printf("%d\n",x);
    }
    return 0;
}
