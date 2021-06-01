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
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    while (a||b||c||d)
    {
        printf("%d\n", 1080+((a- b+40)%40+(c-b+40)%40+(c-d+40)%40)*9);
        scanf("%d %d %d %d",&a,&b,&c,&d);
    }
    return 0;
}
