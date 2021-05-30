#include<bits/stdc++.h>
using namespace std;

int visited[26][26][26];
int level[26][26][26];
vector<vector<int>> directions {
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0},
    {0, 0, -1},
    {0, -1, 0},
    {-1, 0, 0},
};

struct Node {
    int x, y, z;
    
    Node() {}

    Node(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }

    bool operator ==(Node b) {
        return (x == b.x && y == b.y && z == b.z);
    }
};

int nextASCII(int currentASCII, int direction) {
	int ascii = currentASCII + direction;
	ascii = ((ascii<0) ? ascii+26 : ascii) % 26;
	return ascii;
}

bool isForbidden(Node a) {
    return (visited[a.x][a.y][a.z] == -1);
}

int bfs(Node source, Node destination) {
    queue<Node> q;
    Node current, next;

    level[destination.x][destination.y][destination.z] = -1;

	visited[source.x][source.y][source.z] = 1;
    level[source.x][source.y][source.z] = 0;
    q.push(source);
    while(!q.empty()) {
	    current = q.front();
	    q.pop();

	    if(current == destination) 
		    break;
			
        for(vector<int> direction : directions) {
            next.x = nextASCII(current.x, direction[0]);
		    next.y = nextASCII(current.y, direction[1]);
		    next.z = nextASCII(current.z, direction[2]);
		    if(visited[next.x][next.y][next.z] == 0) {
			    visited[next.x][next.y][next.z] = 1;
			    level[next.x][next.y][next.z] = level[current.x][current.y][current.z] + 1;
			    q.push(next);
		    }
        }
    }

    return level[destination.x][destination.y][destination.z];
}

int main() {
    int testCaseCount, n, x, y, z;
    string start, finish, forbidden[3];
    Node source, destination;
	int buttonPresses;

    cin >> testCaseCount;
	for(int testCase=1; testCase<=testCaseCount; testCase++) {        
        cin >> start;
        cin >> finish;
        cin >> n;		

        source = Node(start[0]-'a', start[1]-'a', start[2]-'a');
        destination = Node(finish[0]-'a', finish[1]-'a', finish[2]-'a');

        memset(visited, 0, sizeof(visited));
		for(int i=0; i<n; i++) {
			cin >> forbidden[0] >> forbidden[1] >> forbidden[2];
            for(char c1 : forbidden[0]) {
                x = c1-'a';
                for(char c2 : forbidden[1]) {
                    y = c2-'a';
                    for(char c3 : forbidden[2]) {
                        z = c3-'a';
                        visited[x][y][z] = -1;
                    }
                }
            }
		}

        buttonPresses = (isForbidden(source)) ? -1 : bfs(source, destination);
        cout << "Case " << testCase << ": " << buttonPresses << endl;
	}	
	
	return 0;
}