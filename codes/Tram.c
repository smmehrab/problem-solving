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

    int n,x,y,c=0,s[1000];
    scanf("%d",&n);
    int i=0;
    while(i<n)
    {

        scanf("%d %d",&x,&y);




        c=c+(y-x);
        s[i]=c;
        if(i>0)
        {
            if(s[i]>s[0])
            {
                int t=s[0];
                s[0]=s[i];
                s[i]=t;
            }
        }
        i++;

    }
    printf("%d\n",s[0]);
    return 0;



}
