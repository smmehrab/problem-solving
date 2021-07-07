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

#define N 100100
int tree[2*N];

void build(vector<int>& input, int n) {
    // Fill Up Leaf Nodes
	for(int i=0; i<n; i++)
		tree[n+i] = input[i];
	// Building Bottom Up
	for (int i=n-1; i>0; i--)	
		tree[i] = tree[i<<1] + tree[i<<1 | 1];
}

void update(int key, int value, int n) {
	// Update Leaf
    tree[n+key] = value;
	key += n;
	// Update Bottom Up
	for (int i=key; i>1; i>>=1)
		tree[i>>1] = tree[i] + tree[i^1];
}

int query(int l, int r, int n) {
	int sum = 0;
	for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if(l&1)
			sum += tree[l++];
		if(r&1)
			sum += tree[--r];
	}
	return sum;
}

int main() {
    int n, q, command, key, value, start, end;
    cin >> n >> q;

    vector<int> input(n);
    for(int &item : input)
        cin >> item;

	build(input, n);

    while(q--) {
        cin >> command;
        // Update
        if(command==1) {
            cin >> key >> value;
            update(key, value, n);
        }
        // Query
        else if(command==2) {
            cin >> start >> end;
            cout << query(start, end, n) << endl;
        }
    }
	
	return 0;
}