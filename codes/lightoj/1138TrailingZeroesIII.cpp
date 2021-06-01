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
#include <string> 
#include <map>
using namespace std;

long long int highestPowerof5(long long int n) 
{ 
   long long int power = 0;
   while(n%5==0){
       n/=5;
       power++;
   } 
   return power;  
} 

// Driver Code
int main()
{
    int testCaseCount;
    int testCase;
    long long int q, n, power;
    string answer, qs, ns;
    map<string, string> storedQ;
    for(q=1, n=5, power=1; q<1000010; q++){
        qs = to_string(q);
        if(power==1){
            ns = to_string(n);
            storedQ[qs] = ns;
            n+=5;
            power =  highestPowerof5(n);
        } else{
            storedQ[qs] = "impossible";
            power--;
        }
    }
    scanf("%d", &testCaseCount);
    for (testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%lld", &q);
        qs = to_string(q);
        answer = storedQ[qs];
        printf("Case %d: %s\n", testCase, answer.c_str());
    }
    return 0;
}