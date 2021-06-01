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
void poly(int i,int n)
{
    if(i<n){
        if(i==0) printf("1");
        else {
            printf(" + x");
            if(i>1){
                printf("^%d",i);
            }

        }poly(i+1,n);
    }
}


int main()
{

    int n,i;
    scanf("%d",&n);

    poly(0,n);
    printf("\n");
    return 0;
}
