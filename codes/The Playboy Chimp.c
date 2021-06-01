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

int main()
{
   long long int arr[100000],t,a,b;
   int i,j,n,q,k;

   scanf("%d",&n);

   for(i=0;i<n;i++) scanf("%lld",&arr[i]);

   scanf("%d",&q);

   for(i=0;i<q;i++) {

       scanf("%lld",&t);
       a=0; b=0;
       if(t<arr[0]) b=arr[0];
        else if(t>arr[n-1]) a=arr[n-1];
        else{
            for(j=0;j<n;j++){

                if(arr[j]==t){
                    k=j-1;
                    while(arr[k]==arr[j]) k--;
                    if(k>=0) a=arr[k];
                    k=j+1;
                    while(arr[k]==arr[j]) k++;
                    if(k<n) b=arr[k];
                    break;
                }

                else if(arr[j]>t){
                    k=j-1;
                    while(arr[k-1]==arr[j]) k--;
                    if(k>=0) a=arr[k];
                    if(j<n) b=arr[j];
                    break;
                }
            }
        }

        if(a) printf("%lld",a);
        else printf("X");

        if(b) printf(" %lld",b);
        else printf(" X");

        printf("\n");
   }
   return 0;
}
