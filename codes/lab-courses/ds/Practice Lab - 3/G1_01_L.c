/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<stdio.h>
#include<string.h>

int main()
{
    char y[190000],s[190000];
    long int n,k,m,i,j,v[190000],a,b,l;
    double dollar;

    scanf("%ld",&n);

    while(n--)
    {

        b=0;
        scanf("%ld",&k);

        for(i=0;i<k;i++)
        {scanf(" %c%ld\n",&y[i],&v[i]);}

        scanf("%ld\n",&m);

        for(i=0;i<m;i++)
        {
            gets(s);
            l=strlen(s);
            for(a=0;a<k;a++)
            {
                for(j=0;j<l;j++)
                {
                    if(s[j]==y[a]) {b+=v[a];}
                }
            }

        }
        dollar=(b/100.00);
        printf("%0.2lf$\n",dollar);
    }
    return 0;
}
