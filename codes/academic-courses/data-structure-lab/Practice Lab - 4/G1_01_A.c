#include<stdio.h>

int main()
{
    int t,i,a,b,n,j,tmp;

    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        scanf("%d %d",&a,&b);
        n=(b-a+1);
        int s[n+10];
        for(j=0;j<n+10;j++)
        {s[j]=0;}

        for(j=0;j<n;j++)
        {
            scanf("%d",&tmp);
            s[tmp-a]++;
        }

        for(j=0;j<n;j++)
        {
            if(s[j]==0)
            {
                printf("%d\n",(j+a));
                break;
            }
        }
    }
    return 0;
}
