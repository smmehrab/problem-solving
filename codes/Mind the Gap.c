#include<stdio.h>

int main()
{
    int n,s,h[120],m[120],i,j,g[120],hf=0,mf=0,d;

    scanf("%d %d",&n,&s);
    d=(2*s)+2;
    printf("%d\n",d);
    h[0]=m[0]=g[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&h[i],&m[i]);
        g[i]=(60*h[i])+m[i];
        g[i]=g[i]-g[i-1];
        printf("%d\n",g[i]);
    }
    for(i=0;i<n;i++)
    {
        if(g[i]>=d)
        {
            hf+=h[i];
            mf+=m[i]+s+1;
            if((mf/60)!=0)
            {
                hf+=(mf/60);
                mf%=60;
            }
            if(hf>=24) hf-=24;
            printf("\n%d %d\n",hf,mf);
            return 0;
        }
    }

    hf+=h[n];
    mf+=m[n]+s+1;
    if((mf/60)!=0)
    {
        hf+=(mf/60);
        mf%=60;
    }
    printf("\n%d %d\n",hf,mf);
    return 0;
}
