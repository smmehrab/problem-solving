#include<stdio.h>
#include<string.h>

int main()
{

    char a[110];
    int i,j,n;

    scanf("%d",&n);

    i=0;
    while(i<=n)
    {
        j=0;
        gets(a);
        j=strlen(a);
        if(j>10)
        {
            printf("%c%d%c\n",a[0],j-2,a[j-1]);
        }
        else
        {
            puts(a);
        }

        i++;
    }
    return 0;
}
