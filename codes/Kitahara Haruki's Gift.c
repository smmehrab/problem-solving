#include<stdio.h>

int main()
{
    int n,t=0,o=0,i;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&i);
        if(i==100) o++;
        else t++;
    }

    if((o%2==0 && o!=0)||(o==0 && t%2==0)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
