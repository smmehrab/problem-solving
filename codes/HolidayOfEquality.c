#include<stdio.h>
int main()
{int n,a[120],i=0,max=0,g=0;scanf("%d",&n);
if(n==1){scanf("%d",&a[0]);printf("0");return 0;}
while(i<n){scanf("%d",&a[i]);if(max<a[i]){max=a[i];}i++;}i=0;
while(i<n){g+=(max-a[i]);i++;}
printf("%d\n",g);return 0;}
