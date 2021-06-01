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
#include<stdlib.h>

int divCount(int n)
{
    int hash[1000000]={0},p,i,nod,c;

    for(i=4;i<n;i+=2){
        hash[i] = 1;
    }

    for (p = 3; p * p < n; p+=2) {
        if (hash[p] == 0) {
            for (i = p * 2; i < n; i += p) {
                hash[i] = 1;
            }
        }
    }


    nod = 1;
    for (p = 2; p <= n; p++) {
        if (!hash[p]) {

            c = 0;
            if (n % p == 0) {
                while (n % p == 0) {
                    n /= p;
                    c++;
                }
                nod *= c + 1;
            }
        }
    }
    return nod;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k, n1 = m - l + 1, n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


int main()
{
    int a[100000],b[100000],c[100000],n,i,t,cs=0,j,k;
    for(i=1;i<=1000;i++){
        a[i]=divCount(i);
        b[i]=divCount(i);
    }
    mergeSort(a,1,1000);
    j=1;
    for(k=1;k<=1000;k++){
            for(i=1000;i>0;i--){
                if(a[k]==b[i]){
                    b[i]=-1;
                    c[j++]=i;
                }
        }
    }

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("Case %d: %d\n",++cs,c[n]);
    }
    return 0;
}
