#include<stdio.h>

int main()
{
    int n,i,j=0;
    char s[]="aabb";
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(n>j) printf("%c",s[j]);
        j++;
        if(j>3) j-=4;
    }
    printf("\n");
    return 0;
}
