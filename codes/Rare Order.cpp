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
using namespace std;

vector <int> adj[100100];

map<char, int> mp;
map<int, char> revMp;
stack<int> Stack;

bool visited[100100];
string input[100100];

void dfs(int n, stack<int>& Stack) {
    visited[n]=true;
    for(int i=0; i<adj[n].size(); i++) {
        if(!visited[adj[n][i]])
            dfs(adj[n][i], Stack);
    }
    Stack.push(n);
}

int main() {
    int line=-1, key=1;
    char temp;

    while(true){
        cin >> input[++line];
        if(input[line]=="#")
            break;
    }

    for(int i=0; i<line; i++){
        for(int j=0; j<input[i].size(); j++){
            temp = input[i][j];
            if(mp[temp]==0){
                revMp[key]=temp;
                mp[temp] = key++;
            }
        }
    }

    for(int i=1; i<line; i++){
        string prev = input[i - 1];
        string next = input[i];

        for(int j=0; j<prev.length() && j<next.length(); j++){
            if (prev[j] != next[j]){
                adj[mp[prev[j]]].push_back(mp[next[j]]);
                break;
            }
        }
    }

    for(int i=1; i<key; i++)
        visited[key]=false;


    for(int i=1; i<key; i++) {
        if(!visited[i])
            dfs(i, Stack);
    }

    while(!Stack.empty()) {
        cout << revMp[Stack.top()];
        Stack.pop();
    }
    cout << endl;
}
