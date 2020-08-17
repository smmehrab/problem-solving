#include<stdio.h>
int aladanaki(char s[])
{
    int i=0,j=0;
    while(s[i]!='\0')
    {
        j=i+1;
        while(s[j]!='\0')
        {
            if(s[i]==s[j]) return 0;

            j++;
        }
        i++;

    }
    return 1;
}


int main()
{
    char s[5];
    int n,x;
    scanf("%d",&n);
    n++;

    while(1)
    {
        sprintf(s,"%d",n);
        x=aladanaki(s);
        if(x==1)
        {
            printf("%s\n", s);
             return 0;
        }
        else n++;

    }

}
