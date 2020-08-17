#include<stdio.h>

int main()
{
    int c=0,n,i; char s[1000];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s", s);
        if(s[0]=='T') c+=4;
        else if(s[0]=='C') c+=6;
        else if(s[0]=='O') c+=8;
        else if(s[0]=='D') c+=12;
        else c+=20;
    }
    printf("%d\n",c);
    return 0;
}

