#include<stdio.h>

int gcd(int a,int b)
{
    if(b==0) {return a;}
    return gcd(b,(a%b));
}

int common_divisors(int a[],int m,int n,int gcdmn)
{
    int i,j=1;

    for(i=1;i<=gcdmn;i++)
    {
        if((m%i)==0 && (n%i)==0)
        {
            a[j]=i;
            j++;
        }

    }

    return (j-1);
}


int main()
{
    int t,i;
    int m,n,z,gcdmn;
    int a[1000];
    scanf("%d",&t);
    for(i=0;i<t;i++){

    scanf("%d %d",&m,&n);
    gcdmn = gcd(m,n);

    z =common_divisors(a,m,n,gcdmn);

    printf("%d\n",z);
    }

    return 0;




}
