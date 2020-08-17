#include<stdio.h>
int main()
{
    int t,n;
    char s[]="HOSTED",ns[]="NOT HOSTED";
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n==2010 || n==2015 || n==2016 || n==2017 || n==2019) puts(s);
        else puts(ns);
    }
    return 0;
}
