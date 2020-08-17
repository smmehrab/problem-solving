#include <bits/stdc++.h>
using namespace std;

bool isMagicSquare(vector<int> v){
	int a[3][3], i, j, s = 0, t;

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			a[i][j] = v[3 * i + j];

	for (j = 0; j < 3; ++j)
		s += a[0][j];

	for (i = 1; i <= 2; ++i) {
		t = 0;
		for (j = 0; j < 3; ++j)
			t += a[i][j];
		if (t != s)
			return 0;
	}

	for (j = 0; j < 3; ++j) {
		t = 0;
		for (i = 0; i < 3; ++i)
			t += a[i][j];
		if (t != s)
			return 0;
	}

	for (i = 0, t = 0; i < 3; ++i)
		t += a[i][i];
	if (t != s)
		return 0;

	for (i = 0, t = 0; i < 3; ++i)
		t += a[2 - i][i];
	if (t != s)
		return 0;

	return 1;
}


void generateAllMagicSquares(vector<vector<int> >& allMagicSquares){
	vector<int> v(9);

	for (int i = 0; i < 9; ++i)
		v[i] = i + 1;

	do {
		if (isMagicSquare(v))
			allMagicSquares.push_back(v);
	} while (next_permutation(v.begin(), v.end()));
}

int cost(vector<int> a, vector<int> b){
	int i, res = 0;

	for (i = 0; i < 9; ++i)
		res += abs(a[i] - b[i]);

	return res;
}

int findMinimumCost(vector<int> v){
	int i, mCost = INT_MAX;
	vector<vector<int> > allMagicSquares;

	generateAllMagicSquares(allMagicSquares);

	for (i = 0; i < allMagicSquares.size(); ++i)
		mCost = min(mCost, cost(v, allMagicSquares[i]));
	return mCost;
}

int main(){
    int i, j;
	vector<int> v;

	for(i=0;i<9;i++){
        cin >> j;
        v.push_back(j);
	}

	cout << findMinimumCost(v) << endl;

	return 0;
}
