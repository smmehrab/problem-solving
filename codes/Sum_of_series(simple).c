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
int n;
int series(int n)
{
    if(n==0)
    {
        int main();
    }
    else

    return (n*n) + series(n-1);
}

int main()
{
    printf("Enter the integer : \n");
    scanf("%d",&n);

    printf("=%d",series(n));

    return 0;

}
