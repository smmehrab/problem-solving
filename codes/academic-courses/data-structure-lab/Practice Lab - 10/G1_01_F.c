#include<stdio.h>
long long int digsum(long long int n)
{
  long long int i=0;
  while(n!=0)
  {
    i+=(n%10);
    n/=10;
  }
  return i;
}
int main()
{

  long long int n;
  scanf("%lld",&n);
  if(n%digsum(n)==0) printf("Yes\n");
  else printf("No\n");
  return 0;

}
