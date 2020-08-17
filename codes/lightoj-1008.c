#include <stdio.h>

int main()
{
    int N;

    scanf("%d",&N);
    int a[N][N];



    int i,j,k,c=1;

    for(i=1;i<=N;i++)
    {


            for(j=1;j<=i;j++)
            {
                a[i][j]=c;
                c++;
                if(j==i)
                {
                    for(i=j;i>=1;i--)
                    {
                        a[i][j]=c;
                        c++;
                    }
                }
            }

    }
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            printf("%d",a[i][j]);
            printf("\n");
        }
        printf("t");
    }


    return 0;
}
