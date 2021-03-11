#include<stdio.h>

int main()
{

    char s[200];
    int i=0;

    gets(s);

    while(s[i]!='\0')
    {
        if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
        {
            if(i==0)
            {
                s[i]= '#';
            }
            else
            {s[i]=' ';}
            s[i+1]= '#';
            s[i+2]= '#';
            i=i+3;

        }
        else
        {
            i++;
        }
    }

    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!='#')
        {printf("%c",s[i]);}

        else{
                continue;
        }

    }
    printf("\n");



    return 0;
}
