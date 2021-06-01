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

    int n,x,c=1,y;
    scanf("%d",&n);
    int i=0;

    while(i<n)
    {
        scanf("%d",&x);
        if(i!=0)
        {
            if(x!=y)
            {
                c++;
            }
        }
        y=x;
        i++;

    }

    printf("%d\n",c);
    return 0;

}
