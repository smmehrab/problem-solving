/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
using namespace std;

int main()
{
    int low, high, n, ans=0;
    scanf("%d %d %d", &low, &high, &n);
    if(high%n==0){
        ans+=1;
    } else if(low%n==0){
        ans+=1;
    }
    ans+= (high-low)/n;
    printf("%d", ans);   
    return 0;
}