#include<stdio.h>


int main()
{

    char s[100];
    gets(s);
    int i=0,c=0;

    while(s[i]!='\0')
    {
        if(s[i]=='H' ||s[i]=='Q' || s[i]=='9')
        {
            c=1;

        }
        i++;
    }
    if(c==1) printf("YES\n");
    else printf("NO\n");

    return 0;
}
