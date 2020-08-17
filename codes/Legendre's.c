#include<stdio.h>

int findPowerPrime(int fact, int p)
{
    int res = 0;
    while (fact > 0)
    {
        res += fact / p;
        fact /= p;
    }
    return res;
}

int findPowerComposite(int fact, int n)
{
    int res = INT_MAX;

    for (int i = 2; i <= sqrt(n); i++)
    {
        int count = 0;
        if (n % i == 0)
        {
            count++;
            n = n / i;
        }

        if (count > 0)
        {
            int curr_pow = findPowerPrime(fact, i)/count;
            res = min(res, curr_pow);
        }
    }

    if (n >= 2)
    {
        int curr_pow  = findPowerPrime(fact, n);
        res = min(res, curr_pow);
    }

    return res;
}

int main()
{
    int fact = 146, n = 5;
    printf("%d\n",findPowerComposite(fact, n));
    return 0;
}
