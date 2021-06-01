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
#define pii pair<int,int>

int rookX[] ={1, -1, 0, 0};
int rookY[] ={0, 0, -1, 1};
int rookMoves = 4;

int bishopX[] = {1, 1, -1, -1};
int bishopY[] = {1, -1, 1, -1};
int bishopMoves = 4;

int kingX[] = {1, -1, 0, 0, 1, 1, -1, -1};
int kingY[] = {0, 0, -1, 1, 1, -1, 1, -1};
int kingMoves = 8;

int moveCount[10][10];
bool visited[10][10];

int row=8,col=8, nthMove;

void initialize(){
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            moveCount[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void rookBfs(pii& src, pii& dest) {
    queue<pii>q;
    initialize();

	visited[src.first][src.second]=true;
	q.push(src);

	while(!q.empty()){
		pii c = q.front();
		q.pop();
        nthMove = moveCount[c.first][c.second] + 1;
		for(int i=0; i<rookMoves; i++){
			int cx = c.first + rookX[i];
			int cy = c.second + rookY[i];
            while(cx>0 && cx<=row && cy>0 && cy<=col && !visited[cx][cy]) {
				visited[cx][cy] = true;
                moveCount[cx][cy] = nthMove;
				q.push(make_pair(cx, cy));

                cx += rookX[i];
                cy += rookY[i];
			}
		}
	}

    cout << moveCount[dest.first][dest.second] << " ";
}


void bishopBfs(pii& src, pii& dest) {
    queue<pii>q;
    initialize();

	visited[src.first][src.second]=true;
	q.push(src);

	while(!q.empty()){
		pii c = q.front();
		q.pop();

        nthMove = moveCount[c.first][c.second] + 1;

		for(int i=0; i<bishopMoves; i++){
			int cx = c.first + bishopX[i];
			int cy = c.second + bishopY[i];

			while(cx>0 && cx<=row && cy>0 && cy<=col && !visited[cx][cy]) {
				visited[cx][cy] = true;
                moveCount[cx][cy] = nthMove;
                q.push(make_pair(cx, cy));

                cx += bishopX[i];`
                cy += bishopY[i];
			}
		}
	}

	if(moveCount[dest.first][dest.second] > 2)
        moveCount[dest.first][dest.second] = 2;

    cout << moveCount[dest.first][dest.second] << " ";
}

void kingBfs(pii& src, pii& dest) {
    queue<pii>q;
    initialize();

	visited[src.first][src.second]=true;
	q.push(src);

	while(!q.empty()){
		pii c = q.front();
		q.pop();
        nthMove = moveCount[c.first][c.second] + 1;
		for(int i=0; i<kingMoves; i++){
			int cx = c.first + kingX[i];
			int cy = c.second + kingY[i];

			if(cx>0 && cx<=row && cy>0 && cy<=col && !visited[cx][cy]) {
				visited[cx][cy] = true;
                moveCount[cx][cy] = nthMove;
                q.push(make_pair(cx, cy));
			}
		}
	}

    cout << moveCount[dest.first][dest.second] << endl;
}

int main(){
    pii src, dest;
    cin >> src.first >> src.second >> dest.first >> dest.second;

    rookBfs(src, dest);
    bishopBfs(src, dest);
    kingBfs(src, dest);

    //main();
    return 0;
}

