#include<stdio.h>

int main(){

    int t,n,k,a[100],i,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        r=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]%2==0)
                r++;
        }

        if(k==0){
            if(r==n)
                printf("NO\n");
            else printf("YES\n");
        }

        else if(r>=k)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
