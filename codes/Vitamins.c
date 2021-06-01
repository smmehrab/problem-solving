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

    char t[10];
    int n,c,amin=999999,bmin=999999,cmin=999999,abmin=999999,acmin=999999,bcmin=999999,abcmin=999999,i,j,k,l,min[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %s",&c, t);
        l=strlen(t);
        if(l==2)
        {
            k=t[0]-'A'+t[1]-'A';
            if(k==1 && c<abmin) abmin=c;
            else if(k==2 && c<acmin) acmin=c;
            else if(k==3 && c<bcmin) bcmin=c;
        }

        else if(l==3 && c<abcmin) abcmin=c;

        else if(l==1)
        {
            k=t[0]-'A';
            if(k==0 && c<amin) amin=c;
            else if(k==1 && c<bmin) bmin=c;
            else if(k==2 && c<cmin) cmin=c;
        }
    }

    i=0;
    min[i++]=amin+bmin+cmin;
    min[i++]=amin+bcmin;
    min[i++]=abmin+cmin;
    min[i++]=acmin+bmin;
    min[i++]=abmin+bcmin;
    min[i++]=abmin+acmin;
    min[i++]=bcmin+acmin;
    min[i++]=abcmin;
    if((acmin==999999 && amin==999999&& abmin==999999 && abcmin ==999999) || (bcmin==999999 && bmin==999999 && abmin==999999 && abcmin ==999999) || (acmin==999999 && cmin==999999 && bcmin==999999 && abcmin ==999999)) abcmin=-1;
    else abcmin=999999;
    for(i=0;i<8;i++)
    {
        if(min[i]<abcmin) abcmin=min[i];
    }
    printf("%d\n",abcmin);
    return 0;
}
