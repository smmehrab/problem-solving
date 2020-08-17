#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[110];
    int c[26],i,t;

    memset(c, 0, 26*sizeof(c[0]));

    gets(s);
    i=0;
    while(s[i]!='\0')
    {
        t=s[i] - 'a';
        c[t]++;
        i++;
    }

    for(i=0;i<26;i++)
    {
        if(c[i]%2!=0)
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;


}
