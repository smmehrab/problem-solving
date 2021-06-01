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

    int i=1,j=1,t=0,h=0;


   while(t<n){

        j=1;
        while(j<=i)
        {
                t=t+j;
                j++;

        }

        if(t<=n)
        {h++;}

        i++;


    }

    printf("%d\n",h);
    return 0;

}
