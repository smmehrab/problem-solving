#include<stdio.h>
#include<string.h>

int main()
{
    int t,m,l;
    char n[10000];
    scanf("%d",&t);
    while(t--){
        scanf("%s", n);
        l=strlen(n);
        m= n[0]-'0' + n[l-1] - '0';
        printf("%d\n",m);
    }
    return 0;
}
