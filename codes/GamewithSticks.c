#include<stdio.h>

int main()
{

    int n,m;
    scanf("%d %d",&n,&m);

    int i,j=1;
    if(n==1 || m==1)
    {
        printf("Akshat\n");
    }
    else if(n%2==0 && m%2==0)
    {
        printf("Malvika\n");
    }
    else if(n%2==1 && m%2==1)
    {
        printf("Akshat\n");
    }
    else
    {
        for(i=(n+m);i>=0;i=i-2)
        {
            if(i==1 || i==0)
            {
                break;
            }
            j++;
        }
        if(j%2==0)
        {
            printf("Akshat\n");
        }
        else
        {
            printf("Malvika\n");
        }
    }

    return 0;
}
