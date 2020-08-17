#include <bits/stdc++.h>
using namespace std;

#define SIZE 200

int junctionCount, roadCount, answer;
vector<int> roads[SIZE];
bool visited[SIZE];
int level[SIZE];
int combinedLevel[SIZE];

void bfs(int source) 
{ 
	queue<int> q; 
    
    visited[source] = true; 
	level[source] = 0; 
	q.push(source); 
	
    while (!q.empty()) { 
		int current = q.front(); 
		q.pop(); 

		for (int adjacent : roads[current]){ 
			if (!visited[adjacent]) { 
				visited[adjacent] = true; 
				level[adjacent] = level[current] + 1; 
                combinedLevel[adjacent]+=level[adjacent];
				q.push(adjacent); 
			} 
		} 
	} 
} 

void initialize(){
    answer=-1;
    for(int i=0; i<SIZE; i++){
        visited[i] = false;
        level[i]=0;
        combinedLevel[i]=0;
        roads[i].clear();
    }
}

void refresh(){
    for(int i=0; i<SIZE; i++){
        visited[i] = false;
        level[i] = 0;
    }
}

int main()
{
    int testCaseCount, source, destination;
    scanf("%d", &testCaseCount);

    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        initialize();
        scanf("%d", &junctionCount);
        scanf("%d", &roadCount);

        for (int road = 0; road < roadCount; road++)
        {
            scanf("%d %d", &source, &destination);
            roads[source].push_back(destination);
            roads[destination].push_back(source);
        }

        scanf("%d %d", &source, &destination);

        bfs(source);
        refresh();
        bfs(destination);

        for(int junction=0; junction<junctionCount; junction++){
                if(answer < combinedLevel[junction]){
                    answer = combinedLevel[junction];
                } 
        }

        printf("Case %d: %d\n", testCase, answer);
    }

    return 0;
}