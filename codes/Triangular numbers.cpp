#include<stdio.h>

int main(){

    int n,i,r=0,a[700];

    for(i=1;i<=600;i++)
        a[i]=(i*(i+1))/2;

    scanf("%d",&n);

    for(i=1;i<=600;i++){
        if(a[i]==n)
            r=1;
    }

    if(r)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
