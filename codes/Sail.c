#include<stdio.h>

int main()
{
    long long int t,sx,sy,ex,ey,i,j,k,l,m,n,c;
    char s[200000],temp;
    scanf("%lld %lld %lld %lld %lld",&t,&sx,&sy,&ex,&ey);
    i=sx; j=sy; c=0;
    scanf("%c%s",&temp, s);

    for(k=0;k<t;k++)
    {
        if(s[k]=='N' && j!=ey)
        {if(ey>j) j++;}

        else if(s[k]=='E'&&i!=ex)
        {if(ex>i) i++;}

        else if(s[k]=='S'&&j!=ey)
        {if(ey<j) j--;}

        else if(s[k]=='W'&&i!=ex)
        {if(ex<i) i--;}

        if(i!=ex||j!=ey) c++;
        else break;
    }
    if(i==ex && j==ey) printf("%lld\n",++c);
    else printf("-1\n");
    return 0;

}
