#include <bits/stdc++.h>
using namespace std;

int getSumTill(int index, vector<int>& tree) {
    index++;
    int sum = 0;
    while (index>0) {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}

void update(int index, int addValue, vector<int>& tree, int inputCount) {
    index++;
    while (index <= inputCount) {
        tree[index] += addValue;
        index += index & (-index);
    }
}

int main() {
    int inputCount;
    cin >> inputCount;

    vector<int> input(inputCount); // 0 Based Indexing
    vector<int> tree(inputCount+1); // 1 Based Indexing
    for (int index=0; index<inputCount; index++) {
        cin >> input[index];
        update(index, input[index], tree, inputCount);
    }

    int queryCount, queryType, start, end, index, addValue;
    cin >> queryCount;
    for(int query=1; query<=queryCount; query++) {
        cin >> queryType;
        if(queryType==0) {
            cin >> start >> end;
            cout << getSumTill(end, tree) - getSumTill(start-1, tree) << endl;
        }
        else if(queryType==1) {
            cin >> index >> addValue;
            update(index, addValue, tree, inputCount);
        }
    }

    return 0;
}