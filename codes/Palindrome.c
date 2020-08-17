#include<stdio.h>
int a[1000],i,n,count=0;

int is_palindrome(l,r)
{


    if((r-l)<1 && r==l) {return 1;count++;}
    if(a[l]==a[r]) return is_palindrome(l+1,r-1);
    else return 0;

}
int main()
{
    printf("The number of digits the integer have : \n");

    scanf("%d",&n);


    for(i=0;i<n;i++) scanf("%d",&a[i]);

    if(is_palindrome(0,n-1)==1) printf("The integer is a palindrome");

    else printf("The integer is not a palindrome");


    return 0;



}
