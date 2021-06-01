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

struct student{
    int id;
    char name[40];


};


int main()
{
    struct student one;

    scanf("%d", &one.id);
    scanf("%s", one.name);

    printf("ID: %d\n", one.id);
    printf("Name: %s\n", one.name); // But will only show the first name because we have used %s inside the scanf function
    // We can use %[^\n] to solve this problem
    return 0;
}
