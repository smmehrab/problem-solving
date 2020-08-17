#include<stdio.h>

int gcd(int x,int y)
{
    if(y==0) {return x;}
    else {return gcd(y,(x%y));}
}


int main()
{
    while(1){
    int a,b,n,igcd;
    scanf("%d %d %d",&a,&b,&n);
    int i=0,c;

    igcd=gcd(n,a);

    while(n>=igcd)
    {
        if(i%2==0)
        {

            //printf("%d %d\n",n,igcd);
            n=n-igcd;
            igcd=gcd(n,b);
            c=i%2;
        }

        else
        {
            //printf("%d %d\n",n,igcd);
            n=n-igcd;
            igcd=gcd(n,a);
            c=i%2;
        }

        i++;

    }
    //printf("%d %d\n",n,igcd);

    printf("%d\n",c);}
    return 0;

}
