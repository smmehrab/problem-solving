#include<stdio.h>

int main()
{
    int n,t,j=0,k=0;
    char s[55],temp;

    scanf("%d %d",&n,&t);

    scanf("%s", s);

    k=0;

    while(k<t)
    {
        j=0;
        while(s[j+1]!='\0')
        {
            if(s[j]=='B' && s[j+1]=='G')
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                j=j+2;
            }
            else {j++;}
        }
        k++;
    }

    printf("%s",s);
    printf("\n");

    return 0;


}
