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