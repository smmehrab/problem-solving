#include<stdio.h>

int counter(int n, int c){

    if(n==1)
        return c+1;

    else if(n%2)
        n/=2;

    else
        n=(3*n)+1;

    return counter(n,c+1);
}


int main(){
    int n,c;
    scanf("%d",&n);
    c=counter(n,0);
    printf("%d\n",c);
    return 0;
}
