#include <stdio.h>

int main() {

    int NUMBER,wh;
    float aph,SALARY;
    scanf("%d %d",&NUMBER,&wh);
    scanf("%f",&aph);
    SALARY=(wh*aph);
    printf("NUMBER = %d\n",NUMBER);
    printf("SALARY = U$ %.2f\n",SALARY);

    return 0;
}
