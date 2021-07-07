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
#include<string.h>

int main()
{
	char a[20],b[20],c[20];
	scanf("%s %s %s", a, b, c);
	int al,bl,cl;
	al=strlen(a);
		bl=strlen(b);
			cl=strlen(c);

	if(a[al-1]==b[0] && b[bl-1]==c[0]) printf("YES");
	else printf("NO");
	printf("\n");
	return 0;
}
