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
    struct student
    {
        int id;
        //char* name;
        char name[40];
    };

    struct student one;

    one.id=1;
    //one.name="Mehrab";
    strcpy(one.name, "Mehrab");

    printf("ID: %d\n", one.id);
    printf("Name: %s\n", one.name);

    return 0;
}
