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
    char s[2000000];int n,i=0,o=0,z=0;scanf("%d\n",&n);gets(s);
    while(i<n){if(s[i]=='1'){o++;}else if(s[i]=='0'){z++;}i++;}
    if(o>=z){o=o-z;printf("%d\n",o);}
    else{z=z-o;printf("%d\n",z);}return 0;
}
