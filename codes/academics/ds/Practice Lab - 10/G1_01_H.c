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
  int n,r=0,p,q;
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d %d",&p,&q);
    if(q-p>=2) r++;
  }
  printf("%d\n",r);
  return 0;
}
