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
    int n,i,j,k,l,m;
    char t[100],temp;
    scanf("%d %d",&n,&k);
    scanf("%s%c", t,&temp);

    i=0;j=1;
    while(j<n)
    {
        if(t[i]==t[j])
        {
            if(i==0) m=j+1;
            i++;
            j++;
        }
        else if(i==0) j++;
        else {i=0;j=m;}
    }


    for(j=0;j<k-1;j++)
    {
        for(l=0;l<(n-i);l++) {printf("%c",t[l]);}
    }

    for(l=0;l<n;l++) {printf("%c",t[l]);}

    printf("\n");
    return 0;
}
