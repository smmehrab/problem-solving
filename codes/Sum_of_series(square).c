#include<stdio.h>

int nth_term(int n)
{

    if(n<=2n)
    {
        return n + nth_term(n+1);
    }
    else{int main();}


}


int main()
{   int n;
    printf("Enter the integer n (th term) : \n");
    scanf("%d",&n);

    printf("%d",nth_term(n));
    return 0;
}
