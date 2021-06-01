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

int main(){
    int n,a[1100],i,t,j,s;
    while(scanf("%d",&n)!= EOF){
        s=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(i!=0){
                j=i;
                while(a[j]<a[j-1]){
                    t=a[j-1];
                    a[j-1]=a[j];
                    a[j]=t;

                    s++;
                    j--;

                    if(j==0)
                        break;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",s);
    }
    return 0;
}
