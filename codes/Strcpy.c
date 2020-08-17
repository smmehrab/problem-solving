#include<stdio.h>
#include<string.h>

int main()
{
    char src[40],dest[100];
    memset(dest,'\0',sizeof(dest));
    strcpy(src, "strcpy application");
    strcpy(dest, src);

    printf("%s\n",dest);

    return 0;
}
