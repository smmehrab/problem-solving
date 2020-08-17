#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    return dfsToPerimeter(make_pair(row, col), grid);
                }
            }
        }

        return 0;
    }

private:
    int dfsToPerimeter(pair<int, int> start, vector<vector<int>> &map)
    {
        stack<pair<int, int>> toExplore;
        int perimeter = 0;
        int explored[map.size()][map[0].size()];
        for (int row = 0; row < map.size(); row++)
        {
            for (int col = 0; col < map[0].size(); col++)
            {
                explored[row][col] = false;
            }
        }

        toExplore.push(start);
        while (!toExplore.empty())
        {
            pair<int, int> exploring = toExplore.top();
            toExplore.pop();

            int row = exploring.first;
            int col = exploring.second;

            if (!explored[row][col])
            {
                explored[row][col] = true;
                perimeter += 4;

                if (row != 0 && map[row - 1][col] == 1)
                {
                    toExplore.push(make_pair(row - 1, col));
                    perimeter--;
                }

                if (row != map.size() - 1 && map[row + 1][col] == 1)
                {
                    toExplore.push(make_pair(row + 1, col));
                    perimeter--;
                }

                if (col != 0 && map[row][col - 1] == 1)
                {
                    toExplore.push(make_pair(row, col - 1));
                    perimeter--;
                }

                if (col != map[row].size() - 1 && map[row][col + 1] == 1)
                {
                    toExplore.push(make_pair(row, col + 1));
                    perimeter--;
                }
            }
        }

        return perimeter;
    }
};
