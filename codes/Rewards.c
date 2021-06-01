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

    int n,i,c,m;
    c=0;m=0;
    scanf("%d ",&i);
    c+=i;
    scanf("%d ",&i);
    c+=i;
    scanf("%d\n",&i);
    c+=i;
    scanf("%d ",&i);
    m+=i;
    scanf("%d ",&i);
    m+=i;
    scanf("%d\n",&i);
    m+=i;
    scanf("%d",&n);
    if(c%5!=0){c+=5-(c%5);}
    if(m%10!=0){m+=10-(m%10);}

    if(c>=m)
    {
        if(n-(c/5)>=(m/10)){printf("YES\n");}
        else{printf("NO\n");}
    }
    else
    {
        if(n-((m/10)+(m%10))>=((c/5)+(c%5))){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}
