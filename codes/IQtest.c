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

    int n,i=1,s[110],e=0,o=0;
    scanf("%d",&n);
    while(i<=n)
    {
        scanf("%d",&s[i]);
        if(s[i]%2==0)
        {
            e++;
        }
        else
        {
            o++;
        }
        i++;
    }
    i=1;
    if(o==1)
    {

        while(i<=n)
        {
            if(s[i]%2==1)
            {
                break;
            }
            i++;
        }
    }
    else if(e==1)
    {

        while(i<=n)
        {
            if(s[i]%2==0)
            {
                break;
            }
            i++;
        }
    }

    printf("%d\n",i);
    return 0;
}
