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
#include<iostream>
#include<algorithm>
#include<map>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

void findAns(int n, int startingColumn, const vector<int>& child){
    int current = startingColumn;

    vector<int> orderOfTraversal;
    vector<bool> reached(n, false);

    while (child[current]!=-1 && !reached[current]){
        reached[current] = true;
        orderOfTraversal.push_back(current);
        current = child[current];
    }

    if (child[current] == -1)
        cout << orderOfTraversal.size()+1 << " step(s) to exit" << endl;

    else if(reached[current]){
        int currentPosInOrder;

        for (currentPosInOrder = 0; orderOfTraversal[currentPosInOrder] != current; ++currentPosInOrder);
        int sizeOfCycle = orderOfTraversal.size() - currentPosInOrder;

        cout << currentPosInOrder << " step(s) before a loop of " << sizeOfCycle << " step(s)" << endl;
    }
}


int main(){
    int row, column, startingColumn, n;
    char direction;

    while(true){
        cin >> row >> column >> startingColumn;

        if(row==0 && column==0 && startingColumn==0)
            break;

        startingColumn--;
        n = row*column;
        vector<int> child(n+10, -1);


        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                cin >> direction;
                if(direction=='N'){
                    if(i==0)
                        child[(i*column)+j] = -1;
                    else
                        child[(i*column)+j] = ((i-1)*column)+j;
                }
                else if(direction=='E'){
                    if(j==column-1)
                        child[(i*column)+j] = -1;
                    else
                        child[(i*column)+j] = (i*column)+j+1;
                }
                else if(direction=='S'){
                    if(i==row-1)
                        child[(i*column)+j] = -1;
                    else
                        child[(i*column)+j] = ((i+1)*column)+j;
                }
                else if(direction=='W'){
                    if(j==0)
                        child[(i*column)+j] = -1;
                    else
                        child[(i*column)+j] = (i*column)+j-1;
                }
            }
        }

        findAns(n, startingColumn, child);
    }
    return 0;
}

