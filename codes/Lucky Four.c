#include<stdio.h>
#include<string.h>
int main()
{
    int t,l,ans;
    char n[10000];
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%s", n);
        l=strlen(n);
        while(l--){
            if(n[l]=='4') ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
