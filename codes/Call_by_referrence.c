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

void plus_ten1(int a)
{
    a=a+10;

}
void plus_ten2(int* a)
{
    (*a)=(*a)+10;
}

int main()
{
    int a=5;
    plus_ten1(a);
    printf("a = %d\n",a);
    plus_ten2(&a); // giving the referrence address to the function
    printf("a = %d\n",a);
    return 0;
}
