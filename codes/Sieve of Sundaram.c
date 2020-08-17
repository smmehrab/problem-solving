#include <stdio.h>
#include<stdbool.h>

int SieveOfSundaram(int n)
{
    int i,j;
    int nNew = (n-2)/2;

    bool marked[nNew + 1];

    memset(marked, false, sizeof(marked));

    for (i=1; i<=nNew; i++)
    {
        for (j=i; (i + j + 2*i*j) <= nNew; j++) marked[i + j + 2*i*j] = true;
    }

    if (n > 2) printf("2 ");

    for (i=1; i<=nNew; i++)
    {
        if (marked[i] == false) printf("%d ",2*i + 1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    SieveOfSundaram(n);
    return 0;
}
