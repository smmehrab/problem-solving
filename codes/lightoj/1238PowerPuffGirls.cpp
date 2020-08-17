#include <bits/stdc++.h>
using namespace std;

char grid[22][22];
int m, n;

class Cell
{
public:
    int row;
    int col;
    int dist;
    Cell(int x, int y, int w)
        : row(x), col(y), dist(w)
    {
    }
};

int bfs(Cell source)
{
    bool visited[m][n];
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 'm' || grid[row][col] == '#')
                visited[row][col] = true;
            else
                visited[row][col] = false;
        }
    }

    queue<Cell> q;

    q.push(source);
    visited[source.row][source.col] = true;
    
    while (!q.empty())
    {
        Cell p = q.front();
        q.pop();

        if (grid[p.row][p.col] == 'h')
            return p.dist;

        if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false)
        {
            q.push(Cell(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }

        if (p.row + 1 < m &&
            visited[p.row + 1][p.col] == false)
        {
            q.push(Cell(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }

        if (p.col - 1 >= 0 &&
            visited[p.row][p.col - 1] == false)
        {
            q.push(Cell(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }

        if (p.col + 1 < n &&
            visited[p.row][p.col + 1] == false)
        {
            q.push(Cell(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }
    }
    return -1;
}

// Driver code
int main()
{
    int testCaseCount, answer;
    char temp;
    scanf("%d", &testCaseCount);

    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d %d", &m, &n);

        for (int row = 0; row < m; row++)
        {
            scanf("%s\n", &grid[row]);
        }

        answer = 0;
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 'a' || grid[row][col] == 'b' || grid[row][col] == 'c')
                {
                    answer = max(answer, bfs(Cell(row, col, 0)));
                }
            }
        }

        printf("Case %d: %d\n", testCase, answer);
    }

    return 0;
}