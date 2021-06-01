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

    int s[12]={4,7,47,74,444,447,474,477,744,747,774,777};
    int n,i,c=0;
    scanf("%d",&n);

    for(i=0;i<12;i++)
    {
        if(n%s[i]==0)
        {
            c=1;

        }

    }
    if(c==1)
    {
        printf("YES\n");

    }
    else{
        printf("NO\n");
    }

    return 0;


}
