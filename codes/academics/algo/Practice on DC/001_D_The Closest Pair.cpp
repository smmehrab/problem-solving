#include<bits/stdc++.h>
#include <iostream>
#include <float.h>
#include <stdlib.h>
#include<cstdio>
#include <math.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    if(k >= n*(n-1)/2){
        cout << "no solution" << endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
            cout << "0 " << i << endl;
}
