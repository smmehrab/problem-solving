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
    int n, m, k, residentCount;
    cin >> n >> m >> k;

    vector<int> applicants(n);
    for(int &applicant : applicants)
        cin >> applicant; 

    vector<int> apartments(m);
    for(int &apartment : apartments)
        cin >> apartment; 

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    residentCount = 0;
    for(int i=0, j=0; i<n && j<m;) {
        if(abs(applicants[i]-apartments[j]) <= k) {
            residentCount++;
            i++;
            j++;
        }
        else if(applicants[i] < apartments[j])
            i++;
        else
            j++;
    }

    cout << residentCount << endl;
    return 0;
}