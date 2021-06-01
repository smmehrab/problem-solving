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
#include<string.h>

struct nametype
{
    char first[20];
    char last[20];
};


struct student
{
    int id;
    struct nametype name;
};


int main()
{
    struct student one;

    scanf("%d\n",&one.id);
    scanf("%s\n",&one.name.first);
    scanf("%s",&one.name.last);

    printf("\n\nID: %d\n",one.id);
    printf("Full Name: %s %s\n",one.name.first,one.name.last);


    return 0;

}
