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
#include<vector>
#include<queue>
using namespace std;

bool taken[100000];
vector<int>enemyList[100000];
vector<int>enemyCount[100000];


void initialize(int n){
    for(int i=0; i<n; i++){
        taken[i] = false;
        enemyList[i].clear();
        enemyCount[i].clear();
    }
}

int main(){
    int t, n, p, e, invitaion;
    cin >> t;
    while(t--){
        cin >> n;
        initialize(n);
        invitaion=0;
        for(int i=0; i<n; i++){
            cin >> p;
            enemyCount[p].push_back(i);
            for(int j=0; j<p; j++){
                cin >> e;
                enemyList[p].push_back(e);
            }
        }

        for(int i=0; i<n-1; i++){
            if(enemyCount[i].size()!=0){
                for(int j=0; j<enemyCount[i].size(); j++){
                    if(!taken[enemyCount[i][j]]){
                        taken[enemyCount[i][j]]=true;
                        for(int k=0; k<enemyList[enemyCount[i][j]].size(); k++)
                            taken[enemyList[enemyCount[i][j]][k]]=true;
                        invitaion++;
                    }
                }
            }
        }

        cout << invitaion << endl;
    }
    return 0;
}

