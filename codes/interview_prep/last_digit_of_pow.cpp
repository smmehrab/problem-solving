#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int mod(char x[], int m) {
    int ans = 0;
    for (int i = 0; i < strlen(x); i++)
        ans = (ans * 10 + x[i] - '0') % m;
    return ans;
}

int find_last_digit_of_pow(char base[], char exp[]) {
    int len_base = strlen(base), len_exp = strlen(exp);

    if (len_base == 1 && len_exp == 1 && exp[0] == '0' && base[0] == '0')
        return 1;

    if (len_exp == 1 && exp[0] == '0')
        return 1;

    if (len_base == 1 && base[0] == '0')
        return 0;

    int base_int = base[len_base-1]-'0';
    int exp_int = (mod(exp, 4) == 0) ? 4 : mod(exp, 4);

    int result = pow(base_int, exp_int);
    return result % 10;
}

int main() {
    char base[100], exp[100];
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> exp;
    cout << "Last digit of " << base << "^" << exp << " is: " << find_last_digit_of_pow(base, exp) << endl;
    return 0;
}
