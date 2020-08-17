#include<stdio.h>
#include<string.h>

int main()
{
    char a[100100],b[100100];
    int i,c,la,lb,l,l1,m;

    scanf("%s", a);
    scanf("%s", b);

    c=0;

    la=strlen(a);
    lb=strlen(b);

    if(la!=lb)
    {
        if(la>lb) c=la;
        else c=lb;
    }
    else if(la==lb)
    {
        for(i=0;i<la;i++)
        {
            if(a[i]==b[i]) c=0;
            else
            {
                c=la;
                break;
            }
        }
    }
    if(c==0) c=-1;

    printf("%d\n",c);
    return 0;
}


