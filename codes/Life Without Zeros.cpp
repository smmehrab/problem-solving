/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

int vanishZeroes(int i) {
    int res = 0, j = 1;

    while (i) {
        if (i % 10) {
            res += i % 10 * j;
            j *= 10;
        }
        i /= 10;
    }

    return res;
}

int main() {
    long long int a, b, x, y, z;
    cin >> a >> b;

    x = vanishZeroes(a);
    y = vanishZeroes(b);
    z = vanishZeroes(a + b);

    if (x + y == z) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
