#include<stdio.h>
#include<string.h>
int main()
{
    char s[100100],t[100100];
    gets(s);
    gets(t);
    int ls,lt,c,i,j;
    char a[10];
    c=0;
    ls=strlen(s);
    lt=strlen(t);
    if(lt!=ls) c=-100;
    else
    {
        for(i=0;i<ls;i++)
        {
            if(s[i]!=t[i])
            {
                c++;
                if(c>2)
                {
                    c=-100;
                    break;
                }
                a[c-1]=s[i];
                a[c+1]=t[i];

            }
        }
        if(c==2)
        {
            if(a[0]!=a[3] || a[1]!=a[2]) c=-100;
        }
        else c=-100;
    }
            if(c==-100) printf("NO\n");
        else printf("YES\n");
    return 0;
}
