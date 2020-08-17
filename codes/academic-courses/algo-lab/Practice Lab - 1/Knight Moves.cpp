#include <bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;

int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool visited[12][12];

struct node{
	int x, y;
	int distance;
	node() {}
	node(int x, int y, int distance) : x(x), y(y), distance(distance) {}
};

bool isValid(int x, int y){
	if (x < 1 || x >8 || y < 1 || y > 8)
		return false;
	return true;
}

void initialize(){
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 12; j++){
			visited[i][j] = false;
		}
	}
}

int minPath(int s[], int d[]){

    initialize();

	queue<node> q;
	q.push(node(s[0], s[1], 0));

	node t;
	int x, y;

	visited[s[0]][s[1]] = true;

	while (!q.empty()){
		t = q.front();
		q.pop();

		if (t.x == d[0] && t.y == d[1])
			return t.distance;

		for (int i = 0; i < 8; i++){
			x = t.x + dx[i];
			y = t.y + dy[i];

			if (isValid(x, y) && !visited[x][y]) {
				visited[x][y] = true;
				q.push(node(x, y, t.distance + 1));
			}
		}
	}
}

int main(){
    int s[3], d[3];
    string ss, ds;

    while(cin >> ss >> ds){

        s[0] = (int) ss[1] - '0';
        s[1] = (int) ss[0] - 'a';
        s[1]++;

        d[0] = (int) ds[1] - '0';
        d[1] = (int) ds[0] - 'a';
        d[1]++;

        cout << "To get from " << ss << " to " << ds << " takes " << minPath(s, d) << " knight moves." << endl;
    }
	return 0;
}
