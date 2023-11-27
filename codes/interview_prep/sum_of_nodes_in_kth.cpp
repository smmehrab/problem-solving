#include<iostream>
using namespace std;

int main() {
    string s;
    int k, number, digit;
    cin>>k;
    cin>>s;
    int slen = s.length();
    int sum = 0;
    int level = -1;
    for(int i=0; i<slen; i++) {
        if(s[i]=='(')
            level++;
        else if(s[i]==')')
            level--;
        else if(level==k) {
            number = 0;
            while(s[i]>=48 && s[i]<=57) {
                digit = s[i]-'0';
                number = (number*10) + digit;
                i++;
            }
            sum += number;
            i--;
        }
 
    }
    cout << sum << endl;
    return 0;
}