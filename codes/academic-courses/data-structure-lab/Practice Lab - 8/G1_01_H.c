#include<stdio.h>

int main()
{
    char s[110];
    int i=1,c=0;
    gets(s);
    while(s[i]!='\0')
    {
        if(s[i]==s[i-1])
        {
            c++;
            if(c==6)
            {
                printf("YES\n");
                return 0;
            }
        }

        else{
            c=0;
        }
        i++;
    }


    printf("NO\n");
    return 0;
}
