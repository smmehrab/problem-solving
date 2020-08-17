#include<stdio.h>

int main()
{
    long long int n,d,i,a[120],answer;

    scanf("%lld %lld",&n,&d);

    answer=2;

    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(i!=0)
        {
            if(a[i]-a[i-1]==(2*d)) answer++;
            if(a[i]-a[i-1]>(2*d)) answer+=2;
        }
    }

    printf("%lld\n",answer);
    return 0;
}
