/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

int getMoneySpent(int keyboards_count, int keyboards[], int drives_count, int drives[], int b) {

    sort(keyboards, keyboards+keyboards_count);
    sort(drives, drives+drives_count);

    int i,j,m=-1;

    for(i=0;i<keyboards_count;i++){
        for(j=0;j<drives_count;j++){
            if(keyboards[i]+drives[j]<=b)
                m=max(m,keyboards[i]+drives[j]);
        }
    }

    return m;
}

int main(){

    int i,b,n,m;
    int np[10000],mp[10000];

    cin >> b >> n >> m;

    for(i=0;i<n;i++)
        cin >> np[i];
    for(i=0;i<m;i++)
        cin >> mp[i];

    printf("%d\n",getMoneySpent(n,np,m,mp,b));
}
