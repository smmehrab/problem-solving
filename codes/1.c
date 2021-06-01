/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <stdio.h>
int main()
{
   int t,a,b,c=0,d;
   scanf("%d", &t);
   for(d=1; d<=t; d++)
   {
        scanf("%d%d", &a, &b);
        c=a+b;
        printf("Case %d: %d\n",d,c);
   }
   return 0;
}
