#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCases, n, x;
    cin >> testCases;
    while(testCases--){
        cin >> n;
        set <long long int, greater <long long int>> a;         
        for(int i=0; i<n; i++){
            cin >> x;
            if(x>0) a.insert(x);
        }
        cout << a.size() << endl;
    }
}