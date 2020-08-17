#include <bits/stdc++.h>
#include <string>
using namespace std;

int dp[2005][2][2][2005], nLen, answer;
string n;

long long int recurse(int pos, int smallFlag, int largeFlag, int remainder){
    if(pos==numberOfDigits) return remainder==0;

    long long int  &ret = dp[pos][smallFlag][largeFlag][remainder];
    if(ret!=-1) return ret;

    int upperLimit=9, lowerLimit = 0;
    if(smallFlag==0) upperLimit = b[pos] - '0';
    if(largeFlag==0) lowerLimit = a[pos] - '0';

    ret=0;
    if(pos%2==1 && (d>=lowerLimit||largeFlag==1) && (d<=upperLimit || smallFlag==1)) ret = (ret + recurse(pos+1, d<upperLimit || smallFlag ==1,  d>lowerLimit || largeFlag ==1, (10*remainder + d)%m))%mod;
    else if(pos%2==0) {
        for(int option = lowerLimit; option <= upperLimit; option++){
            if(option!=d){
                ret = (ret + recurse(pos+1, option<upperLimit || smallFlag ==1, option>lowerLimit || largeFlag==1, (10*remainder + option)%m))%mod;
            }
        }
    }

    return ret;
}

int solve(string n){
    nLen = n.size();
    memset(dp, -1, sizeof(dp));
    return recurse(0, 0, 0, 0);
}

int main()
{
    int testCaseCount;
    cin >> testCaseCount;
    for(int testCase = 1; testCase<=testCaseCount; testCase++){
        cin >> n;
        answer = solve(n);
        cout << answer << endl;
    }
    return 0;
}





string input;

cout << "Please enter a string: ";
cin >> input;

if (input == string(input.rbegin(), input.rend())) {
    cout << input << " is a palindrome";
}