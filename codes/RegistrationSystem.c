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
#include<stdlib.h>

int main()
{

    long long int n,i,j,x,l[35]={0},d;
    char* a[100100];

    scanf("%lld",&n);

    i=0;
    while(i<n)
    {
        a[i]=(char*) malloc(35);
        scanf("%s", a[i]);

        d=strlen(a[i]);
        l[d]++;

        if(i==0){printf("OK\n");}

        else if(l[d]==1) {printf("OK\n");}

        else
        {
                j=i-1;
                x=0;

                while(j>=0)
                {
                    if(strlen(a[i])==strlen(a[j]))
                    {
                        if(strcmp(a[i],a[j])==0) x++;
                    }
                    j--;
                }

                if(x==0){printf("OK\n");}
                else {printf("%s%lld\n", a[i],x);}
        }
        i++;
    }

    return 0;
}
