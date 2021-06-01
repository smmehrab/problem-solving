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
    int n,a[100000],e=0,o=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a[n]);
        if(a[n]%2) o++;
        else e++;
    }
    if(e>o) printf("READY FOR BATTLE");
    else printf("NOT READY");
    printf("\n");
    return 0;
}
