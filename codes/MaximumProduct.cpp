#include <bits/stdc++.h>
#include <string>
using namespace std;

int aDigits, bDigits;
string a, b, answer;

void recurse(int pos, int smallFlag, int largeFlag, string number)
{
    if (pos == bDigits)
    {
        answer = number;
        answer.erase(0, min(answer.find_first_not_of('0'), answer.size() - 1));
        return;
    }

    int upperLimit = b[pos] - '0';
    int lowerLimit = a[pos] - '0';
    int digit;

    if(smallFlag==1){
        digit = 9;
        recurse(pos + 1, 1, digit > lowerLimit || largeFlag == 1, number + to_string(digit));
    }

    else {
        digit = upperLimit;
        recurse(pos + 1, smallFlag, largeFlag, number + to_string(upperLimit));
    }
    else if (upperLimit - lowerLimit == 1){
        digit = upperLimit - 1;
        recurse(pos + 1, 1, largeFlag, number + to_string(digit));
    }

    else if (upperLimit - lowerLimit > 1){
        digit = upperLimit - 1;
        recurse(pos + 1, 1, 1, number + to_string(digit));
    }


    return;
}

void solve(string a, string b)
{
    aDigits = a.size();
    bDigits = b.size();
    int dif = bDigits - aDigits;
    while (dif--) a = "0" + a;
    aDigits = a.size();
    bDigits = b.size();
    recurse(0, 0, 0, "");
}

int main()
{
    cin >> a >> b;
    solve(a, b);
    cout << answer << endl;
    return 0;
}