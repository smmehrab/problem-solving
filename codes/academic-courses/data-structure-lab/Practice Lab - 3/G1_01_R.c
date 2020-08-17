#include<stdio.h>
int digsum(int d)
{
    int k;
    if(d<10) return d;

    k=(d/100);
    d=d%100;
    k+=(d/10)+(d%10);

    if(k>9) return digsum(k);
    else return k;

}
int main()
{
    char s[100];
    int i,d;
    while(1)
    {
        scanf("%s", s);
        if(s[0]=='0') break;
        i=0;
        d=0;
        while(s[i]!='\0')
        {
            d+=s[i]-'0';
            i++;
        }

        i=digsum(d);
        printf("%d\n",i);
    }
    return 0;
}
