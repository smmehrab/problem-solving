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

    unsigned long long n,k,i,j=1;
    scanf("%llu %llu",&n,&k);

    if(n%2==0)
    {
         if(k>(n/2))
        {
            k=k-(n/2);
            k=(2*k);
        }
        else
        {
            k=(2*k)-1;
        }
    }
    else
    {

        if(k>(n/2)+1)
        {
            k=k-(n/2)-1;
            k=(2*k);
        }
        else
        {
            k=(2*k)-1;
        }
    }


  printf("%llu\n",k);
  return 0;



}
