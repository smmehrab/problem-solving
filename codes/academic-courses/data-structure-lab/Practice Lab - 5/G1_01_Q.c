#include<stdio.h>

int main()
{
    int n,d=1,i,j,m[100][100];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(m[i][j]!=m[j][i]) d=0;
        }
    }

    if(d==1) printf("Yes\n");
    else printf("No\n");

    return 0;
}


