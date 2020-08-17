#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int a[1010],i=0,imin,imax,c=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i==0)
        {
            imin=a[0];
            imax=a[0];
        }
        else
        {
            if(a[i]>imax)
            {
                c++;
                imax=a[i];
            }
            if(a[i]<imin)
            {
                c++;
                imin=a[i];
            }
        }

    }
    printf("%d\n",c);
    return 0;

}
