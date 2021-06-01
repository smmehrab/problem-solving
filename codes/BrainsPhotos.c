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

    int n,m,i,j,c=0;
    char temp;

    scanf("%d %d\n",&n,&m);

    i=0;
    while(i<n)
    {
        j=0;
        while(j<m)
        {
            if(j==m-1 && i==n-1){scanf("%c",&temp);}
            else if(j==m-1){scanf("%c\n",&temp);}
            else{scanf("%c ", &temp);}

            if((temp=='C')||(temp=='M')||(temp== 'Y')){c++;j++;}
            else {j++;}
        }
        i++;

    }

    if(c!=0){printf("#Color\n");}

    else{printf("#Black&White\n");}

    return 0;
}
