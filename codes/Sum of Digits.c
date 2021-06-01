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
int c=0;
int digsum(int d)
{

    int k;
    if(d<10) return d;
    c++;
    k=(d/1000000);
    d=d%1000000;
    k+=(d/100000);
    d=d%100000;
    k+=(d/10000);
    d=d%10000;
    k+=(d/1000);
    d=d%1000;
    k+=(d/100);
    d=d%100;
    k+=(d/10)+(d%10);

    if(k>9) return digsum(k);
    else return k;

}
int main()
{
    c=0;
    char s[100000];
    int i,d;

        scanf("%s", s);
        i=0;
        d=0;
        if(s[1]!='\0')
        {
            while(s[i]!='\0')
            {
                d+=s[i]-'0';
                i++;
            }
            c++;
            i=digsum(d);
        }
        printf("%d\n",c);

    return 0;
}
