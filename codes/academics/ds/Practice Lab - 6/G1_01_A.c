#include<stdio.h>
#include<string.h>

int main()
{
    char s[200],temp;
    int i,j,k,l,u;
    scanf("%s%c", s,&temp);
    j=strlen(s);
    i=0;l=0;u=0;
    while(i<j)
    {
        if(s[i]>='a') l++;
        else u++;
        i++;
    }

    if(u>l)
    {
        i=0;
        while(s[i]!='\0')
        {
            if(s[i]>='a') s[i]-=32;
            i++;
        }
    }
    else
    {
        i=0;
        while(s[i]!='\0')
        {
            if(s[i]<'a') s[i]+=32;
            i++;
        }
    }
    printf("%s\n", s);
    return 0;

}
