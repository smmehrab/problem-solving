#include<stdio.h>

int main()
{
    int n,i,s,c;
    c=0;
    while(1)
    {
        scanf("%d ",&n);
        if(c==0) {printf("PERFECTION OUTPUT\n");c++;}


        if(n==0)
        {
            printf("END OF OUTPUT\n");
            break;
        }

        s=0;
        for(i=1;i<n;i++)
        {
            if(n%i==0) s+=i;
        }
        if(s<n)
        {
            printf("%5d  DEFICIENT\n",n);
        }
        else if(s>n)
        {
            printf("%5d  ABUNDANT\n",n);
        }
        else printf("%5d  PERFECT\n",n);

    }
    return 0;
}
