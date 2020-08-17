#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool prime[10000000];
int main()
{
    int n,c,t;
    long long int i,j,k;
    k=1000000000;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        c=0;
        memset(prime, false, sizeof(prime));
        for (i=3 ; i <= k; i+=2)
        {
            if (!prime[i/2])
            {
                c++;
                if(c==n) {printf("%d\n",i);break;}
                for (j=i+3;j<=k; j+=3) prime[j] = true;
            }
        }
    }
    return 0;
}

