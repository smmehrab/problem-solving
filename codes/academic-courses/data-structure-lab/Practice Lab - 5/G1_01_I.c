#include<stdio.h>

int main()
{
    int r,c,i,j,m[100][100];

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",m[i][j]);
            if(j!=r-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
