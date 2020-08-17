#include<stdio.h>

int main()
{
    char i='a',s[120];
    int j,k,l;

    gets(s);

    j=0;k=0;
    while(s[j]!='\0')
    {
        if(s[j]>i) l=(int) s[j]- (int) i;
        else l=(int) i- (int) s[j];

        if(l>26-l) k+=26-l;
        else k+=l;
        i=s[j];
        j++;
    }
    printf("%d\n",k);
    return 0;
}
