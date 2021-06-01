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
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int n, m, area;
bool visited[100][100];
string input[100];

void dfsCount(int x, int y){
    if(x == n || x<0 || y == m || y<0 || input[x][y]=='L' || visited[x][y]==true)
        return;

    visited[x][y] = true;
    area++;

    dfsCount(x+1, y);
    dfsCount(x-1, y);
    dfsCount(x, y+1);
    dfsCount(x, y-1);

    dfsCount(x+1, y+1);
    dfsCount(x-1, y-1);
    dfsCount(x+1, y-1);
    dfsCount(x-1, y+1);
}

int main() {
    int t, x, y, first = 1;

    cin >> t;

    getchar();
    getchar();

    while(t--){
        string line;
        n = 0;
        m = 0;

        if(first == 0)
            cout << endl;

        first = 0;

        while(getline(cin, line) && line.length()>0) {
            if(line[0] == 'L' || line[0] == 'W'){
                input[n] = line;
                m = line.length();
                n++;
            }
            else if(line[0]!='\n'){
                istringstream is(line);
                is>>x>>y;

                memset(visited, false, sizeof (visited));

                area = 0;
                dfsCount(x-1, y-1);

                cout << area << endl;
            }
        }
    }

    return 0;
}
