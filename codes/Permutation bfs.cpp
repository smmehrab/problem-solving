/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, len;
    char a[n];
    string src="";
    string dest="";

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        src+=a[i];
    }

    len=src.length();

    dest=str.substr(0, len);
    sort(dest.begin(), dest.end());

    queue <string> q;
    map<string,int> dist;

    q.push(src);
    dist[src]=0;

    while(!q.empty()){
        string p=q.front();
        if(p==dest)
            break;
        q.pop();
        for(int j=2;j<=n;j++){
                string t=p;
                reverse(t.begin(),t.begin()+j);
                if(dist.find(t)==dist.end()){
                    dist[t]=dist[p]+1;
                    q.push(t);
                }
        }
    }

    cout<<dist[dest];
    return 0;
}
