#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, a[100000], sum, answer;

    cin >> n >> k;
    for(int element=0; element<n; element++)
        cin >> a[element];

    answer = 0;
    for(int bitmask = 0; bitmask < (1<<n); bitmask++){
        sum = 0;
        for(int index=0; index < n; index++){
            if(bitmask & (1 << index)){
                sum += a[index];
            }
        }
        if(sum % k == 0) answer++;
    }

    return 0;
}