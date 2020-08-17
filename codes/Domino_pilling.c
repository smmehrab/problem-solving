#include<stdio.h>

int main()
{
    int n,m;
    int i=0,j=0;
    scanf("%d %d",&n,&m);



    if(n%2==0)
    {
        i=(n/2)*m;
        printf("%d\n",(i+j));
    }
        else {
        i=(n/2)*m;
        j=(m/2);

        printf("%d\n",(i+j));}


    return 0;
}
