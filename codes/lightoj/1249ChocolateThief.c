#include<stdio.h>

int main()
{
    int t,cs=0,a,b,c,n,v[120],th,vc,i,j,k;
    char x[120][120];

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0,vc=0,th=0;i<n;i++){
            scanf("%s %d %d %d", x[i],&a,&b,&c);
            v[i]=(a*b*c);
            if(i){
                if(v[i]>v[th]) th=i;
                if(v[i]<v[vc]) vc=i;
            }
        }

        if(th!=vc) printf("Case %d: %s took chocolate from %s\n",++cs,x[th],x[vc]);
        else printf("Case %d: no thief\n",++cs);

    }
    return 0;
}
