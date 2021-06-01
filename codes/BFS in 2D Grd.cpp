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

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

int cell[100][100];
int d[100][100],vis[100][100];

int row,col;

void bfs(int sx,int sy) {
    queue<pii>q;
	memset(vis,0,sizeof vis);

	vis[sx][sy]=1;
	q.push(pii(sx,sy));

	while(!q.empty()){
		pii top=q.front();
		q.pop();

		for(int k=0;k<4;k++){
			int tx=top.first+fx[k];
			int ty=top.second+fy[k];
			if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0) {
				vis[tx][ty]=1;
				d[tx][ty]=d[top.first][top.second]+1;
				q.push(pii(tx,ty));
			}
		}
	}
}

int main(){
    int x, y;
    cin >> x >> y;
    bfs(x, y);
    return 0;
}
