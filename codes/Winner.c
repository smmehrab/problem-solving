#include<stdio.h>
#include<string.h>

int main()
{
    int n,t,sa=0,sb=0,i,j,k=1;
    char s[100000],s1[100000],s2[100000];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s %d", s,&t);

        if(k==1)
        {
            strcpy(s1,s);
            k--;
        }

        else if(strcmp(s,s1)!=0 && k!=-1)
        {
            strcpy(s2,s);
            k=-1;
        }

        if(strcmp(s,s1)==0)
        {
            sa+=t;
        }

        else
        {
            sb+=t;
        }
    }
    if(sa>sb) puts(s1);
    else if(sb>sa) puts(s2);
    else
    {
        if(strcmp(s,s1)==0 && t>0) puts(s2);
        else if(strcmp(s,s1)==0 && t<0) puts(s1);
        else if(strcmp(s,s2)==0 && t>0) puts(s1);
        else if(strcmp(s,s2)==0 && t<0) puts(s2);
    }
    return 0;

}
