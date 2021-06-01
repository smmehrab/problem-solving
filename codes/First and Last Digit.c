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
    int t,m,l;
    char n[10000];
    scanf("%d",&t);
    while(t--){
        scanf("%s", n);
        l=strlen(n);
        m= n[0]-'0' + n[l-1] - '0';
        printf("%d\n",m);
    }
    return 0;
}
