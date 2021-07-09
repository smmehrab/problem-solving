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

#define N 150000
int input[N];
int tree[4*N];

void update(int key, int valueToAdd){
    while(key<N) {
        tree[key] += valueToAdd;
        key += key & (-key);
    }
}

int query(int key){
    int sum=0;
    while(key>0){
        sum += tree[key];
        key -= key & (-key);
    }
    return sum;
}

int main() {
    int testCaseCount, n, q, key, value;
    int low, high, mid, midSum, sum;
    char type;

    cin >> testCaseCount;
    for(int testCase=1; testCase<=testCaseCount; testCase++) {        
        memset(input, 0, sizeof(input));
        memset(tree, 0, sizeof(tree));

        cout << "Case " << testCase << ":" << endl;
        cin >> n >> q;
        for(key=1; key<=n; key++) {
            cin >> input[key];
            update(key, 1);
        }

        while(q--) {
            cin >> type;
            if(type == 'a') {
                cin >> value;
                input[++n] = value;
                update(n, 1);
            }
            else if(type == 'c') {
                cin >> key;

                // Binary Search BST
                low=1, high=n, sum=-1;
                while(low<=high) {
                    mid = (low + ((high-low)>>2));
                    midSum = query(mid);
                    if(midSum == key)
                        sum = mid;    
                    if(midSum>=key)
                        high = mid-1;
                    else 
                        low = mid+1;
                }

                if(sum==-1) 
                    cout << "none" << endl;
                else {
                    cout << input[sum] << endl;
                    update(sum, -1);
                    input[sum] = -1; 
                }
            }
        }
    }
    return 0;
}