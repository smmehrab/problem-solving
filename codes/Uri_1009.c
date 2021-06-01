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
  double salary,value,
  TOTAL;
  char name;
  scanf("%s %lf %lf",&name,&salary,&value);

  TOTAL = salary+value*.15;
  printf("TOTAL = R$ %.2lf\n",TOTAL);
  return 0;
}
