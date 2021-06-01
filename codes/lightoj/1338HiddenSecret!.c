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
    char a[120],b[120],c[30]={0},d[30]={0};
    int t,r,i,j,k,al,bl,cs=0;

    scanf("%d",&t);
    getchar();
    while(t--){

        for(i=0;i<26;i++){
            c[i]=0; d[i]=0;
        }

        gets(a);
        gets(b);

        for(i=0;a[i]!='\0';i++){
            if(a[i]>=65 && a[i]<=90) c[a[i]-65]++;
            else if(a[i]>=97 && a[i]<=122) c[a[i]-97]++;
        }

        for(i=0;b[i]!='\0';i++){
            if(b[i]>=65 && b[i]<=90) d[b[i]-65]++;
            else if(b[i]>=97 && b[i]<=122) d[b[i]-97]++;
        }

        for(i=0,r=1;i<26;i++){
            if(c[i]!=d[i]){
                printf("Case %d: No\n",++cs);
                r=0;
                break;
            }
        }

        if(r) printf("Case %d: Yes\n",++cs);
    }
    return 0;
}
