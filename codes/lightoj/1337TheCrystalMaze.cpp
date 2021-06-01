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
using namespace std;

char grid[600][600];
bool visited[600][600];
int crystals[600][600];
int m, n, q;

int dfs(pair<int, int> source)
{
    int x = source.first;
    int y = source.second;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int crystal = 0;

    if (grid[x][y] == 'C')
    {
        crystal++;
    }

    visited[x][y] = true;
    for (int d = 0; d < 4; d++)
    {
        int newX = x + dx[d];
        int newY = y + dy[d];
        if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY] && grid[newX][newY]!='#')
        {
            crystal += dfs(make_pair(newX, newY));
        }
    }

    return crystal;
}

// Driver code
int main()
{
    int testCaseCount, x, y;

    scanf("%d", &testCaseCount);
    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d %d %d", &m, &n, &q);
        for (int row = 0; row < m; row++)
        {
            scanf("%s\n", &grid[row]);
        }

        printf("Case %d:\n", testCase);

        memset(crystals, -1, sizeof(crystals));
        for (int pos = 0; pos < q; pos++)
        {
            scanf("%d %d", &x, &y);

            if (crystals[x-1][y-1] == -1)
            {
                memset(visited, false, sizeof(visited));
                crystals[x-1][y-1] = dfs(make_pair(x - 1, y - 1));
                printf("%d\n", crystals[x-1][y-1]);
                for (int row = 0; row < m; row++){
                    for (int col = 0; col < n; col++){
                        if (visited[row][col]){
                            crystals[row][col] = crystals[x-1][y-1];
                        }
                    }
                }
            }
            else{
                printf("%d\n", crystals[x-1][y-1]);
            }
        }
    }

    return 0;
}