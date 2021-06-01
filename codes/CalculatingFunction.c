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


    unsigned long long int n,i,s;
    scanf("%llu",&n);


    if(n%2==0)
    {
        s=(n/2);
        printf("%llu\n",s);
    }

    else{
        s=1;
        s=s+(n/2);
        printf("-%llu\n",s);
    }


    return 0;


}
