#include<stdio.h>

int main()
{
  int n,r=0,t;
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d",&t);
    r+=t-1;
  }
  printf("%d\n",r);
  return 0;
}
