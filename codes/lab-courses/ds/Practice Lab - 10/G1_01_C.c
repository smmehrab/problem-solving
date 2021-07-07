/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<stdio.h>
#include<string.h>

int main()
{
  char s[200],t[200];
  scanf("%s", s);
  scanf("%s", t);

  int l=strlen(s);
  int i,j,k,m;
  k=0;
  for(i=0;i<l;i++)
  {
    m=i;
    for(j=0;j<l;)
    {
      if(m==l) m-=l;
      if(s[m++]==t[j++]) k++;
      else break;
    }
    if(k==l) break;
    else k=0;
  }
  if(k!=l) printf("No\n");
  else printf("Yes\n");
  return 0;

}
