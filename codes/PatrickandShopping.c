#include<stdio.h>

int main()
{

    int d1,d2,d3,d;
    scanf("%d %d %d",&d1,&d2,&d3);

    d=0;
    if(d1<=(d2+d3)){d+=d1;}
    else{d+=(d2+d3);}
    if(d3<=(d1+d2)){d+=d3;}
    else {d+=(d1+d2);}
    if(d2<=(d3+d1)){d+=d2;}
    else{d+=(d3+d1);}

    printf("%d\n",d);
    return 0;

}
