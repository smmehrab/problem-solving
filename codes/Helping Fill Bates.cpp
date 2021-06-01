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
using namespace std;
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> ve;

int main() {
    string s;
    cin>>s;
    ve v;
    v.resize(123);
    for(ll i=0;i<s.length();i++){
        v[s[i]].push_back(i);
    }
    ll t;
    cin>>t;
    while(t--){
        string q;
        cin>>q;
        ll in_it=-1,start=0,flag=0;
        for(ll i=0;i<q.size();i++){
            vector<ll> :: iterator it=upper_bound(v[q[i]].begin(),v[q[i]].end(),in_it);
            in_it=it-v[q[i]].begin();
            if(it==v[q[i]].end()) {
                flag=1;break;
            }
            in_it=v[q[i]][in_it];
            if(i==0) start=in_it;
        }
        if(flag==0) cout<<"Matched "<<start<<" "<<in_it<<endl;
        else cout<<"Not matched\n";
    }
    return 0;
}
