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

    int i,c=0;
    int a,b;

    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        if((b-a)>1)
        {
            c++;
        }
    }
    printf("%d\n",c);

    return 0;
}
