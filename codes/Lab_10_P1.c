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

    double billf50=0,bills100=0,billt100=0,billab250=0,totalbill;

    double units;

    scanf("%lf",&units);

    if(units>=50.00)
    {
        billf50= 50.00*0.50;
    }
    else
    {   billf50=units*0.50;
        totalbill=billf50+(billf50*0.20);
            printf("%lf\n",totalbill);
        return 0;
    }
    if(units>=150.00)
    {
        bills100=100.00*0.75;
    }
    else
    {
        bills100=(units-50.00)*0.75;
        totalbill=(billf50+bills100)+((billf50+bills100)*0.20);
            printf("%lf\n",totalbill);
        return 0;

    }

    if(units>=250)
    {
        billt100=100.00*1.20;
        billab250=(units-250.00)*1.50;
    }
    else
    {
        billt100=(units-150.00)*1.20;
        totalbill=(billf50+bills100+billt100)+((billf50+bills100+billt100)*0.20);
            printf("%lf\n",totalbill);
        return 0;
    }

    totalbill=(billf50+bills100+billt100+billab250)+((billf50+bills100+billt100+billab250)*0.20);
    printf("%lf\n",totalbill);
    return 0;




}
