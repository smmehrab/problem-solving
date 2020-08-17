#include<stdio.h>

int main()
{
    char s[100];
    gets(s);
    int i=0,j,r,x;
    while(s[i]!='\0')
    {
        i++;
    }
    int n=i;


    x=0;

    for(i=0;i<n;i++)
    {

        for(j=i+1;j<n;j++)
        {
            if(s[i]==s[j])
            {
                s[j]='\0';

            }
        }

        if(s[i]!='\0')
        {
            x++;
        }

    }



    if((x%2)==1)
    {
        printf("IGNORE HIM!\n");
    }
    else
    {
        printf("CHAT WITH HER!\n");
    }

    return 0;
}
