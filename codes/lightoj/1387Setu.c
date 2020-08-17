#include<stdio.h>
#include<string.h>

int main()
{
    int t,d,i,j,k,n;
    char temp[10],demo[10]="donate";


    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        printf("Case %d:\n",i+1);

        scanf("%d",&n);

        d=0;

        for(j=0;j<n;j++)
        {
            scanf("%s", temp);

            if(strcmp(temp,demo)==0)
            {
                scanf("%d",&k);
                d+=k;
            }
            else
            {
                printf("%d\n",d);
            }
        }
    }
    return 0;
}
