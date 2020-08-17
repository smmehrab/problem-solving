#include<stdio.h>

int main()
{

    int n,i=0,j=0,x,y,z;
    char c[1010],l[1010];

    scanf("%d\n",&n);

    gets(c);
    gets(l);

    while(i<n)
    {
        x=c[i]-'0';
        y=l[i]-'0';
        if(x>=y)
        {
            z=x-y;
            if(z<(10-z))
            {
                j=j+z;
            }
            else {j=j+10-z;}
        }
        else
        {
            z=y-x;
            if(z<(10-z))
            {
                j=j+z;
            }
            else {j=j+10-z;}
        }
        i++;
    }

    printf("%d\n",j);
    return 0;
}
