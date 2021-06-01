/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<iostream>
using namespace std;

#define MAX 500

int multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry

    for (int i=0; i<res_size; i++)// One by one multiply n with individual digits of res[]
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;// Store last digit of 'prod' in res[]
        carry  = prod/10;// Put rest in carry
    }

    while (carry)// Put carry in res and increase result size
    {
        res[res_size++] = carry%10;
        carry/=10;
    }

    return res_size;
}

void factorial(int n)
{
    int res[MAX];

    res[0] = 1;// Initialize result
    int res_size = 1;

    for (int x=2; x<=n; x++) res_size = multiply(x, res, res_size);// Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n

    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--) cout << res[i];
}

int main()
{
    factorial(100);
    return 0;
}
