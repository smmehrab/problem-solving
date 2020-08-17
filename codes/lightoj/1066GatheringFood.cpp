#include <bits/stdc++.h>
using namespace std;

int n, k;
char grid[22][22];
char alphabets[26] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z'
};

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

int bfs(char sourceCharacter, char destinationCharacter)
{
    queue<Cell> q;
    bool visited[n][n];
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if(grid[row][col]=='.' || grid[row][col]==sourceCharacter || grid[row][col]==destinationCharacter)
                visited[row][col] = false;
            else 
                visited[row][col] = true;

            // cout << visited[row][col] << " ";

            if(grid[row][col]==sourceCharacter){
                q.push(Cell(row, col, 0));
                grid[row][col] = '.';
                visited[row][col] = true;
            }
        }
        // cout << endl;
    }
    
    while (!q.empty())
    {
        Cell p = q.front();
        q.pop();

        if (grid[p.row][p.col] == destinationCharacter){
            // grid[p.row][p.col] = '.';
            return p.dist;
        }
        
        if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false)
        {
            q.push(Cell(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }

        if (p.row + 1 < n &&
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
    int testCaseCount, answer, tempAnswer;
    char temp;
    scanf("%d", &testCaseCount);

    for (int testCase = 1; testCase <= testCaseCount; testCase++)
    {
        scanf("%d", &n);

        for (int row = 0; row < n; row++)
        {
            scanf("%s\n", &grid[row]);
        }

        k=0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] != '.' && grid[row][col] != '#')
                {
                    k++;
                }
            }
        }

        // cout << "Number of Characters : " << k << endl;

        answer = 0;
        for(int index=0; index<k-1; index++){
            char sourceCharacter = alphabets[index];
            char destinationCharacter = alphabets[index+1];
            tempAnswer=bfs(sourceCharacter, destinationCharacter);
            // cout << endl;
            if(tempAnswer==-1){
                answer=-1;
                break;
            }
            else{
                answer+=tempAnswer;
            }
        }

        if(answer==-1){
            printf("Case %d: Impossible\n", testCase, answer);
        }
        else{
            printf("Case %d: %d\n", testCase, answer);
        }
    }

    return 0;
}