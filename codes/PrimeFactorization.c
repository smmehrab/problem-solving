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
#include<math.h>

int main()
{
    int n,c,i,m;
    scanf("%d",&n);
    printf("%d = 1",n);
    i=2; c=0;
    m=n;
            while(m%i==0)
                {
                    m=m/i;
                    c++;

                }
            if(c!=0)
                {
                printf("*(%d^%d)",i,c);
                }



            for(i=3;i<=sqrt(m);i=i+2)
            {
                c=0;
                while(m%i==0)
                {
                    m=m/i;
                    c++;
                }
                if(c!=0)
                {
                printf("*(%d^%d)",i,c);
                }

            }
        if(m>1) printf("*%d",m);
        printf("\n");
        return 0;
}
