#include<stdio.h>

int main()
{
    int x=0; char s[100];



    int n,i=0;
    scanf("%d",&n);

    for(i=0;i<=n;i++)

    {

        gets(s);

        if((s[0]=='X' && s[1]=='+' && s[2]=='+')||(s[0]=='+' && s[1]=='+' && s[2]=='X'))
        {
            x++;
        }
        if((s[0]=='X' && s[1]=='-' && s[2]=='-')||(s[0]=='-' && s[1]=='-' && s[2]=='X'))
        {
            x--;
        }


    }
    printf("%d\n",x);
    return 0;
}
