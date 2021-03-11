#include<stdio.h>

int main()
{
    int h,m;
    scanf("%d %d",&h,&m);

    if(h<6)
    {
        printf("Night\n");
    }
    else if(h<12)
    {
        printf("Morning\n");
    }
    else if(h<18)
    {
        printf("Afternoon\n");
    }
    else
    {
        printf("Evening\n");
    }

    return 0;
}
