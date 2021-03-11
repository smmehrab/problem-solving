#include<stdio.h>
int main()
{
    int m,n,i,j,k,l,a[100][100];

    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++) {scanf("%d",&a[i][j]);}
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",a[i][n-j-1]);
            if(j!=n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
