#include<stdio.h>
#include<math.h>

int main()
{
    long long int n;



    while(1){

        scanf("%lld",&n);
        if(n==0) {return 0;}

        long long int x,y;
        x=(int)sqrt(n);

        y=x*x;



        if(y==n) {printf("yes\n");}
        else {printf("no\n");}

    }
        return 0;



}
