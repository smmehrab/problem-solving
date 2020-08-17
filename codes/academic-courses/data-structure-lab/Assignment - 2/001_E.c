#include<stdio.h>

int main()
{
    int r1,c1,r2,c2,i,j,m1[100][100],m2[100][100],t[100][100]={0},k,l;
    char a;

    scanf("%d %d",&r1,&c1);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&m1[i][j]);
        }
    }

    scanf("%d %d",&r2,&c2);
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&m2[i][j]);
        }
    }

    getchar();
    printf("\nMenu:\nPress 1 to ADD\nPress 2 to SUBSTRACT\nPress 3 to MULTIPLICATION\nPress 0 to EXIT\n");
    scanf("%c",&a);
    if(a=='1')
    {
        if(r1!=r2 || c1!=c2) printf("INVALID ADDITION\n");
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                printf("%d",(m1[i][j]+m2[i][j]));
                if(j!=c1-1) printf(" ");
            }
            printf("\n");
        }
    }

    if(a=='2')
    {
        if(r1!=r2 || c1!=c2) printf("INVALID SUBTRACTION\n");
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                printf("%d",(m1[i][j]-m2[i][j]));
                if(j!=c1-1) printf(" ");
            }
            printf("\n");
        }
    }

    if(a=='3')
    {
        if(c1!=r2) printf("INVALID MULTIPLICATION\n");

        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                for(k=0;k<c1;k++)
                {
                    t[i][j]+=(m1[i][k]*m2[k][j]);
                }
            }
        }

        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                printf("%d",t[i][j]);
                if(j!=c2-1) printf(" ");
            }
            printf("\n");
        }
    }

    if(a=='0') return 0;

    return 0;
}

