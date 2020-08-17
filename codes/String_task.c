#include<stdio.h>

int main()
{
    char s[200];int i=0;
    gets(s); int n=0;
    while(s[i]!='\0')
    {
        n++;
        i++;
    }

    for(i=0;i<n;i++)

    {

        if(s[i]<'a')

        {

            s[i]= s[i] + 32;

        }
        if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='y')
        {
            printf(".");
            printf("%c",s[i]);
        }

    }

    printf("\n");
    return 0;


}
