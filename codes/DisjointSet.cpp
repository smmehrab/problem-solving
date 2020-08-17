#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class DisjointSet{
	map<int, int> parent;
	map<int, int> rank;

    public:
	void makeSet(vector<int> const &universe){
		for (int i = 0; i < universe.size(); i++){
			parent[i+1] = i+1;
			rank[i+1] = 0;
		}
	}

	int Find(int k){
		if (parent[k] != k)
			parent[k] = Find(parent[k]);
		return parent[k];
	}

	void Union(int a, int b){
		int x = Find(a);
		int y = Find(b);

		if (x == y)
			return;

		if (rank[x] > rank[y])
			parent[y] = x;
		else if (rank[x] < rank[y])
			parent[x] = y;
		else{
			parent[x] = y;
			rank[y]++;
		}
	}
};

void printSets(vector<int> const &universe, DisjointSet &ds){
    for (int i = 0; i < universe.size(); i++)
		cout << ds.Find(i+1) << ' ';
	cout << '\n';
}

int main(){
	vector<int> universe;
	for(int i=0;i<5;i++)
        universe.push_back(i+1);

	DisjointSet ds;

	ds.makeSet(universe);
	printSets(universe, ds);

	ds.Union(4, 3); // 4 and 3 are in same set
	printSets(universe, ds);

	ds.Union(2, 1); // 1 and 2 are in same set
	printSets(universe, ds);

	ds.Union(1, 3); // 1, 2, 3, 4 are in same set
	printSets(universe, ds);

	return 0;
}
