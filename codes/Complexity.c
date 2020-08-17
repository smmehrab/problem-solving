#include<stdio.h>
#include<string.h>

int main()
{
    char s[1000];
    int c[30]={0},complexity=0,l,i,j;
    scanf("%s",s);
    l=strlen(s);
    for(i=0;i<l;i++)
    {
        j=s[i]-'a';
        if(c[j]==0) complexity++;
        c[j]++;
    }
    if(complexity>2) printf("%d\n",complexity-2);
    else printf("0\n");
    return 0;
}



