#include<stdio.h>

int main()
{

    int n;char s[100],t;int i=0,x=0;
    scanf("%d\n",&n);
    gets(s);


    while(s[i+1]!='\0')
    {
        if(s[i]==s[i+1])
        {

            int j=i+1;s[j]='\0';

            while(j<n-1)
            {
                 t=s[j];s[j]=s[j+1];s[j+1]=t;

                j++;

            }

            x++;
        }

        if(s[i]!=s[i+1]){
        i++;}


    }
    printf("%d\n",x);
    return 0;
}
