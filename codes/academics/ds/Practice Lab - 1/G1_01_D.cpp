#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int i,max,t;

    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(i==0)
        {
            max=t;
        }
        else if(t>max)
        {
            max=t;
        }
    }

    printf("%d\n",max);
    return 0;
}
