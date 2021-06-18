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

struct Node{
    long long int value;
    int index;

    bool operator <(Node b) {
        return (value < b.value);
    }
};

int main() {
	int n;
    long long int x;

	cin >> n >> x;
	vector<Node> nodes(n);

    int index = 1;
    for(Node &node : nodes) {
        cin >> node.value;
        node.index = index++;
    }

	sort(nodes.begin(), nodes.end());
	int low = 0, high = n-1, sum;
	while(low < high) {
        sum = nodes[low].value + nodes[high].value;
		if(sum == x) break;
		(sum < x) ? low++ : high--;
	}

    if(sum == x) 
        cout << nodes[low].index << " " << nodes[high].index << endl;
    else
	    cout << "IMPOSSIBLE" << endl;
 
	return 0;
}