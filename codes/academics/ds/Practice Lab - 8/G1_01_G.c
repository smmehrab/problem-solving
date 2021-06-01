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
	int n,r=0,i,j,k,c;
	scanf("%d",&n);
	if(n<105) r=0;
	else if(n==105) r=1;
	else
	{
		r=1;
		for(i=107;i<=n;i+=2)
		{
			c=0;
			for(j=1;j*j<i;j++)
			{
				if(j*j==i) c+=1;
				else if(i%j==0) c+=2;
			}
			if(c==8) r++;
		}
	}
	printf("%d\n",r);
	return 0;
}
