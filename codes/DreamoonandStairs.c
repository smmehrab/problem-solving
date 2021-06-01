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

    int n,m,j,mv;
    scanf("%d %d",&n,&m);

    if(n<m){mv=-1;}
    else if(n%2==0)
    {
        mv=(n/2);
        while((mv)%m!=0){mv++;}
    }
    else
    {
        mv=(n/2)+1;
        while((mv)%m!=0){mv++;}
    }
    printf("%d\n",mv);
    return 0;

}
