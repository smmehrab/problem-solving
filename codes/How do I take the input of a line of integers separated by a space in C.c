/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i=0, j=0;
  int arr[10000];
  char temp;
  do {
      scanf("%d%c", &arr[i], &temp);
      i++;
  } while(temp != '\n');

  for(j=0; j<i; j++) {
    printf("%d ", arr[j]);
  }

  return 0;
}
