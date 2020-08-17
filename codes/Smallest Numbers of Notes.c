#include<stdio.h>

int main()
{
    int t,n,ans;
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        while(n/100){
            ans+=(n/100);
            n%=100;
        }
        while(n/50){
            ans+=(n/50);
            n%=50;
        }
        while(n/10){
            ans+=(n/10);
            n%=10;
        }
        while(n/5){
            ans+=(n/5);
            n%=5;
        }
        while(n/2){
            ans+=(n/2);
            n%=2;
        }
        if(n) ans+=n;
        printf("%d\n",ans);
    }
    return 0;
}
