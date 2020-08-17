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
