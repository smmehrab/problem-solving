#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

#define SIZE 1200

bool visited[SIZE];
int reachability[SIZE];
vector<int> roads[SIZE];
vector<int> people;

void dfs(int source){
	visited[source] = true;
    reachability[source]++;
    for(int reachable : roads[source]){
        if(!visited[reachable]){
            dfs(reachable);
        }
    }
}

void initialize()
{
    people.clear();
    for (int i = 0; i < SIZE; i++)
    {
        visited[i] = false;
        reachability[i] = 0;
        roads[i].clear();
    }
}

int main()
{
    int testCaseCount, k, n, m, u, v, p, maxReachable, answer;
    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        initialize();
        scanf("%d %d %d", &k, &n, &m);

        for(int person = 1; person<=k; person++){
            scanf("%d", &p);
            people.push_back(p);
        }

        for (int road = 0; road < m; road++)
        {
            scanf("%d %d", &u, &v);
            roads[u].push_back(v);
        }

        maxReachable = -1;
        answer = 0;

        for (int person : people)
        {
            memset(visited, false, sizeof visited);
            dfs(person);
        }

        for(int index=1; index<=n; index++){
            if(reachability[index]>maxReachable){
                maxReachable=reachability[index];
            }
        }

        for(int index=1; index<=n; index++){
            if(reachability[index]==maxReachable){
                answer++;
            }
        }
        
        printf("Case %d: %d\n", testCase, answer);
    }

    return 0;
}