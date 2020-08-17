#include<stdio.h>
#include<math.h>


int main()
{
    unsigned long long int n,i,j,a[100000],d;
    scanf("%llu",&n);
    for(i=0;n!=0;i++)
    {
        a[i]=n%2;
        printf("%d ",a[i]);
        n=n/2;
        i++;
    }

    i--; d=0;printf("\n");

    for(j=0;j<=i;j++)
    {
        if(a[i-j]==1)
        {
            d+= pow(2,j);
            printf("%d ",d);
        }
    }

    printf("%d\n",d);

    return 0;

}
