#include<stdio.h>
#include<math.h>


int main()
{
    int n,i,j,k; char a[1000000];

    scanf("%d",&n);

    j=n;
    i=0;

    while(j!=0)
    {
        if((j%2)==0) a[i]='0';
        else a[i]='1';
        i++;
        j=j/2;
    }

    i--;
    k=0;

    for(;i>=0;i--)
    {
        if(a[i]=='1') {k+=pow(2,j);}
        j++;
    }

    printf("%d\n",k);
    return 0;
}
