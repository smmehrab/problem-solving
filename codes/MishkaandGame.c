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
    int m=0,c=0,n,x,y,i;
    scanf("%d",&n);
    i=0;
    while(i<n)
    {
        scanf("%d %d",&x,&y);
        if(x>y){m++;}
        else if(y>x){c++;}
        i++;
    }
    if(m==c){printf("Friendship is magic!^^\n");}
    else if(m>c){printf("Mishka\n");}
    else if(c>m){printf("Chris\n");}

    return 0;

}
