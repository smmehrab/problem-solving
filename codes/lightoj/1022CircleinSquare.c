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
#include<math.h>



int main()
{
    int T,i;
 double pi=2.0*acos(0.0);
    scanf("%d",&T);
    double r[T],A[T];
    for(i=0;i<T;i++)
    {
    scanf("%lf",&r[i]);
    A[i] = pow((2.00*r[i]),2) - (pi*pow(r[i],2));

    }
    for(i=0;i<T;i++)
    {
        printf("Case %d: %0.2lf\n",i+1,A[i]);

    }


    return 0;
}
