#include<stdio.h>
int main()
{
    int a[5][5]={{25,24,23,22,21},{10,11,12,13,20},{9,8,7,14,19},{2,3,6,15,18},{1,4,5,16,17}};



int i,j,k;
    int t;
    scanf("%d",&t);
    int s[t];


    for(i=0;i<t;i++)
    {
    scanf("%d",&s[i]);

    }
    for(i=0;i<t;i++){
    for(k=0;k<5;k++)
    {
        for(j=0;j<5;j++)
        {
            if(a[k][j]==s[i])
            {
            printf("Case %d: %d %d\n",i+1,j+1,5-k);
            }
        }

    }

    }

    return 0;


}
