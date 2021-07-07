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

int main()
{
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  if(a<b) a^=b^=a^=b;
  if(a<c) a^=c^=a^=c;
  if(b<c) b^=c^=b^=c;
  a=(a-b)+(b-c);
  printf("%d\n",a);
  return 0;
}
