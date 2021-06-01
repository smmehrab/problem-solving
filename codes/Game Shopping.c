/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<stdio.h>

int main()
{
    int n,m,i,j=0,a[1100],c[1100],b=0;
    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++)
    {
        if(i==n-1)
        {
            scanf("%d\n",&c[i]);
        }
        else
        {
            scanf("%d ",&c[i]);
        }
    }
    for(i=0;i<m;i++)
    {
        if(i==m-1)
        {
            scanf("%d",&a[i]);
        }
        else
        {
            scanf("%d ",&a[i]);
        }
    }

    for(i=0;i<n;i++)
    {
            if(a[j]>=c[i])
            {
                b++;
                j++;
                if(j>m-1)
                {
                     break;
                }
            }
    }

    printf("%d\n",b);
    return 0;
}
