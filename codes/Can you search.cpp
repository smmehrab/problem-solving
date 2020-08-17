#include<stdio.h>

int main(){
    int t,n,q,a,b,ans[100000],i,j,k;

    scanf("%d",&t);



    while(t--){
        scanf("%d %d",&n,&q);

        for(i=0;i<n;i++){
            scanf("%d",&a);

            if(!i) k=a;
            else if(a<k) k=a;

            ans[i]=k;
        }

        for(i=0;i<q;i++){
            scanf("%d",&b);
            printf("%d\n",ans[b-1]);
        }
    }

    return 0;
}
