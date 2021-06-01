/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <stdio.h> #include <string.h> #include <math.h>

void makeString(char s[], int n)
{
    int i,r,l,m;

    l=0;
    m=n;

    while (m!=0)
    {
        l++;
        m/=10;
    }

    for(i=0;i<l;i++)
    {
        r=n%10;
        n/=10;
        s[l-1-i]=r+'0';
    }

    s[l]='\0';
}

int makeInt(char s[])
{
    int i,n,l;

    n=0;
    l=strlen(s);

    for (i=0;i<l;i++)
    {
        n+=((s[l-1-i]-'0')*pow(10,i));
    }

    return n;
}

int main()
{
    char s[10];
    int n,r;

    printf("Enter a number: ");
    scanf("%d",&n);
    makeString(s, n);
    printf("Number converted to string: %s\n", s);
    r=makeInt(s);
    printf("Number converted back to integer: %d\n", r);

    return 0;
}
