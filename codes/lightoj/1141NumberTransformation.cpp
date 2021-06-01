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
#include<algorithm>
#include<iostream>
#include<limits.h>
#include<string.h>
#include <utility>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
 
vector<int>prime;
bool divisible[1100];
int visited[1100];
 
void sieve(){
    int n=1100;
    int sqn=sqrt(n);
 
    for(int i=4; i<=n; i+=2)
        divisible[i]=true;
 
    prime.push_back(2);
 
    for(int i=3; i<=sqn; i+=2){
        if(!divisible[i])
            for(int j=i*i; j<=n; j+=i)
                divisible[j]=true;
    }
 
    divisible[1]=true;
    divisible[0]=true;
 
    for(int i=3; i<=n; i+=2)
        if(!divisible[i])
            prime.push_back(i);
}
 
int bfs(int src, int dest){
    queue<int>q;
 
    int current, next;
    memset(visited, -1, sizeof(visited));
 
    q.push(src);
    visited[src]=0;
 
    while(!q.empty()){
        current = q.front();
        q.pop();
 
        for(int i=0; prime[i]<current; i++){
            if(current%prime[i]==0){
                next = current + prime[i];
                if(visited[next]==-1 && next<=dest){
                    visited[next] = visited[current] + 1;
                    q.push(next);
                }
            }
        }
    }
 
    return visited[dest];
}
 
int main(){
    int T, cs=0, s, t, res;
    sieve();
 
    cin >> T;
    while(T--){
        cin >> s >> t;
        res = bfs(s, t);
        cout << "Case " << ++cs << ": " << res << endl;
    }
}