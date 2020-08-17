#include<stdio.h>

int main()
{

    int n;
    scanf("%d",&n);

    while(n>5){


    if((n-5)%2!=0)
    {
    n=((n-5)/2)+1;}
    else
    {
        n=(n-5)/2;
    }}
    if(n==1)
    {
        printf("Sheldon");
    }
    else if(n==2)
    {
        printf("Leonard");
    }
    else if(n==3)
    {
        printf("Penny");
    }
    else if(n==4)
    {
        printf("Rajesh");
    }
    else if(n==5)
    {
        printf("Howard");
    }
    printf("\n");
    return 0;

}
