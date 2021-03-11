#include<stdio.h>
#include<string.h>

int main()
{
  char s[20];int i,j,n;
  scanf("%s", s);
  n=strlen(s);
  if(s[0]!='A')
  {
        printf("WA");
        printf("\n");
        return 0;
  }
  else
  {
    s[0]+=32;
    j=0;
    for(i=2;i<n-1;i++)
    {
      if(s[i]=='C')
      {
        j++;
        s[i]+=32;
      }
    }
    if(j!=1)
    {
        printf("WA");
        printf("\n");
        return 0;
    }
    for(i=1;i<n;i++)
    {
      if(s[i]<'a')
      {
        printf("WA");
        printf("\n");
        return 0;
      }
    }
  }

  printf("AC");
  printf("\n");
  return 0;

}
