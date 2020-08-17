#include<stdio.h>
#include<string.h>

int main()
{
    char str[50];

    strcpy(str, "Memset application");
    puts(str);

    memset(str,'h',7);
    puts(str);

    return 0;
}
