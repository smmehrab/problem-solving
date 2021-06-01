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
int main(){
	long long int x[1000001],temp,a,b,r[1000001],i,j,k,l,n;
	int T;
	scanf("%d",&T);

	while(T--)
    {

	scanf("%lld %lld",&a,&b);
    n=b-a+1;
	for(i=0;i<n;i++)
    {
        r[i]=0;
		scanf("%lld",&r[i]);
    }

    for(i=0;i<n-1;i++)
    {
		for(j=i+1;j<n;j++)
		{
			if(r[j]<r[i])
			{
				temp=r[i];
				r[i]=r[j];
				r[j]=temp;
            }

        }
    }

    for(i=0;i<n;i++) printf("%lld ",r[i]);

    i=0;
    for(l=a;l<=b;l++)
    {
        x[i]=l;
        i++;
    }

    for(i=0;i<n;i++)
    {
        if(x[i]!=r[i]) k=x[i];
    }

    printf("%lld\n",k);

    }
	return 0;

}
