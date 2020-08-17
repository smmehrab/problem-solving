#include<stdio.h>

int main()
{
    char c;
    scanf("%c",&c);

    int x= (int) c;
    if(x<97)
    {
        x=x+32;
        char y = (char) x;

        printf("%c",y);
    }
    else
    {
        x=x-32;
        char y = (char) x;

        printf("%c",y);
    }
    return 0;
}
