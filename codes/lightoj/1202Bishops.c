#include<stdio.h>
int abs(int n)
{
    if(n<0) n*=-1;
    return n;
}
int main()
{
    int r1,c1,r2,c2,m=0,t,cs=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        printf("Case %d: ",++cs);
        if(((r1+c1)%2) != ((r2+c2)%2)) printf("impossible\n");
        else if(abs(r1-r2)==abs(c1-c2)) printf("1\n");
        else printf("2\n");
    }
    return 0;
}
