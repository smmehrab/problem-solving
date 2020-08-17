#include<stdio.h>

int main()
{
    int i,j,k;
    char s[10000];
    i=0;
    while(1)
    {
        scanf("%c",&s[i]);
        if(s[i]=='\n') {printf("%c",s[i]);break;}
        else if(s[i]==' ') printf("\n");
        else printf("%c",s[i]);
        i++;
    }
    return 0;
}
