#include<stdio.h>

int main()
{

    int n;
    scanf("%d",&n);

    int x=(n/2);
    if( (n%2==0) && n!=2 && n!=0 )
    {
        printf("Yes\n");
    }
    else printf("No\n");

    return 0;
}
