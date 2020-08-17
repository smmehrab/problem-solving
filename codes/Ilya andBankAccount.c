#include<stdio.h>
#include<string.h>
int main()
{

    char s[20];
    scanf("%s", s);
    int l,i=0;
    l=strlen(s);
    if(s[0]!='-')
    {
        printf("%s",s);

    }
    else if(l==2)
    {
        printf("0");
    }

    else
    {


        if(s[l-1]>=s[l-2])
        {
            s[l-1]='a';

        }
        else
        {
            s[l-2]='a';
            if(s[l-3]=='-' && s[l-1]=='0')
            {
                s[l-3]='a';
            }
        }
        while(s[i]!='\0')
        {
            if(s[i]!='a'){
            printf("%c",s[i]);}
            i++;
        }
    }
    printf("\n");
    return 0;
}
