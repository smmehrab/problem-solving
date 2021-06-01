/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[100000],b[100000],temp;
    int t,r,i,j,k;

    scanf("%d%c",&t,&temp);
    while(t--)
    {
        scanf("%[^\n] %[^\n]", &a, &b);

        j=0;
        while(a[j]!='\0') j++;
        sort(a,a+j-1);

        i=0;
        while(b[i]!='\0') i++;
        sort(b,b+i-1);

        if(i!=j) r=0;
        else
        {
            r=1;
            for(i=0;i<j;i++)
            {
                if(a[i]!=b[i]) {r=0;break;}
            }
        }

        if(r==0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
