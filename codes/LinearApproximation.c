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
#include<stdlib.h>


int main()
{
	unsigned long long a[200000],y,n,i;
	y=0;
	scanf("%llu",&n);
	for(i=0;i<n;i++)
    {
        scanf("%llu",&a[i]);
        y+=abs(a[i]-i-1);
    }

	printf("%llu\n",y);
	return 0;
}
