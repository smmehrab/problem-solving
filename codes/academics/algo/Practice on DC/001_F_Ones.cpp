#include<bits/stdc++.h>
#include <iostream>
#include <float.h>
#include <stdlib.h>
#include<cstdio>
#include <math.h>
using namespace std;

int main(){
    int n, m, x;
    while(scanf("%d",&n)==1){
        x = 0, m =0;
        while(m!=0 || x==0){
            m = ((m*10)+1)%n;
            x++;
        }
        cout << x << endl;
    }
    return 0;
}
