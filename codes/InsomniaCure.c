#include<stdio.h>

int main()
{
    while(1){
    int k,l,m,n,d;
    scanf("%d",&k);
    scanf("%d",&l);
    scanf("%d",&m);
    scanf("%d",&n);
    scanf("%d",&d);

    int s[100000];

    int i;

    for(i=1;i<=d;i++)
    {

        s[i]=1;
    }
    for(i=1;i<=d;i=i+k)
    {
        if(k<=d){
        s[i]=0;}
    }
    for(i=1;i<=d;i=i+l)
    {
        if(l<=d && l!=k){
        s[i]=0;}
    }
    for(i=1;i<=d;i=i+m)
    {
        if(m<=d && ((m!=l)||(m!=k))){
        s[i]=0;}
    }
    for(i=1;i<=d;i=i+n)
    {
        if(n<=d && ((n!=l)||(n!=k)||(n!=m))){
        s[i]=0;}
    }
    int c=0;
    for(i=1;i<=d;i++)
    {
        if(s[i]==0)
        {c++;}
    }

    printf("%d\n",c);}
    return 0;



}
