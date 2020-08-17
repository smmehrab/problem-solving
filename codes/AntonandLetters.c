#include<stdio.h>


int main()
{


    char s[1010],n[1010];
    int i,j,l,x,c;

    gets(s);

    if(s[0]=='{'&&s[1]=='}')
    {
        printf("0\n");
    }

    else
    {
            i=1;j=0;
            while(s[i]!='}')
            {
                if(s[i]!=',' && s[i]!=' ')
                {
                    n[j]=s[i];
                    j++;
                }
                i++;
            }

            l=j;
            x=1;
            i=0;

            while(i<l-1)
            {
                c=1;
                j=i+1;
                while(j<l)
                {
                    if(n[i]==n[j])
                    {
                        c=0;
                    }
                    j++;
                }
                x+=c;
                i++;
            }

            printf("%d\n",x);
    }

    return 0;
}
