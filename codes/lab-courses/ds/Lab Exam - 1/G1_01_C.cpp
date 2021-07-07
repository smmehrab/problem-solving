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
    unsigned long long int n,c=0;
    scanf("%llu",&n);
    
    while(n!=0)
    {
		n/=2;
		c++;
    }
	printf("%llu\n",c-1);
	return 0;

}
