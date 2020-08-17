#include<stdio.h>

int main()
{
    while(1){
    int i,n,t,a[100000],m=1,x=1,c=0;
    scanf("%d %d",&n,&t);
    i=1;
    for(i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        if((a[i]+i)>=m){
        m=m+a[i]+i;
        if(m==t){c=1;}}
    }
    if(c==1)
    {printf("YES\n");}

    else printf("NO\n");

    }return 0;
}
