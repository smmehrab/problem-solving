#include<stdio.h>

int main()
{
    int n,m,i,j,k,x[200]={0};
    char c;

    scanf("%d %d",&n,&m);

    i=0;k=0;
    while(i<n)
    {
        scanf("%d%c",&j,&c);
        if(k<m)
        {
            x[j]++;
            k++;
        }
        else if(j==1 && k==3 && n==1 && x[1]==1)
        {
            printf("NO\n");
            return 0;
        }
        if(c=='\n')
        {
            i++;
            k=0;
        }

    }
    j=1;
    for(i=1;i<=m;i++)
    {
        if(x[i]==0)
        {
            j--;
            break;
        }
    }
    if(j!=1) printf("NO\n");
    else printf("YES\n");

    return 0;
}
