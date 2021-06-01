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

void reverseSentence()
{
    char c;
    scanf("%c",&c);
    if(c!='\n')
    {
        reverseSentence();
        printf("%c",c);
    }
}

int main()
{
    printf("Enter a sentence to reverse:\n");
    reverseSentence();
    printf("\n");
    return 0;
}
