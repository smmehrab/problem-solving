#include<stdio.h>

int main()
{
    int r,c,i,j,m[100][100];
    scanf("%d %d",&r,&c);

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }

    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d",m[j][i]);
            if(j!=r-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
