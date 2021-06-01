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

    int n;
    scanf("%d",&n);

    int a[100100],i,p=0,c=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>0)
        {
            p+=a[i];
        }
        else
        {
            if(p<=0)
            {
                c++;
            }
            else
            {
                p--;
            }

        }
    }
    printf("%d\n",c);
    return 0;
}
