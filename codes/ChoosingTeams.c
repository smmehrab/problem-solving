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

    int n,k,s[2500],j=0,i;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        s[i]=s[i]+k;
        if(s[i]<=5)
        {
            j++;
        }

    }

    j=(j/3);

    printf("%d\n",j);
    return 0;


}
