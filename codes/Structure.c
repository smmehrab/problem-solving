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
