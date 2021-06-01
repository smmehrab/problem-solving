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
#include<algorithm>
#include<iostream>
#include<limits.h>
#include<string.h>
#include <utility>
using namespace std;

pair<int, int> point[1100];
pair<int, int> adj[1100];
bool visited[1100];

int calculateDistanceBetween(pair<int, int>& p1, pair<int, int>& p2) {
	return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int reachCount(int i) {
	if (visited[i])
		return 0;

	visited[i] = true;
	return reachCount(adj[i].first)+reachCount(adj[i].second)+1;
}

int main() {
	int n;
	while(cin>>n && n){
		for(int i=0; i<n; i++)
			cin >> point[i].first >> point[i].second;

        memset(visited, false, sizeof(visited));

		for(int i=0; i<n; i++){
			int minimum = INT_MAX, secondMinimum = INT_MAX;
			int minimumIndex = -1, secondMinimumIndex = -1;

			for(int j=0; j<n; j++){
				if(i!=j){
					int distance = calculateDistanceBetween(point[i], point[j]);
					if (distance<=minimum) {
						secondMinimum = minimum;
						secondMinimumIndex = minimumIndex;

						minimum = distance;
						minimumIndex = j;
					}
					else if (distance<secondMinimum) {
						secondMinimum = distance;
						secondMinimumIndex = j;
					}
				}
			}

			adj[i].first = minimumIndex;
			adj[i].second = secondMinimumIndex;
		}

		int reach = reachCount(0);
		if(reach==n)
			cout << "All stations are reachable." << endl;
		else
			cout << "There are stations that are unreachable." << endl;

	}

	return 0;
}
