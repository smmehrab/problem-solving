/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x, gondolaCount;
    cin >> n >> x;

    vector<int> p(n);
    for(int &w : p)
        cin >> w; 

    sort(p.begin(), p.end());

    gondolaCount = 0;
    for(int i=0, j=n-1; i<=j; gondolaCount++) {
    	if(i==j) {
    		gondolaCount++;
    		break;
    	}
        else if(p[i]+p[j]>x)
            j--;
        else 
            i++, j--;
    }

    cout << gondolaCount << endl;
    return 0;
}