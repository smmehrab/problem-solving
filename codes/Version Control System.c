#include<stdio.h>
int main()
{
    int t,n,m,k,i,j,ans1,ans2;
    scanf("%d",&t);
    while(t--){
        ans1=0; ans2=0;
        scanf("%d %d %d",&n,&m,&k);
        int a[1000]={0},b[1000]={0};

        for(i=0;i<m;i++) {
            scanf("%d",&j);
            a[j]++;
        }
        for(i=0;i<k;i++){
            scanf("%d",&j);
            if(a[j]!=0) ans1++;
            b[j]++;
        }

        for(i=1;i<=n;i++){
            if(a[i]==0 && b[i]==0) ans2++;
        }

        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
