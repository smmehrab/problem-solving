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
#include <queue>
#include <vector>
using namespace std;

#define SIZE 200200

int color[SIZE];
vector<int> rivals[SIZE];
vector<int> fighters;
int one, zero;

void bfs(int source){
	queue<int>q;

	color[source] = 0;
    zero++;
    q.push(source);

	while(!q.empty()){
		int current = q.front();
		q.pop();
		for(int rival : rivals[current]){
			if(color[rival]==-1){
                if(color[current]==1){
                    color[rival]=0;
                    zero++;
                } 
                else if(color[current]==0){
                    color[rival]=1;
                    one++;
                }
				q.push(rival);
            }
        }
    }
}


void initialize()
{
    one = 0;
    zero = 0;
    fighters.clear();
    for (int i = 0; i < SIZE; i++)
    {
        color[i] = -1;
        rivals[i].clear();
    }
}

int main()
{
    int testCaseCount, n, u, v, answer;
    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d", &n);
        
        initialize();

        for (int dual = 0; dual < n; dual++)
        {
            scanf("%d %d", &u, &v);
            rivals[u].push_back(v);
            rivals[v].push_back(u);
            fighters.push_back(u);
            fighters.push_back(v);
        }

        answer = 0;
        for (int fighter : fighters)
        {
            if (color[fighter]==-1)
            {
                bfs(fighter);
                answer += max(zero, one);
                zero = 0;
                one = 0;
            }
        }
        
        printf("Case %d: %d\n", testCase, answer);
    }

    return 0;
}
