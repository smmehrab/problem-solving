#include<stdio.h>
int toggle(int n)
{
    if(n==1) return 0;
    if(n==0) return 1;
}

int main()
{
    int b[10][10],i,j,k;

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            b[i][j]=1;
        }
    }

    for(i=4;i<7;i++)
    {
        for(j=4;j<7;j++)
        {
            scanf("%d",&k);
            k=k%2;
            if(k!=0)
            {
                b[i][j]=toggle(b[i][j]);
                b[i][j+1]=toggle(b[i][j+1]);
                b[i+1][j]=toggle(b[i+1][j]);
                b[i][j-1]=toggle(b[i][j-1]);
                b[i-1][j]=toggle(b[i-1][j]);
            }
        }
    }

    for(i=4;i<7;i++)
    {
        for(j=4;j<7;j++)
        {
            printf("%d",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
