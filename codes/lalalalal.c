#include<stdio.h>

int prime(int p)
{
        int i;
        if(p%2==0)
    {
        return 0;
    }
        int z=sqrt(p);
    for(i=3;i<=z;i=i+2){
    if(p%i==0){
    return 0;
    }

    }
    return 1;
}



int main()
{
    int n,t;
    scanf("%d",&t);
    int j;
    for(j=1;j<=t;j++)
    {
        scanf("%d",&n);


        int i=2,c=0,onoff=0,m=n;
        if(n==0)
            {printf("no\n"); continue;}

                while(m%i==0)
                    {
                        c++;
                        m=m/i;
                    }

                for(i=3;i<=n;i=i+2)
                {

                    m=n;
                    if(prime(i)==1)
                    {
                        while(m%i==0)
                        {
                            c++;
                            m=m/i;

                        }
                    }

                }
                if((c+1)%2==1)
                {
                    onoff=!onoff;
                }
                if(prime(n)==1){onoff=!onoff;}
                if(onoff==1)
                    {printf("yes\n");}
                else if(onoff==0)
                    {printf("no\n");}
    }
        return 0;
}
