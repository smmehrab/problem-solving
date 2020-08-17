#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void f(int n)
{
    int ans = 0;
    for (int number = 1; number <= sqrt(n); number++)
    {
        int low = number;
        int high = sqrt(n);

        while (low <= high)
        {
            if ((number * number) + (low * low) + (high * high) + (number * low) + (number * high) + (low * high) == n)
            {
                if(number==low && number==high){
                    ans++;
                } else if(number==low || number == high || low == high){
                    ans+=3; 
                } else{
                    ans+=6; 
                }
                low++;
                high--;
            }
            else if ((number * number) + (low * low) + (high * high) + (number * low) + (number * high) + (low * high) < n)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int number = 1; number <= n; number++)
    {
        f(number);
    }
    return 0;
}