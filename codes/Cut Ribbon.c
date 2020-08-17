#include<stdio.h>
int swap(int *a,int *b)
{
    int t;
    t=*b;
    *b=*a;
    *a=t;
}

int main()
{
    int n,a,b,c,i,j,k,na,nb,nc,answer;
    scanf("%d %d %d %d",&n,&a,&b,&c);

    if(a>b) swap(&a,&b);
    if(a>c) swap(&a,&c);
    if(b>c) swap(&b,&c);

    na=(n/a); nb=(n/b); answer=0;

    for(i=0;i<=nb;i++)
    {
        for(j=0;j<=na;j++)
        {
            if((i*b)+(j*a)>n) break;
            else
            {
                if((n-(i*b+j*a))%c==0) k=j+i+((n-(i*b+j*a))/c);
                if(k>answer) answer=k;
            }
        }
    }

    printf("%d\n",answer);
    return 0;
}


