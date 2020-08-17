#include<stdio.h>

int main()
{
    long long int i=1,k,j=1,c=0;

    scanf("%lld",&k);

    while((k-c)!=0)
    {
        if(i==1)
        {
            j+=(2*9);
            i=0;
            c++;
        }
        else if((k-c)<9)
        {
            j+=(k-c)*9;
            c+=k-c;
        }
        else
        {
            j+=72;
            i=1;
            c+=8;
        }
    }

    printf("%lld\n",j);

    return 0;
}
