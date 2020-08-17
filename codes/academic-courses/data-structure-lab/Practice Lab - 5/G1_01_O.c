#include<stdio.h>

int main()
{
    int r,c,i,j,m[100][100],max,x,y;
    scanf("%d %d",&r,&c);

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&m[i][j]);

                if(i==0 && j==0)
                {
                    max=m[i][j];
                    x=i;
                    y=j;
                }

                if(max<m[i][j])
                {
                    max=m[i][j];
                    x=i;
                    y=j;
                }
        }
    }

    printf("Max: %d\nLocation: [%d][%d]\n",max,x,y);
    return 0;
}

