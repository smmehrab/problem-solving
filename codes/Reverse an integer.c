/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <stdio.h>
int main()
{
    int n, reversedNumber = 0, remainder;

    printf("Enter an integer: ");
    scanf("%d", &n);

    while(n!=0)
    {
        remainder = n%10;
        reversedNumber*=10;
        reversedNumber+= remainder;
        n/=10;
    }

    printf("Reversed Number = %d", reversedNumber);

    return 0;
}
