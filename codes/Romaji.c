#include<stdio.h>

int main()
{
    int i;
    char s[1000];
    gets(s);
    i=0;
    while(s[i]!=0)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
        {i++;}
        else
        {
            if(s[i+1]!='a' &&s[i+1]!='e' &&s[i+1]!='i' &&s[i+1]!='o' &&s[i+1]!='u' && s[i]!='n')
            {
                printf("NO\n");
                return 0;
            }
            i++;
        }
    }
    printf("YES\n");
    return 0;
}
