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
    int a[1000][1000],i,j,max=-1000,s=0;

    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {scanf("%d",&a[i][j]);}
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            s += a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1] + a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
            if(s>max) max =s;
            s=0;
        }
    }
    printf("%d\n",max);
    return 0;

}
