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
#include<conio.h>
#define MAX 30

void main() {
   int size, i, arr[MAX];
   int *ptr;

   ptr = &arr[0];

   printf("\nEnter the size of array : ");
   scanf("%d", &size);

   printf("\nEnter %d integers into array: ", size);
   for (i = 0; i < size; i++) {
      scanf("%d", ptr);
      ptr++;
   }
   ptr--;



   printf("\nElements of array in reverse order are :");

   for (i = size - 1; i >= 0; i--) {
      printf("\nElement %d is %d : ", i, *ptr);
      ptr--;
   }

   getch();
}
