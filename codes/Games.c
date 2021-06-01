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

    int n,i,j,c;
    int h[110],a[110];

    scanf("%d",&n);

    i=0;
    while(i<n)
    {
        scanf("%d %d",&h[i],&a[i]);
        i++;
    }

    i=0;c=0;

    while(i<n)
    {
        j=0;
        while(j<n)
        {
            if(h[i]==a[j])
            {
                c++;
            }
            j++;
        }
        i++;
    }
    printf("%d\n",c);
    return 0;

}
