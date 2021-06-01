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
    double n;
    scanf("%lf",&n);

    if(n>=5000 && n<=10000)
    {
        double HRA = n*0.10;
        double DA = n*0.05;
        printf("HRA = %lf\nDA = %lf\n",HRA,DA);
    }
    else if(n>=10001 && n<=15000)
    {
        double HRA = n*0.15;
        double DA = n*0.08;
        printf("HRA = %lf\nDA = %lf\n",HRA,DA);
    }

    return 0;


}
