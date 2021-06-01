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
    long long int g,s;

    scanf("%lld %lld",&s,&g);

    if(s%g==0 && s>g) printf("%lld %lld\n",g,s-g);

    else printf("-1\n");

	return 0;
}
